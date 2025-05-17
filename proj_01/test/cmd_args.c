#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("argc = %d\n", argc);
  int j = 0;
  while (j < argc) {
    printf("argv[%d] = %s\n", j, argv[j]);
    j++;
  }
  return EXIT_SUCCESS;
}
