#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

void swap(int *array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void compare_and_swap(int *array, int i, int j, int dir) {
 
  if (dir == (array[i] > array[j])) {
    swap(array, i, j);
    printf("Result of swap %d, %d: ", array[i], array[j]);
    for (int k = 0; k < 8; k++) {
      printf("%d ", array[k]);
    }
    printf("\n");
  }
}

void bitonic_merge(int *array, int low, int count, int dir) {
  if (count > 1) {
    int k = count / 2;
    for (int i = low; i < low + k; i++) {
      compare_and_swap(array, i, i + k, dir);
    }
    bitonic_merge(array, low, k, dir);
    bitonic_merge(array, low + k, k, dir);
  }
}

void bitonic_sort(int *array, int low, int count, int dir) {
 
  if (count > 1) {
    int k = count / 2;
    bitonic_sort(array, low, k, 1);
    bitonic_sort(array, low + k, k, 0);
    bitonic_merge(array, low, count, dir);
  }
}

void print_array(int *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}


int main() {
  
  int array[] = {3, 7, 4, 8, 6, 2, 1, 5};
  size_t size = sizeof(array) / sizeof(array[0]);
  if ((size & (size - 1)) != 0) {
    printf("Error: size must be a power of 2\n");
    return 1;
  }
  
  printf("Original array: ");
  print_array(array, size);
  bitonic_sort(array, 0, size, 1);
  printf("Sorted array: ");
  print_array(array, size);
  return 0;
}
