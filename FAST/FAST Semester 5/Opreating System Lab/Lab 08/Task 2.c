#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

  int input_fd = open(argv[1], O_RDONLY);
  int output_fd = open(argv[2], O_RDONLY);

  char buffer[1024];

  read(input_fd, buffer, sizeof(buffer));
  printf("Input File Text : %s\n", buffer);
  read(output_fd, buffer, sizeof(buffer));
  printf("Output File Text : %s\n", buffer);

  return 0;
}

