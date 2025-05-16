#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "unix_shell.h"

void setup(char input_buf[], char *args[], int *bg) {
  int len;
  if ((len = read(STDIN_FILENO, input_buf, MAX_LINE)) < 0) {
    // fprintf(stderr, "\"read()\" sys. call failed.\n");
    perror("read err");
    exit(EXIT_FAILURE);
  } else if (len == 0) {
    exit(EXIT_SUCCESS);
  }
  int start = -1, ct = 0;
  int j = 0;
  while (j < len) {
    if (input_buf[j] == ' ' || input_buf[j] == '\t') {
      if (start != -1) {
        args[ct++] = &input_buf[start];
      }
      input_buf[j] = '\0';
      start = -1;
    } else if (input_buf[j] == '\n') {
      if (start != -1) {
        args[ct++] = &input_buf[start];
      }
      input_buf[j] = '\0';
      args[ct] = NULL;
    } else if (input_buf[j] == '&') {
      input_buf[j] = '\0';
      *bg = 1;
    } else {
      if (start == -1) {
        start = j;
      }
    }
    j++;
  }
  args[ct] = NULL;
}

void cd_cmd(char *args[]) {
  if (args[1] == NULL) {
    perror("err");
  } else {
    if (chdir(args[1]) < 0) {
      // fprintf(stderr, "\"chdir()\" sys. call failed.\n");
      perror("chdir err");
    }
  }
}
