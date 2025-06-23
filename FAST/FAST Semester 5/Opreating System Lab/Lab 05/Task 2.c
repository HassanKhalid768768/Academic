#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int send_arr[] = {1, 5, 7, 2, 15};
    int num_of_elements = sizeof(send_arr) / sizeof(send_arr[0]);
    int size = sizeof(int) * num_of_elements;
    int sum = 0;
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
        close(fd[0]); // Close the read end
        write(fd[1], send_arr, size);
        close(fd[1]);

        wait(NULL); // Wait for the child to finish
        read(fd[0], &sum, sizeof(sum));
        close(fd[0]);

        printf("Sum Received from Child: %d\n", sum);
    } else { // Child process
        close(fd[1]); // Close the write end
        int recv_arr[num_of_elements];
        read(fd[0], recv_arr, size);
        close(fd[0]);

        for (int i = 0; i < num_of_elements; ++i) {
            sum += recv_arr[i];
        }
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
