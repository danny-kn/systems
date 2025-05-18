#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "buf.h"

buf_item buf[BUF_SIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t num_full, num_empty;

int main(int argc, char *argv[]) {
  return EXIT_SUCCESS;
}
