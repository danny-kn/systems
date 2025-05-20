#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "main.h"

int ct = 0;

void sigint_handler(int sig) {
  // TODO: need to implement.
}

void sigquit_handler(int sig) {
  // TODO: need to implement.
}

int main(void) {
  signal(SIGINT, sigint_handler);
  signal(SIGQUIT, sigquit_handler);
  while (true) { }
  return EXIT_SUCCESS;
}
