#include <stdio.h>
#include <stdlib.h>
#include "bit_encode.h"

unsigned char rotate_left(unsigned char x) {
  unsigned char y = 0xc0; // | 1100 | 0000 |
  return ((x << 2) | (x & y) >> 6);
}

unsigned char rotate_right(unsigned char x) {
  unsigned char y = 0x03; // | 0000 | 0011 |
  return ((x >> 2) | (x & y) << 6);
}
