#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void check_fd(void)
{
    printf("STDIN_FILENO:  %d\n", fileno(stdin));
    printf("STDOUT_FILENO: %d\n", fileno(stdout));
    printf("STDERR_FILENO: %d\n", fileno(stderr));
}

int main(void)
{
  char *file;
  int  fd;
  char *line;

  check_fd();
  file = "example.txt";
  fd = open(file, O_RDONLY);
  if (fd == -1)
  {
    perror("error opening file");
      return (1);
  }
  printf("TXT_FILE_OPEN: %d\n", fd);
  line = get_next_line(fd);
  printf("\nLINE OUTPUT-> \n%s\n", line);
  return (0);
}
