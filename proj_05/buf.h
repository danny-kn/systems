#ifndef PROJ_05_H
#define PROJ_05_H

typedef int buf_item;

#define BUF_SIZE 5

void validate_usr_input(int argc);
void insert_item(buf_item item);
void remove_item(buf_item *item);

#endif
