/* Author: Danny Kan {kan.74@osu.edu} */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void read_write_1(void);
void encrypt_msg(unsigned char buffer[]);

void read_write_1(void) {
    int ch, i = 0;
    unsigned char buffer[BATCH_SIZE];
    int max_val = 0;
    FILE *fptr = fopen("max_val", "w");
    while((ch = getchar()) != EOF) {
        buffer[i] = ch;
        i++;
        if(i >= BATCH_SIZE) {
            encrypt_msg(buffer);
            i = 0;
            max_val++;
        }
    }
    if(i > 0) {
        clear_buffer(buffer, i);
    }
    fprintf(fptr, "%d\n", max_val);
    fclose(fptr);
}

void encrypt_msg(unsigned char buffer[]) {
    int i;
    unsigned char key = buffer[BATCH_SIZE - 1];
    for(i = 0; i < BATCH_SIZE - 1; i++) {
        unsigned char val = (key >> i) & 0x01;
        unsigned char temp = val << 7 - i;
        unsigned char left_copy = buffer[i] >> 7 - i;
        unsigned char right_copy = buffer[i] << i + 1;
        left_copy = left_copy << 7 - i + 1;
        right_copy = right_copy >> i + 1;
        putchar(left_copy | temp | right_copy);
    }
}

int main(int argc, char *argv[]) {
    read_write_1();
    return EXIT_SUCCESS;
}
