#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor < 0) {
        perror("open");
        return 1;
    }

    // Get the shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach shared memory segment
    char *shared_memory = (char *)shmat(shmid, NULL, 0);
    if (shared_memory == (char *)(-1)) {
        perror("shmat");
        return 1;
    }

    // Read data from the file and write to shared memory
    ssize_t bytesRead = read(fileDescriptor, shared_memory, SHM_SIZE);
    if (bytesRead < 0) {
        perror("read");
        return 1;
    }

    // Detach shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        return 1;
    }

    // Close the file
    close(fileDescriptor);

    return 0;
}

