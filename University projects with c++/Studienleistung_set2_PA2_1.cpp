#include <cstdio>

int faculty (int x){

    int faculty = x * (x-1);

    if (x == 1){
        faculty = 1;
    }

    for (int i = (x-2); i > 0; i--){
        faculty *= i;
    }
    return faculty;
}

int main (){

    int x = 12;

    printf("Die Fakultaet aus %i! ist %d", x, faculty(x));

    return 0;
}