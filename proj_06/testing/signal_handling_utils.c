#include <stdio.h>
#include <stdlib.h>
#include "signal_handling.h"

volatile sig_atomic_t sigint_flag = 0;
volatile sig_atomic_t sigquit_flag = 0;
volatile sig_atomic_t ct = 0;

static void config_sigaction(int signum, void (*handler)(int)) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(signum, &sa, NULL) != 0) {
      // fprintf(stderr, "sigaction() failed.\n");
      perror("sigaction");
      exit(EXIT_FAILURE);
    }
}

static void sigint_handler(int sig) {
  (void) sig;
  sigint_flag = 1;
  ct++;
}

static void sigquit_handler(int sig) {
  (void) sig;
  sigquit_flag = 1;
}

void setup_signal_handlers(void) {
  config_sigaction(SIGINT, sigint_handler);
  config_sigaction(SIGQUIT, sigquit_handler);
}
