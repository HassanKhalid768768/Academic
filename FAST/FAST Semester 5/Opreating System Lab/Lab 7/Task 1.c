#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_worker(void *arg) {
    printf("Thread ID: %lu ", pthread_self());
    printf("Process ID: %d\n", getpid());
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    pthread_t threads[n];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, thread_worker, NULL);
    }	
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

