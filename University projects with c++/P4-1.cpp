#include <cstdio>

/*
// Gibt den größten Wert des Arrays zurück,
// der kleiner oder gleich cap ist.
// Wenn kein geeigneter Wert vorhanden ist,
// gibt die Funktion cap+1 zurück.
int capped_max(int array[], int size, int cap) {
  int maximum = array[0];
  int count = 0;
  for (int i = 0; i < size; i++){
    if (array[i] > cap){ //wenn alle werte im Array größer sind als int cap
      count++;
    }
  }
  if (count == size){ // dann gib einfach cap + 1 heraus
    return cap + 1;
  }
  else{
    for (int i = 0; i < size; i++){ //falls der wert cap an irgendeiner Stelle im Array vorkommt, dann gib cap heraus
      if (array[i] == cap){
        return cap;
      }
    }
  }
  for (int i = 1; i < size; i++){ // wenn die o.g. Bedingungen nicht zutreffen, dann such das Array nach dem größtem Wert im Array heraus, der gleichzeitig kleiner als cap ist
    if (array[i] > maximum && array[i] <= cap){
      maximum = array[i];
    }
  }
  return maximum;

}

int main() {
  char filename[1000];
  printf("Enter a filename that contains the given array:\n");
  scanf("%s", filename); //erfordert die Eingabe des vollständigen Pfades, in dem sich die textdatei valuesP4 befindet 

int size;
int* arr = new int[size];

FILE *datei;

datei = fopen(filename, "r");

if (datei == nullptr){
  printf("File not found\n");
  return 1;
}

else{
  for (int i = 0; i < 1; i++){
    if (i == 0){
      fscanf(datei, "%i\n", &size);
      printf("The size of the array is %i.\n", size);
    }
  }
  printf("The array contains the following values:\n");
  for (int i = 0; i < size; i++){
    fscanf(datei, "%i\n", &arr[i]);
    printf("[%i", arr[i]);
  printf("]\n");

  }

}

fclose(datei);

int cap;
  printf("Enter the value of cap:\n");
  scanf("%i", &cap);
  printf("The capped max is %i.\n", capped_max(arr, size, cap));

  delete[] arr;

  return 0;
}
*/

void selection_sort_vorlesung(float array[], int size) {
  for (int i = 0; i < size; ++i) {
    // find the position of the minimum in array[i, size-1]
    int min_pos = i;
    for (int j = i + 1; j < size; ++j) {
      if (array[min_pos] > array[j]) {
        min_pos = j;
      }
    }
    // swap array[i] with the minimal value in array[i, size-1]
    int tmp = array[i];
    array[i] = array[min_pos];
    array[min_pos] = tmp;
  }
}

int main(){
  float array [] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int size = 9;
  void selection_sort_vorlesung();
}