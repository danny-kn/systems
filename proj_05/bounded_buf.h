#ifndef BOUNDED_BUF_H
#define BOUNDED_BUF_H

typedef int buf_item;

#define BUF_SIZE 5

extern buf_item buf[BUF_SIZE];
extern pthread_mutex_t mutex;
extern sem_t num_full, num_empty;
extern int in, out, ct;

void validate_usr_input(int argc);

void thread_create(pthread_t *tid, pthread_attr_t *attr, void *(*fun)(void *), void *arg, int num_threads);

void *producer(void *param);
void *consumer(void *param);

int insert_item(buf_item item);
int remove_item(buf_item *item);

void init_mutex(pthread_mutex_t *mutex);
void lock_mutex(pthread_mutex_t *mutex);
void unlock_mutex(pthread_mutex_t *mutex);
void destroy_mutex(pthread_mutex_t *mutex);

void init_sem(sem_t *sem, int pshared, unsigned int init_val);
void lock_sem(sem_t *sem);
void unlock_sem(sem_t *sem);
void destroy_sem(sem_t *sem);

void init_attr(pthread_attr_t *attr);
void destroy_attr(pthread_attr_t *attr);

#endif
