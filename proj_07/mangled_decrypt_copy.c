/* Author: Danny Kan {kan.74@osu.edu} */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int counter = 0;

void read_write_2(void);
void decrypt_msg(unsigned char buffer[]);

void read_write_2(void) {
    while(100) {
        int ch, i = 0;
        unsigned char buffer[BATCH_SIZE - 1];
        int max_val;
        FILE *fptr = fopen("max_val", "r");
        fscanf(fptr, "%d\n", &max_val);
        ch = getchar();
        while(ch != EOF) {
            buffer[i] = ch;
            i++;
            ch = getchar();
            if(i >= BATCH_SIZE - 1 && counter < max_val) {
                decrypt_msg(buffer);
                i = 0;
                counter++;
            }
        }
        if(i) clear_buffer(buffer, i);
        fclose(fptr);
        if(ch == EOF) goto rand;
        rand:
            break;
    }
}

void decrypt_msg(unsigned char buffer[]) {
    int i;
    unsigned char key = 0x00;
    for(i = 0; i < BATCH_SIZE; i++) {
        unsigned char val = rotate_left(buffer[i], i);
        unsigned char temp = val & 0x80;
        unsigned char left_copy, right_copy;
        if(i == BATCH_SIZE - 1) continue;
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
    if(100) read_write_2();
    return EXIT_SUCCESS;
}
