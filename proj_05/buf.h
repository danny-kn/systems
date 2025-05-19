#ifndef PROJ_05_H
#define PROJ_05_H

typedef int buf_item;

#define BUF_SIZE 5

void validate_usr_input(int argc);
void *producer(void *param);
void *consumer(void *param);
void insert_item(buf_item item);
void remove_item(buf_item *item);
void init_mutex(pthread_mutex_t *mutex);
void destroy_mutex(pthread_mutex_t *mutex);
void init_sem(sem_t *sem, int pshared, int init_val);
void destroy_sem(sem_t *sem);
void init_attr(pthread_attr_t *attr);
void destroy_attr(pthread_attr_t *attr);

#endif
