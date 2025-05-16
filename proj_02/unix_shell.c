#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "unix_shell.h"

int main(void) {
  char input_buf[MAX_LINE];
  char *args[MAX_LINE / 2 + 1];
  int bg;
  pid_t pid;
  while (true) {
    bg = 0;
    printf("CMD -> ");
    fflush(stdout);
    setup(input_buf, args, &bg);
    if (args[0] == NULL) {
      continue;
    } else if (strcmp(args[0], "exit") == 0) {
      exit(EXIT_SUCCESS);
    } else if (strcmp(args[0], "cd") == 0) {
      cd_cmd(args);
      continue;
    }
    if ((pid = fork()) < 0) {
      // fprintf(stderr, "\"fork()\" sys. call failed.\n");
      perror("fork err");
      exit(EXIT_FAILURE);
    } else if (pid == 0) { // child process.
      if (execvp(args[0], args) < 0) {
        // fprintf(stderr, "\"execvp()\" sys. call failed.\n");
        perror("execvp err");
        exit(EXIT_FAILURE);
      }
    } else { // parent process.
      if (bg == 0) {
        waitpid(pid, NULL, 0);
      }
    }
  }
  return EXIT_SUCCESS;
}
