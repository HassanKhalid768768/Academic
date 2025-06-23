#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int summation(int N) {
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += i;
  }
  return sum;
}

void *thread_summation(void *arg) {
  int N = *((int *)arg);
  int result = summation(N);
  printf("Summation of integers from 1 to %d is %d\n", N, result);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

  int N = atoi(argv[1]);

  pthread_t thread;

  pthread_create(&thread, NULL, thread_summation, &N);

  pthread_join(thread, NULL);

  return 0;
}
