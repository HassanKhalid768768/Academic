#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Process ID before execv: %d\n", getpid());

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This code block is executed by the child process.
        char *args[] = {"my_info", NULL};
        execv("./my_info", args); // Specify the correct path to my_info.c
        perror("Execv failed");
        exit(1);
    } else {
        // This code block is executed by the parent process.
        wait(NULL);
        printf("Back in the parent process\n");
    }

    return 0;
}

