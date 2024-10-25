#include <cstdio>

int gcd (int a, int b){

    int gcd = 0;

    if (a == b){
        return a;
    }

    while (a != b){

        if (a > b){
            gcd = a - b;
            a = gcd;
        }

        else{
            gcd = b - a;
            b = gcd;
        }
    }

    return gcd;
}

int main() {

    int a = 221;
    int b = 153;

    printf("Der groesste gemeinsame Teiler aus %i und %d lautet %li", a, b, gcd(a,b));

    return 0;
}