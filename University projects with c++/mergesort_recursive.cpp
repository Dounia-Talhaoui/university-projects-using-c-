#include <cstdio>

// merge 2 sortierte Arrays a[0,la-1] und b[0,lb-1]
// und schreibe das Ergebnis in c[0,la+lb-1]
void merge(int const a[], int const b[], int c[], int la, int lb) {
  int left = 0;   // Index in a[0,la-1]
  int right = 0;  // Index in b[0,lb-1]

  int idx;  // Index in c[0,la+lb-1]

  for (idx = 0; left < la && right < lb; ++idx) {
    if (a[left] < b[right]) {
      c[idx] = a[left];  // Minimum ist in a
      ++left;            // gehe 1 Position weiter in a
    } else {
      c[idx] = b[right];  // Minimum ist in b
      ++right;            // gehe 1 Position weiter in b
    }
  }

  if (left < la) {  // es gibt noch Werte in a
    while (idx < la + lb) {
      c[idx] = a[left];
      ++idx;
      ++left;
    }
  } else {
    while (idx < la + lb) c[idx++] = b[right++];  // Kurzschreibweise
  }
}

void mergesort(int values[], int first_index, int last_index) {
  if (first_index < last_index) {
    int middle = (first_index + last_index) / 2;

    mergesort(values, first_index, middle);
    mergesort(values, middle + 1, last_index);

    int *tempArray = new int[last_index - first_index + 1];
    merge(values + first_index, values + middle + 1, tempArray, middle - first_index + 1, last_index - middle);

    for (int i = 0; i < last_index - first_index + 1; ++i) {
      values[first_index + i] = tempArray[i];
    }

    delete[] tempArray;
  }
}

void print_all(int const values[], int length) {
  for (int i = 0; i < length; ++i) printf("%i, ", values[i]);
  printf("\n");
}

int main() {
  printf("======== Test 1 ========\n");
  int values1[] = {9,  30, 18, 27, 14, 26, 3, 5,  13, 28, 16,
                   25, 22, 1,  12, 8,  17, 2, 23, 15, 24, 31,
                   6,  20, 19, 21, 32, 4,  7, 10, 29, 11};
  print_all(values1, 32);
  mergesort(values1, 0, 31);
  print_all(values1, 32);

  printf("======== Test 2 ========\n");
  int values2[] = {9,  30, 18, 27, 14, 26, 3, 5,  13, 28, 16, 25, 22, 1,  12, 8,
                   17, 2,  23, 15, 24, 31, 6, 20, 19, 21, 4,  7,  10, 29, 11};
  print_all(values2, 31);
  mergesort(values2, 0, 30);
  print_all(values2, 31);

  return 0;
}