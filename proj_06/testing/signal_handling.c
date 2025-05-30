#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "signal_handling.h"

int main(void) {
  setup_signal_handlers();
  while (true) {
    pause();
    if (sigint_flag) {
      sigint_flag = 0;
      printf("SIGINT: ct = %d\n", ct);
    }
    if (sigquit_flag) {
      sigquit_flag = 0;
      printf("SIGQUIT: ct = %d\n", ct);
      break;
    }
  }
  return EXIT_SUCCESS;
}
