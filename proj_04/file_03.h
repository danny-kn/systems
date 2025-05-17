#ifndef FILE_03_H
#define FILE_03_H

#define MAX_NUM_THREADS 10

void validate_usr_input(int argc);
void validate_num_threads(int num_threads);
void *thread_fun(void *arg);
void thread_create(pthread_t *tid, int *num_iter, int num_threads);
void thread_join(pthread_t *tid, int num_threads);

#endif
