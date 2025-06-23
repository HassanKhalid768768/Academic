#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h> 

#define MAX_N 100


void* fibonacciGenerator(void* arg) {
    int N = *((int*)arg);
    long long* fib = (long long*)malloc((N + 1) * sizeof(long long));

    fib[0] = N;
    fib[1] = 0;
    fib[2] = 1;

    for (int i = 3; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    pthread_exit(fib);
}

void* countEven(void* arg) {
    long long* series = (long long*)arg;
    int N = series[0];
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (series[i] % 2 == 0) {
            count++;
        }
    }
    pthread_exit((void*)(intptr_t)count);
}

void* countOdd(void* arg) {
    long long* series = (long long*)arg;
    int N = series[0];
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (series[i] % 2 != 0) {
            count++;
        }
    }
    pthread_exit((void*)(intptr_t)count);
}

void* calculateSum(void* arg) {
    long long* series = (long long*)arg;
    int N = series[0];
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += series[i];
    }
    FILE* file = fopen("sum.txt", "w");
    if (file) {
        fprintf(file, "%lld\n", sum);
        fclose(file);
    }
    pthread_exit((void*)(intptr_t)sum);
}

int main(int argc, char* argv[]) {

    int N = atoi(argv[1]);

    if (N <= 0 || N > MAX_N) {
        printf("N should be a positive integer less than or equal to %d.\n", MAX_N);
        return 1;
    }

    pthread_t thread1, thread2, thread3, thread4;
    long long* fib = NULL;

    pthread_create(&thread1, NULL, fibonacciGenerator, &N);

    pthread_join(thread1, (void**)&fib);

    printf("ID = %ld, Series: ", pthread_self());
    for (int i = 1; i <= N; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    int evenCount, oddCount;
    pthread_create(&thread2, NULL, countEven, fib);
    pthread_create(&thread3, NULL, countOdd, fib);

    pthread_join(thread2, (void**)&evenCount);
    pthread_join(thread3, (void**)&oddCount);

    printf("ID = %ld, Even Numbers: %d\n", pthread_self(), evenCount);
    printf("ID = %ld, Odd Numbers: %d\n", pthread_self(), oddCount);

    long long sum;
    pthread_create(&thread4, NULL, calculateSum, fib);
    pthread_join(thread4, (void**)&sum);

    printf("ID = %ld, Sum: %lld\n", pthread_self(), sum);

    free(fib);

    return 0;
}
