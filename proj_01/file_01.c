#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    fprintf(stderr, "\"fork()\" sys. call failed.\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { // child process.
    printf("child pid is %d.\n", getpid());
  } else { // parent process.
    wait(NULL);
    exit(EXIT_SUCCESS);
  }
  return EXIT_SUCCESS;
}
