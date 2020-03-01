#include <stdio.h>
#define LENGTH 100  
int main( void) {

    int a[LENGTH ];
    int *p;

    for( p = a; p < a + LENGTH; p++ ) { // Da a[0] ad a[LENGTH]
        scanf( "%d", p );
        if ( *p == 0 )      // Carichi l'array finché non leggi 0
            break;
    }

    while ( --p >= a )
        printf( "%d ", *p );

    printf( "\n" );
    return 0;
}

/*
- Che tipo di variabile è p?
Un puntatore a intero.

- Perché nella riga 11 il nome p non è preceduto dal simbolo % come al solito?
Perché si tratta già di un indirizzo di memoria in cui andrà memorizzato il numero inserito.

- Senza eseguire automaticamente il programma, tracciatene l’esecuzione quando riceve il seguente input:
1 2 3 4 5 0

Stampa l'array al contrario, escluso lo 0 obv.

- A cosa serve il ciclo for nelle righe 10-14?
A caricare l'array fino ad interrompere l'input tramite 0.

- A cosa serve il ciclo while nelle righe 16-74?
A stampare dall'ultimo elemento al primo.

- A cosa serve la variabile p?
È un indirizzo che serve a spostarsi da elemento in elemento dell'array.
*/