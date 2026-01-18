#include "kernel/types.h"
#include "user/user.h"

// Merge sort array inplace
// Merge [p, q] and [q + 1, r]
// Require p <= q < r
void merge(int array[] /*input and output*/, int p, int q, int r) {
  //   printf("Start merge %d %d %d\n", p, q, r);

  if (p > q || q >= r) {
    return;
  }

  int len1 = q - p + 1;
  int len2 = r - q;

  int sub_array1[len1];
  int sub_array2[len2];

  for (int k = 0, i = p; i <= q; ++i) {
    sub_array1[k++] = array[i];
  }
  for (int k = 0, i = q + 1; i <= r; ++i) {
    sub_array2[k++] = array[i];
  }

  int i = 0, j = 0, k = p;
  while (i < len1 && j < len2) {
    if (sub_array1[i] <= sub_array2[j]) {
      array[k] = sub_array1[i];
      i++;
    } else {
      array[k] = sub_array2[j];
      j++;
    }
    k++;
  }
  while (i < len1) {
    array[k] = sub_array1[i];
    i++;
    k++;
  }
  while (j < len2) {
    array[k] = sub_array2[j];
    j++;
    k++;
  }
}

// Merge-sort using a divide-and-Conquer method
void mergesort(int array[], int start_index, int end_index) {
  //   printf("start merge sort %d %d\n", start_index, end_index);

  if (end_index <= start_index) {
    return;
  }

  // Divide
  int middle_index = (start_index + end_index) / 2;

  // Conquer
  mergesort(array, start_index, middle_index);
  mergesort(array, middle_index + 1, end_index);

  // Merge array inplace
  merge(array, start_index, middle_index, end_index);
}

void printarray(const int array[], const int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(int argc, char argv[]) {
  printf("sort\n");

  int random_numbers[100] = {
      17,  22, 93, 37, 64, 51, 80, 3,  59, 77, 39, 54, 28, 25, 66, 61, 73,
      67,  84, 48, 70, 63, 41, 18, 72, 53, 6,  40, 94, 65, 38, 92, 31, 43,
      13,  19, 69, 30, 33, 24, 85, 8,  42, 4,  58, 12, 45, 78, 95, 44, 21,
      86,  35, 50, 26, 99, 88, 55, 36, 46, 49, 75, 56, 16, 11, 97, 79, 27,
      100, 52, 89, 90, 2,  34, 47, 83, 15, 57, 62, 7,  98, 5,  87, 81, 32,
      10,  20, 68, 71, 14, 29, 91, 76, 96, 9,  1,  60, 74, 82, 23};

  printarray(random_numbers, sizeof(random_numbers) / sizeof(int));

  mergesort(random_numbers, 0, 100 - 1);

  printarray(random_numbers, sizeof(random_numbers) / sizeof(int));

  return 0;
}
