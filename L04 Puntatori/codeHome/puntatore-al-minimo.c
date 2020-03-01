#include <stdio.h>
#define LENGTH 100
int *smallest( int a[], int n );
int main() {
    int a[LENGTH], n = 0, *p;
    printf("loading array:\n");

    for (p=a; p < a+LENGTH; p++) {
        scanf("%d",p);
        if (*p == 0) {
            break;
        }
        n++;
    }
    
    printf( "%d", *smallest( a, n ) );
}

int *smallest( int a[], int n ) {
    int *min;
    min = a;
    int *i;
    for (i = a+1; i < a + n; i++) {
        if (*i < *min) {
            min = i;
        }
    }
    return min;
}
/*
1. Scrivete una funzione con prototipo int *smallest( int a[], int n ) che, dato un array a 
di lunghezza n, restituisca un puntatore all’elemento più piccolo dell’array.
2. Testate la funzione inserendola in un programma che legga una sequenza di numeri, 
la memorizzi un un array a e stampi il valore più piccolo del vettore usando 
l’istruzione printf( "%d", *smallest( a, n ) ).
*/