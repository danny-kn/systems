#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "file_03.h"

int shared_ct = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_fun(void *arg) {
  int max_num_iter = *((int *) arg);
  int j = 0;
  while (j < max_num_iter) {
    pthread_mutex_lock(&mutex);
    shared_ct++;
    pthread_mutex_unlock(&mutex);
    j++;
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  validate_usr_input(argc);
  int num_iter = atoi(argv[1]);
  int num_threads = atoi(argv[2]);
  validate_num_threads(num_threads);
  if (pthread_mutex_init(&mutex, NULL) != 0) {
    // fprintf(stderr, "pthread_mutex_init() failed.\n");
    perror("pthread_mutex_init");
    return EXIT_FAILURE;
  }
  pthread_t tid[num_threads];
  thread_create(tid, &num_iter, num_threads);
  thread_join(tid, num_threads);
  printf("shared_ct is %d.\n", shared_ct);
  if (pthread_mutex_destroy(&mutex) != 0) {
    // fprintf(stderr, "pthread_mutex_destroy() failed.\n");
    perror("pthread_mutex_destroy");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
