#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "bounded_buf.h"

buf_item buf[BUF_SIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t num_full, num_empty;
int in = 0, out = 0, ct = 0;

int main(int argc, char *argv[]) {
  validate_usr_input(argc);
  // input validation?
  time_t sleep_time = atoi(argv[1]);
  int num_pthreads = atoi(argv[2]);
  int num_cthreads = atoi(argv[3]);
  init_mutex(&mutex);
  init_sem(&num_full, 0, 0);
  init_sem(&num_empty, 0, BUF_SIZE);
  pthread_attr_t attr;
  init_attr(&attr);
  pthread_t ptid[num_pthreads];
  thread_create(ptid, &attr, producer, NULL, num_pthreads);
  pthread_t ctid[num_cthreads];
  thread_create(ctid, &attr, consumer, NULL, num_cthreads);
  sleep(sleep_time);
  destroy_attr(&attr);
  destroy_sem(&num_full);
  destroy_sem(&num_empty);
  destroy_mutex(&mutex);
  return EXIT_SUCCESS;
}
