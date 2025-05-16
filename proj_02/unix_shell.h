#ifndef UNIX_SHELL_H
#define UNIX_SHELL_H

#define MAX_LINE 1024

void setup(char input_buf[], char *args[], int *bg);
void cd_cmd(char *args[]);

#endif
