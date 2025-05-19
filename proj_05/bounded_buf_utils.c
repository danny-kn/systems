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

void *producer(void *param) {
  // TODO: need to implement.
}

void *consumer(void *param) {
  // TODO: need to implement.
}

void insert_item(buf_item item) {
  // TODO: need to implement.
}

void remove_item(buf_item *item) {
  // TODO: need to implement.
}

void init_mutex(pthread_mutex_t *mutex) {
  if (pthread_mutex_init(mutex, NULL) != 0) {
    // fprintf(stderr, "pthread_mutex_init() failed.\n");
    perror("pthread_mutex_init");
    exit(EXIT_FAILURE);
  }
}

void destroy_mutex(pthread_mutex_t *mutex) {
  if (pthread_mutex_destroy(mutex) != 0) {
    // fprintf(stderr, "pthread_mutex_destroy() failed.\n");
    perror("pthread_mutex_destroy");
    exit(EXIT_FAILURE);
  }
}

void init_sem(sem_t *sem, int pshared, unsigned int init_val) {
  if (sem_init(sem, pshared, value) != 0) {
    // fprintf(stderr, "sem_init() failed.\n");
    perror("sem_init");
    exit(EXIT_FAILURE);
  }
}

void destroy_sem(sem_t *sem) {
  if (sem_destroy(sem) != 0) {
    // fprintf(stderr, "sem_destroy() failed.\n");
    perror("sem_destroy");
    exit(EXIT_FAILURE);
  }
}

void init_attr(pthread_attr_t *attr) {
  if (pthread_attr_init(attr) != 0) {
    // fprintf(stderr, "pthread_attr_init() failed.\n");
    perror("pthread_attr_init");
    exit(EXIT_FAILURE);
  }
}

void destroy_attr(pthread_attr_t *attr) {
  if (pthread_attr_destroy(attr) != 0) {
    // fprintf(stderr, "pthread_attr_destroy() failed.\n");
    perror("pthread_attr_destroy");
    exit(EXIT_FAILURE);
  }
}
