#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    // Get the shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
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

    // Read data from shared memory and calculate sum and average
    int sum = 0;
    int count = 0;

    char *token = strtok(shared_memory, " ");
    while (token != NULL) {
        int number = atoi(token);
        sum += number;
        count++;
        token = strtok(NULL, " ");
    }

    // Calculate average
    double average = (double)sum / count;

    // Display sum and average
    printf("Sum = %d\n", sum);
    printf("Average = %.2lf\n", average);

    // Detach shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        return 1;
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }

    return 0;
}

