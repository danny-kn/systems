#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "file_02.h"

int shared_ct = 0;

void *thread_func(void *arg) {
  int j = 0;
  while (j < MAX_VAL) {
    shared_ct++;
    j++;
  }
  return NULL;
}

int main(void) {
  pthread_t tid_01, tid_02;
  pthread_create(&tid_01, NULL, thread_func, NULL);
  pthread_create(&tid_02, NULL, thread_func, NULL);
  pthread_join(tid_01, NULL);
  pthread_join(tid_02, NULL);
  printf("shared_ct is %d.\n", shared_ct);
  return EXIT_SUCCESS;
}
