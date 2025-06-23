#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This code block is executed by the child process.
        char *args[] = {"Fibonacci", "10", NULL}; // Replace "10" with the desired value of n.
        execv("./Fibonacci", args); // Specify the correct path to Fibonacci binary
        perror("Execv failed");
        exit(1);
    } else {
        // This code block is executed by the parent process.
        wait(NULL);
        printf("Back in the parent process\n");
    }

    return 0;
}

