#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "bounded_buf.h"

void validate_num_args(int argc) {
  if (argc != 4) {
    fprintf(stderr, "usage: ./bounded_buf <sleep_time> <num_pthreads> <num_cthreads>\n");
    exit(EXIT_FAILURE);
  }
}

void validate_usr_input(time_t sleep_time, int num_pthreads, int num_cthreads) {
  if (sleep_time <= 0) {
    fprintf(stderr, "usage: <sleep_time> must be greater than 0\n");
    exit(EXIT_FAILURE);
  }
  if (num_pthreads <= 0) {
    fprintf(stderr, "usage: <num_pthreads> must be greater than 0\n");
    exit(EXIT_FAILURE);
  }
  if (num_cthreads <= 0) {
    fprintf(stderr, "usage: <num_cthreads> must be greater than 0\n");
    exit(EXIT_FAILURE);
  }
}

void thread_create(pthread_t *tid, pthread_attr_t *attr, void *(*fun)(void *), void *arg, int num_threads) {
  int j = 0;
  while (j < num_threads) {
    if (pthread_create(&tid[j], attr, fun, arg) != 0) {
      // fprintf(stderr, "pthread_create() failed.\n");
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
    j++;
  }
}

void *producer(void *param) {
  (void) param;
  buf_item item;
  srand(time(NULL) + pthread_self());
  while (true) {
    sleep(rand() % 3);
    item = rand() % 8000;
    if (insert_item(item) != 0) {
      // fprintf(stderr, "insert_item() failed.\n");
      perror("insert_item");
      pthread_exit(NULL);
    }
  }
  return NULL;
}

void *consumer(void *param) {
  (void) param;
  buf_item item;
  srand(time(NULL) + pthread_self());
  while (true) {
    sleep(rand() % 3);
    if (remove_item(&item) != 0) {
      // fprintf(stderr, "remove_item() failed.\n");
      perror("remove_item");
      pthread_exit(NULL);
    }
  }
  return NULL;
}

int insert_item(buf_item item) {
  lock_sem(&num_empty);
  lock_mutex(&mutex);
  buf[in] = item;
  in = (in + 1) % BUF_SIZE;
  ct++;
  printf("producer: item = %d\n", item);
  unlock_mutex(&mutex);
  unlock_sem(&num_full);
  return 0;
}

int remove_item(buf_item *item) {
  lock_sem(&num_full);
  lock_mutex(&mutex);
  *item = buf[out];
  out = (out + 1) % BUF_SIZE;
  ct--;
  printf("consumer: item = %d\n", *item);
  unlock_mutex(&mutex);
  unlock_sem(&num_empty);
  return 0;
}

void init_mutex(pthread_mutex_t *mutex) {
  if (pthread_mutex_init(mutex, NULL) != 0) {
    // fprintf(stderr, "pthread_mutex_init() failed.\n");
    perror("pthread_mutex_init");
    exit(EXIT_FAILURE);
  }
}

void lock_mutex(pthread_mutex_t *mutex) {
  if (pthread_mutex_lock(mutex) != 0) {
    // fprintf(stderr, "pthread_mutex_lock() failed.\n");
    perror("pthread_mutex_lock");
    exit(EXIT_FAILURE);
  }
}

void unlock_mutex(pthread_mutex_t *mutex) {
  if (pthread_mutex_unlock(mutex) != 0) {
    // fprintf(stderr, "pthread_mutex_unlock() failed.\n");
    perror("pthread_mutex_unlock");
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
  if (sem_init(sem, pshared, init_val) != 0) {
    // fprintf(stderr, "sem_init() failed.\n");
    perror("sem_init");
    exit(EXIT_FAILURE);
  }
}

void lock_sem(sem_t *sem) {
  if (sem_wait(sem) != 0) {
    // fprintf(stderr, "sem_wait() failed.\n");
    perror("sem_wait");
    exit(EXIT_FAILURE);
  }
}

void unlock_sem(sem_t *sem) {
  if (sem_post(sem) != 0) {
    // fprintf(stderr, "sem_post() failed.\n");
    perror("sem_post");
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
