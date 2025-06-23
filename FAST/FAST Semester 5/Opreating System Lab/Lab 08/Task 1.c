#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {


  int input_fd = open(argv[1], O_RDONLY);
  int output_fd = open(argv[2], O_WRONLY);

  dup2(input_fd, 0);
  dup2(output_fd, 1);

  char buffer[1024];

  read(0, buffer, sizeof(buffer));
  printf("%s", buffer);

  return 0;
}
