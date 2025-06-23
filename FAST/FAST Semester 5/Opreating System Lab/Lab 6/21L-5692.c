#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int reversedNum = 0;
    int originalNum = num;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return (reversedNum == originalNum);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t childPid = fork();

    if (childPid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (childPid == 0) {
        // Child Process (Read process)
        close(pipefd[1]);  // Close write end

        // Read the filename from the pipe
        char filename[256];
        read(pipefd[0], filename, sizeof(filename));
        close(pipefd[0]);

        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            int numbers[256];
            int count = 0;

            char *token = strtok(line, " ");
            while (token != NULL) {
                numbers[count++] = atoi(token);
                token = strtok(NULL, " ");
            }

            for (int i = 0; i < count; i++) {
                if (isPalindrome(numbers[i])) {
                    printf("%d ", numbers[i]);
                }
            }
            printf("\n");
        }

        fclose(file);
    } else {
        // Parent Process (Write process)
        close(pipefd[0]);  // Close read end

        // Send the filename to the child process
        write(pipefd[1], argv[1], strlen(argv[1]) + 1);
        close(pipefd[1]);

        wait(NULL);  // Wait for the child to finish
    }

    return 0;
}
