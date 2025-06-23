#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

typedef struct {
    char *map;
    size_t halfSize;
} ThreadData;

void *replaceIntegersInHalf(void *data) {
    ThreadData *threadData = (ThreadData *)data;

    for (size_t i = 0; i < threadData->halfSize; ++i) {
        if (isdigit(threadData->map[i])) {
            threadData->map[i] = ' ';
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *fileName = argv[1];

    int fd = open(fileName, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Obtain file size
    off_t fileSize = lseek(fd, 0, SEEK_END);
    if (fileSize == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    // Map the file into memory
    char *map = mmap(NULL, fileSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // Close the file after mapping
    close(fd);

    // Split the file into two halves
    size_t halfSize = fileSize / 2;

    // Create threads to replace integers in each half
    pthread_t firstHalfThread, secondHalfThread;
    ThreadData firstHalfData = {map, halfSize};
    ThreadData secondHalfData = {map + halfSize, halfSize};

    if (pthread_create(&firstHalfThread, NULL, replaceIntegersInHalf, &firstHalfData) != 0) {
        perror("pthread_create");
        return 1;
    }

    if (pthread_create(&secondHalfThread, NULL, replaceIntegersInHalf, &secondHalfData) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Join threads
    if (pthread_join(firstHalfThread, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    if (pthread_join(secondHalfThread, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    // Unmap the file
    if (munmap(map, fileSize) == -1) {
        perror("munmap");
        return 1;
    }

    return 0;
}

