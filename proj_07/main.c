/* Author: Danny Kan {kan.74@osu.edu} */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

unsigned char rotate_left(unsigned char x, int pos) {
    int i;
    for(i = 0; i < pos; i++) {
        x = (x << 1) | (x & 0x80) >> 7;
    }
    return x;
}

unsigned char rotate_right(unsigned char x, int pos) {
    int i;
    for(i = 0; i < pos; i++) {
        x = (x >> 1) | (x & 0x01) << 7;
    }
    return x;
}

void clear_buffer(unsigned char buffer[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        putchar(buffer[i]);
    }
}
