#include <cstdio>

int min(int a, int b, int c){
    if (a == b && b == c) // Gleichheit bei allen Variablen
    {
       return a; 
    }
    if (a == b){ // a und b gleich, c unterschiedlich
        if (a < c){
            return a;
        }
        else{
            return c;
        }
    }
    if (a == c){ // a und c gleich, b unterschiedlich
        if (a < b){
            return a;
        }
        else{
            return b;
        }
    }
    if (b == c){ // b und c gleich, a unterschiedlich
        if (b < a){
            return b;
        }
        else{
            return a;
        }
    }
    if (a < b && a < c){ // a kleinste Zahl
        return a;
    }
    if (b < a && b < c){ // b kleinste Zahl
        return b;
    }
    if (c < a && c < b){ // c kleinste Zahl
        return c;
    }
    return 0;
}

int main() {
    int a = 15;
    int b = -7;
    int c = 42;

    printf("%i\n", min(a, b, c));
    
    return 0;
}