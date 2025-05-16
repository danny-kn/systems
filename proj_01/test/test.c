#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    // fprintf(stderr, "\"fork()\" sys. call failed.\n");
    perror("fork err");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { // child process.
    printf("child process: hello, world!\n");
  } else { // parent process.
    printf("parent process: hello, world!\n");
  }
  return EXIT_SUCCESS;
}
