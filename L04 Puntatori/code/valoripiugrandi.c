#include <stdio.h>
void max_secondmax ( int a[], int n, int *max, int *second_max );
int main() {
    int a[] = {3, 4, 2, 9, 12, 10, 19, 8};
    int n = 8;
    int max,second_max;

    max_secondmax(a,n,&max,&second_max);
    printf("Max: %d, second Max: %d\n", max, second_max);
}

void max_secondmax ( int a[], int n, int *max, int *second_max ) {
    *max = a[0];
    *second_max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *max) {
            *second_max = *max;
            *max = a[i];
        } else if (a[i] < *max && a[i] > *second_max) {
            *second_max = a[i];
        }
    }
    return;
}

/*
1. Scrivete una funzione con prototipo
void max_secondmax ( int a[], int n, int *max, int *second_max )
che, dato un array a di lunghezza n, individui il valore più grande in a e il secondo elemento per grandezza
in a, e li memorizzi negli spazi di memoria puntate da max e second_max.
Suggerimento: i parametri max secondmax sono da utilizzare in modo simile ai paramentri h, m e s della
funzione split_time.
2. Testate il vostro programma invocandolo da un main strutturato secondo quanto indicato sopra. Notate che
gli argomenti passati in corrispondenza di max e secondmax devono essere indirizzi di memoria utili (ad
esempio indirizzi di variabili dichiarate opportunamente).
3. Rappresentate graficamente lo stato della memoria del programma subito prima dell’invocazione della
funzione e subito prima del return, riportando in aree diverse dei disegni la porzione di memoria relativa
alla funzione main e quella relativa alla funzione max_secondmax.
*/