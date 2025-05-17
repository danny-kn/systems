#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "file_03.h"

void validate_usr_input(int argc) {
  if (argc != 3) {
    fprintf(stderr, "usage: ./file_03 <num_iter> <num_threads>\n");
    exit(EXIT_FAILURE);
  }
}

void validate_num_threads(int num_threads) {
  if (num_threads < 1) {
    fprintf(stderr, "the minimum number of threads is 1.\n");
    exit(EXIT_FAILURE);
  } else if (num_threads > MAX_NUM_THREADS) {
    fprintf(stderr, "the maximum number of threads is %d.\n", MAX_NUM_THREADS);
    exit(EXIT_FAILURE);
  }
}

void thread_create(pthread_t *tid, int *num_iter, int num_threads) {
  int j = 0;
  while (j < num_threads) {
    pthread_create(&tid[j], NULL, thread_fun, num_iter);
    j++;
  }
}

void thread_join(pthread_t *tid, int num_threads) {
  int j = 0;
  while (j < num_threads) {
    pthread_join(tid[j], NULL);
    j++;
  }
}
