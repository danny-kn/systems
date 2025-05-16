#include <stdio.h>
#include <stdlib.h>
#include "test_02.h"

int *sum_vals(int *xp, int *yp) {
  if (xp == NULL || yp == NULL) {
    return NULL;
  }
  int *res = (int *) malloc(sizeof(int));
  if (res == NULL) {
    return NULL;
  }
  *res = *xp + *yp;
  return res;
}

int main(void) {
  int x = 3, y = 5;
  int *sum = sum_vals(&x, &y);
  if (sum == NULL) {
    return EXIT_FAILURE;
  }
  printf("the sum is %d.\n", *sum);
  free(sum);
  return EXIT_SUCCESS;
}
