#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubbleSort(int arr[], int n, int ascending) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
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

    pid_t child1_pid = fork();

    if (child1_pid == 0) {
        // This is child process 1
        printf("I am Child 1 (with ID = %d and Parent's ID = %d): ", getpid(), getppid());
        bubbleSort(arr, 10, 1);
        for (int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        exit(0);
    } else if (child1_pid > 0) {
        // This is the parent process
        pid_t child2_pid = fork();
        
        if (child2_pid == 0) {
            // This is child process 2
            printf("I am Child 2 (with ID = %d and Parent's ID = %d): ", getpid(), getppid());
            bubbleSort(arr, 10, 0);
            for (int i = 0; i < 10; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            exit(0);
        } else if (child2_pid > 0) {
            // This is still the parent process
            wait(NULL);
            wait(NULL);
            printf("Parent Process terminating and my ID = %d and parent's ID = %d\n", getpid(), getppid());
        } else {
            printf("Fork failed for Child 2.\n");
            return 1;
        }
    } else {
        printf("Fork failed for Child 1.\n");
        return 1;
    }

    return 0;
}

