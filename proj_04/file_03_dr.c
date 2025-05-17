#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "file_03.h"

int shared_ct = 0;

void *thread_fun(void *arg) {
  int max_num_iter = *((int *) arg);
  int j = 0;
  while (j < max_num_iter) {
    shared_ct++;
    j++;
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  validate_usr_input(argc);
  int num_iter = atoi(argv[1]);
  int num_threads = atoi(argv[2]);
  validate_num_threads(num_threads);
  pthread_t tid[num_threads];
  thread_create(tid, &num_iter, num_threads);
  thread_join(tid, num_threads);
  printf("shared_ct is %d.\n", shared_ct);
  return EXIT_SUCCESS;
}
