#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>

#define SHM_SIZE 20

int main() {
    // Create or get the shared memory segment
    key_t key = ftok("shared_memory_key", 1);
    int shmid = shmget(key, SHM_SIZE, 0666);
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

    // Open semaphores for synchronization
    sem_t* producer_sem = sem_open("producer_sem", 0);
    sem_t* consumer_sem = sem_open("consumer_sem", 0);

    while (1) {
        // Consumer waits for the producer
        sem_wait(consumer_sem);

        // Read from shared memory and print
        char buffer[SHM_SIZE];
        memcpy(buffer, shmem, SHM_SIZE);
        if (buffer[0] == '$') {
            break;
        }

        printf("%s\n", buffer);

        // Signal the producer
        sem_post(producer_sem);
    }

    // Cleanup and exit
    shmdt(shmem);

    return 0;
}

