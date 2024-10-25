#include <cstdio>

int interpolate(int l, int r, float l_value, float r_value, float x) {
  //============================================================================
  // Implementieren Sie hier die Funktion gemäß der Vorgaben.
  return (l + r) / 2;
  //============================================================================
}

// Interpolationssuche Suche:
// Entscheide, ob x im AUFSTEIGEND SORTIERTEN array[0,length-1] vorkommt
int find_faster(float array[], int size, float x) {
  // left/right: linke/rechte Grenze im noch zu durchsuchenden Array:
  int left = 0, right = size - 1;  // initialisiere

  while (right >= left) {  // solange das Suchintervall noch nicht leer ist

    int p = interpolate(left, right, array[left], array[right], x);
    printf("Interpolated: array[%i] = %g\n", p, array[p]);

    if (x == array[p]) return p;

    if (x < array[p]) {
      // falls x vorhanden, muss es in array[left,p-1] sein
      right = p - 1;
    } else {
      // falls x vorhanden, muss es in array[p+1,right] sein
      left = p + 1;
    }
  }
  return -1;  // x nicht gefunden => return -1
}

void print_all(float array[], int size);

int main() {
  float x_easy = 8;
  float arr_easy[24] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12,
                        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

  float x_hard = 77;
  float arr_hard[30] = {-1000, -777, -100, -77, 0,  77, 78, 79, 80, 81,
                        82,    83,   84,   85,  86, 87, 88, 89, 90, 91,
                        92,    93,   94,   95,  96, 97, 98, 99, 10};

  printf("Array (easy): ");
  print_all(arr_easy, 24);
  printf("\n\n");

  int result = find_faster(arr_easy, 24, x_easy);
  printf("Position of %g: %i\n\n", x_easy, result);

  printf("Array (hard): ");
  print_all(arr_hard, 24);
  printf("\n\n");

  result = find_faster(arr_hard, 24, x_hard);
  printf("Position of %g: %i\n", x_hard, result);

  return 0;
}

/* RICHTIGE AUSGABE:

Array (easy): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
19, 20, 21, 22, 23, 24]

Interpolated: array[7] = 8
Position of 8: 7

Array (hard): [-1000, -777, -100, -77, 0, 77, 78, 79, 80, 81, 82, 83, 84, 85,
86, 87, 88, 89, 90, 91, 92, 93, 94, 95]

Interpolated: array[22] = 94
Interpolated: array[20] = 92
Interpolated: array[18] = 90
Interpolated: array[16] = 88
Interpolated: array[14] = 86
Interpolated: array[12] = 84
Interpolated: array[10] = 82
Interpolated: array[8] = 80
Interpolated: array[6] = 78
Interpolated: array[5] = 77
Position of 77: 5

*/

void print_all(float array[], int size) {
  if (size == 0) {
    printf("[]");
  } else {
    printf("[%g", array[0]);
    for (int i = 1; i < size; ++i) {
      printf(", %g", array[i]);
    }
    printf("]");
  }
}