#include <stdio.h>
void scambia(int *p, int *q);
int main() {
    int n1,n2;
    printf("insert n1 and n2: ");
    scanf("%d %d", &n1, &n2);
    scambia(&n1,&n2);
    printf("%d %d\n", n1,n2);
}

void scambia(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
/*
1. Scrivete una funzione con prototipo void scambia( int *p, int *q ) che scambi i valori delle due
variabili puntate da p e q.
2. Testate la funzione scrivendo un programma che legge due interi, li scambia invocando opportunamente la
funzione scambia e infine li stampa nel nuovo ordine.
3. Rappresentate graficamente lo stato della memoria subito dopo la chiamata della funzione.
*/