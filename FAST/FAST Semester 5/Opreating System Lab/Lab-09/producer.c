#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <semaphore.h>

#define SHM_SIZE 20

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    // Create or get the shared memory segment
    key_t key = ftok("shared_memory_key", 1);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment
    char* shmem = shmat(shmid, NULL, 0);
    if (shmem == (void*)-1) {
        perror("shmat");
        return 1;
    }

    // Create semaphores for synchronization
    sem_t* producer_sem = sem_open("producer_sem", O_CREAT, 0666, 1);
    sem_t* consumer_sem = sem_open("consumer_sem", O_CREAT, 0666, 0);

    // Open the source file for reading
    FILE* source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        perror("fopen");
        return 1;
    }

    while (1) {
        // Read 20 characters from the file
        char buffer[SHM_SIZE];
        if (fread(buffer, sizeof(char), SHM_SIZE, source_file) != SHM_SIZE) {
            // End of file reached
            buffer[0] = '$';
        }

        // Producer waits for consumer to read
        sem_wait(producer_sem);

        // Write to shared memory
        memcpy(shmem, buffer, SHM_SIZE);

        // Signal the consumer
        sem_post(consumer_sem);

        if (buffer[0] == '$') {
            break;
        }
    }

    // Cleanup and exit
    fclose(source_file);
    shmdt(shmem);
    shmctl(shmid, IPC_RMID, NULL);
    sem_close(producer_sem);
    sem_close(consumer_sem);
    sem_unlink("producer_sem");
    sem_unlink("consumer_sem");

    return 0;
}

