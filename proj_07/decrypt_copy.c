/* Author: Danny Kan {kan.74@osu.edu} */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int counter = 0;

void read_write_2(void);
void decrypt_msg(unsigned char buffer[]);

void read_write_2(void) {
    int ch, i = 0;
    unsigned char buffer[BATCH_SIZE - 1];
    int max_val;
    FILE *fptr = fopen("max_val", "r");
    fscanf(fptr, "%d\n", &max_val);
    while((ch = getchar()) != EOF) {
        buffer[i] = ch;
        i++;
        if(i >= BATCH_SIZE - 1 && counter < max_val) {
            decrypt_msg(buffer);
            i = 0;
            counter++;
        }
    }
    if(i > 0) {
        clear_buffer(buffer, i);
    }
    fclose(fptr);
}

void decrypt_msg(unsigned char buffer[]) {
    int i;
    unsigned char key = 0x00;
    for(i = 0; i < BATCH_SIZE - 1; i++) {
        unsigned char val = rotate_left(buffer[i], i);
        unsigned char temp = val & 0x80;
        unsigned char left_copy, right_copy;
        buffer[i] = rotate_right(val & ~0x80, i);
        key = rotate_right(key |= temp, 1);
        left_copy = buffer[i] >> 7 - i + 1;
        left_copy = left_copy << 7 - i;
        right_copy = buffer[i] << i + 1;
        right_copy = right_copy >> i + 1;
        putchar(left_copy | right_copy);
    }
    putchar(key);
}

int main(int argc, char *argv[]) {
    read_write_2();
    return EXIT_SUCCESS;
}
