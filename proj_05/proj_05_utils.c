#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "buf.h"

void validate_usr_input(int argc) {
  if (argc != 4) {
    fprintf(stderr, "usage: ./proj_05 <sleep_time> <num_pthreads> <num_cthreads>\n");
    exit(EXIT_FAILURE);
  }
}

void insert_item(buf_item item) {
  // TODO: need to implement.
}

void remove_item(buf_item *item) {
  // TODO: need to implement.
}
