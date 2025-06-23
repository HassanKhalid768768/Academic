#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 11) {
        printf("Usage: %s <num1> <num2> ... <num10>\n", argv[0]);
        return 1;
    }

    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    pid_t child_pid = fork();

    if (child_pid == 0) {
        // This is the child process
        printf("Child process ID: %d\n", getpid());
        bubbleSort(arr, 10);
        printf("Sorted array in child process: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        exit(0);
    } else if (child_pid > 0) {
        // This is the parent process
        wait(NULL);
        printf("Parent process ID: %d\n", getpid());
    } else {
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}

