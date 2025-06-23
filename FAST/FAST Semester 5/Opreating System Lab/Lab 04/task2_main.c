#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Task 1: Create a directory using execlp
    child_pid = fork();
    if (child_pid == 0) {
        execlp("mkdir", "mkdir", "demo_folder", NULL);
        perror("execlp mkdir failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // Task 2: Create files using execvp
    child_pid = fork();
    if (child_pid == 0) {
        char *args[] = {"touch", "demo_folder/file1.txt", "demo_folder/file2.txt", NULL};
        execvp("touch", args);
        perror("execvp touch failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // Task 3: List files using execvp
    child_pid = fork();
    if (child_pid == 0) {
        execlp("ls", "ls", "demo_folder", NULL);
        perror("execlp ls failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // Task 4: Remove directory using execvp
    child_pid = fork();
    if (child_pid == 0) {
        char *args[] = {"rm", "-rf", "demo_folder", NULL};
        execvp("rm", args);
        perror("execvp rm failed");
        exit(1);
    } else {
        wait(NULL);
    }

    return 0;
}

