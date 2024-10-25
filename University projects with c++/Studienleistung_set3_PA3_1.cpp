#include <cstdio>

int minimum(int array[], int size){

    int minimum = array[0];

    for (int i = 0; i < size; i++){

        if (array[i] < minimum){

            minimum = array[i];
        }
    }

    return minimum;

}