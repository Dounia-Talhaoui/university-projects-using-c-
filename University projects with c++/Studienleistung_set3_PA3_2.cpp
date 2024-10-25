#include <cstdio>

int second_smallest(int array[], int size){

    int minimum = array[0];
    int sndminimum = array[1];
    int count = 0;

    if (sndminimum < minimum) { // wenn der erste Array-Eintrag größer ist als der zweite, werden beide Werte getauscht

        minimum = array[1];
        sndminimum = array[0];
    }

    for (int i = 2; i < size; i++){ // durchsucht erstmal, ob es einen noch kleineren Wert gibt als das jetzige Minimum. Falls ja, wird dieser neu gefundenen Wert dem minimum zugewiesen

        if (array[i] < minimum){

            sndminimum = minimum;
            minimum = array[i];
        }
    }

    for (int i = 0; i < size; i++){ // zählt, wie oft der Wert Minimum im Array vorkommt

        if (array[i] == minimum){

            count++;
        }
    }

    if (count >= 2){ // wenn minimum doppelt oder mehr vorhanden ist, wird das Programm abgebrochen und nur das Minimum herausgegeben

        return minimum;
    }

    else{

    for (int i = 2; i < size; i++) { // falls minimum nur einmal vorkommt, wird das array nach dem zweitklenstem Wert herausgesucht und herausgegeben

        if (array[i] < sndminimum && array[i] > minimum){

            sndminimum = array[i];
        }
    }

    return sndminimum;

    }
}

int main(){

    int array[] = {1,1,1,1};
    int size = sizeof(array) / sizeof(array[0]);

    printf("zweit kleinstes minimum: %i", second_smallest(array, size));
}
