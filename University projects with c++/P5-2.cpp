#include <cstdio>

void print_all(int array[], int size) {
  printf("[%i", array[0]);
  for (int i = 1; i < size; ++i) {
    printf(", %i", array[i]);
  }
  printf("]\n");
}

// =============================================================================

// Hier dürfen Sie Hilfsfunktionen (z.B. zum Sortieren) implementieren
void insert(int array[], int i){
  int value = array[i]; 
  int index = i - 1; 

  while (index >= 0 && array[index] > value) {
    array[index + 1] = array[index];
    index--;
    }

    array[index + 1] = value;
}

// =============================================================================

int count_distinct(int array[], int size) {
  // ===========================================================================

  for(int i = 1; i < size; i++){
    insert(array, i);
  }
  int count = 0;
  for(int i = 1; i < size; i++){
    if(array[i-1] != array[i]){
      count++;
    }
  }
  return count+1;

  // ===========================================================================
}

int main() {
  char filename[1000];
  printf("Enter a filename that contains the given array:\n");
  scanf("%s", filename);

  FILE* file = fopen(filename, "r");
  rewind(file);
  int size;
  fscanf(file, "%i", &size);
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    fscanf(file, "%i", &arr[i]);
  }
  fclose(file);

  printf("The size of the array is %i.\n", size);
  printf("The array contains the following values:\n");
  print_all(arr, size);

  printf("The array contains %i distinct values.\n", count_distinct(arr, size));

  delete[] arr;

  return 0;
}
