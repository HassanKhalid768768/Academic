#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num_children>\n", argv[0]);
        return 1;
    }

    int num_children = atoi(argv[1]);

    for (int i = 0; i < num_children; i++) {
        pid_t child_pid = fork();

        if (child_pid == 0) {
            // This is a child process
            printf("Child process %d: My ID = %d, Parent's ID = %d\n", i + 1, getpid(), getppid());
            exit(0);
        } else if (child_pid < 0) {
            printf("Fork failed for child %d.\n", i + 1);
        }
    }

    // The parent process waits for all child processes to complete
    for (int i = 0; i < num_children; i++) {
        wait(NULL);
    }

    return 0;
}

