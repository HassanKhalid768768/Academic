#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char send_buffer[] = "Hi There";
    int fd[2];
    pid_t child_id;

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    child_id = fork();

    if (child_id == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_id > 0) { // Parent process
        printf("Parent Process [ID: %d]\n", getpid());
        close(fd[0]); // Close the read end

        printf("Original String: %s\n", send_buffer);
        write(fd[1], send_buffer, strlen(send_buffer) + 1);
        close(fd[1]);
    } else { // Child process
        close(fd[1]); // Close the write end
        char recv_buffer[100];
        read(fd[0], recv_buffer, sizeof(recv_buffer));
        close(fd[0]);

        for (int i = 0; recv_buffer[i] != '\0'; ++i) {
            if (recv_buffer[i] >= 'a' && recv_buffer[i] <= 'z') {
                recv_buffer[i] = recv_buffer[i] - 32;
            } else if (recv_buffer[i] >= 'A' && recv_buffer[i] <= 'Z') {
                recv_buffer[i] = recv_buffer[i] + 32;
            }
        }
        printf("Child Process [ID: %d]\nModified String: %s\n", getpid(), recv_buffer);
    }

    return 0;
}
