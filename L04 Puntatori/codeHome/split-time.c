#include <stdio.h>
#define N 5

void split_time( long int tot_sec , int *h, int *m, int *s ) {
    *h = tot_sec / 3600;
    tot_sec %= 3600;
    *m = tot_sec / 60;
    *s = tot_sec % 60;
}

int main( void ) {
    int time = 23425 , h=0, m=0, s=0;

    split_time( time , &h , &m , &s );
    printf( "h = %d, m = %d, s = %d\n", h, m, s );

    return 0;
}

/*
Analizzate il codice e rispondete per iscritto alle seguenti domande.
1. Di che tipo sono i parametri h, m e s della funzione dichiarata nella linea 4? A cosa serve dichiararli così?
Sono dichiarati in modo da puntare al contenuto di un indirizzo di memoria. Serve per
evitare di copiare i valori dei parametri passati, e passare solamente l'indirizzo dal main.

2. Nella figura ci sono due porzioni di memoria identificate dallo stesso nome h. In che cosa si distinguono?
Una è la variabile h locale, l'altra è una cella di memoria che punta a quella variabile. (e ha l'indirizzo di h)

3. Completate opportunamente la invocazione di riga 14.
4. Completate opportunamente la definizione della funzione split_time (righe 5-8) facendo in modo che gli
assegnamenti modifichino il valore delle variabili locali della funzione main.
5. Verificate il funzionamento del programma completo, testandolo con valori di time diversi.
*/