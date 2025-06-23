#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        perror("Source file open failed");
        exit(EXIT_FAILURE);
    }

    int fd[2];
    pid_t child_id;

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    child_id = fork();

    if (child_id == -1) {
        perror("Fork failed");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    if (child_id > 0) { // Parent process
        close(fd[0]); // Close the read end
        fseek(source_file, 0, SEEK_END);
        int size = ftell(source_file);
        rewind(source_file);
        char *content = (char *)malloc(size + 1);
        fread(content, 1, size, source_file);
        content[size] = '\0';

        printf("[PARENT: %d] - Size of Content to Send: %d\n", getpid(), size);
        write(fd[1], &size, sizeof(size));
        write(fd[1], content, size);
        close(fd[1]);
        free(content);
        fclose(source_file);
    } else { // Child process
        close(fd[1]); // Close the write end
        int size;
        read(fd[0], &size, sizeof(size));
        char *content = (char *)malloc(size);
        read(fd[0], content, size);
        close(fd[0]);

        FILE *dest_file = fopen(argv[2], "w");
        if (dest_file == NULL) {
            perror("Destination file open failed");
            free(content);
            exit(EXIT_FAILURE);
        }

        printf("[CHILD: %d] - Size of Content to Receive: %d\n", getpid(), size);
        printf("[CHILD: %d] - Content Received: %s\n", getpid(), content);

        fwrite(content, 1, size, dest_file);
        fclose(dest_file);
        free(content);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
