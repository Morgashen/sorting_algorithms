#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int max_element(int *array, size_t size) {
  int max = array[0];
  for (size_t i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}


void counting_sort(int *array, size_t size, int place) {
  
  int *output = malloc(size * sizeof(int));
  
  int count[10] = {0};
  
  for (size_t i = 0; i < size; i++) {
    int digit = (array[i] / place) % 10;
    count[digit]++;
  }
  
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  
  for (size_t i = size; i > 0; i--) {
    int digit = (array[i - 1] / place) % 10;
    output[count[digit] - 1] = array[i - 1];
    count[digit]--;
  }
  
  for (size_t i = 0; i < size; i++) {
    array[i] = output[i];
  }
  
  free(output);
}


void radix_sort(int *array, size_t size) {
  
  int max = max_element(array, size);
  
  for (int place = 1; max / place > 0; place *= 10) {
    
    counting_sort(array, size, place);
    
    printf("After sorting %d place: ", place);
    for (size_t i = 0; i < size; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
  }
}


void print_array(int *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}


int main() {
  
  int array[] = {329, 457, 657, 839, 436, 720, 355};
  
  size_t size = sizeof(array) / sizeof(array[0]);
  
  printf("Original array: ");
  print_array(array, size);
  
  radix_sort(array, size);
  
  printf("Sorted array: ");
  print_array(array, size);
  return 0;
}
