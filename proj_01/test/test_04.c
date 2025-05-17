#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("arr_size = ");
  int arr_size = 0;
  scanf("%d", &arr_size);
  int *arr = malloc(arr_size * sizeof(int));
  if (arr == NULL) {
    // fprintf(stderr, "\"malloc()\" failed.\n");
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  printf("---\n");
  int j = 0;
  while (j < arr_size) {
    printf("arr[%d] = ", j);
    scanf("%d", &arr[j]);
    j++;
  }
  printf("---\n");
  j = 0;
  while (j < arr_size) {
    printf("arr[%d] = %d\n", j, arr[j]);
    j++;
  }
  free(arr);
  return EXIT_SUCCESS;
}
