#include <stdio.h>
#include <stdlib.h>
#include "test_03.h"

int *add_pts(int *xp, int *yp) {
  if (xp == NULL || yp == NULL) {
    return NULL;
  }
  static int res[2];
  res[0] = xp[0] + yp[0];
  res[1] = xp[1] + yp[1];
  return res;
}

int main(void) {
  int x[2] = {1, 2};
  int y[2] = {3, 4};
  int *z = add_pts(x, y);
  if (z == NULL) {
    return EXIT_FAILURE;
  }
  printf("x[0] = %d\n", x[0]);
  printf("x[1] = %d\n", x[1]);
  printf("---\n");
  printf("y[0] = %d\n", y[0]);
  printf("y[1] = %d\n", y[1]);
  printf("---\n");
  printf("z[0] = %d\n", z[0]);
  printf("z[1] = %d\n", z[1]);
  return EXIT_SUCCESS;
}
