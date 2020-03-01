#include <stdio.h>
char garibaldi( char a, char b ){
    if ( b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u' )
    return a;
    else return b;
}

int main () {
     char c, vocale;

     vocale = getchar();
     getchar();

     while ( ( c = getchar() ) != '.' )
     printf( "%c", garibaldi( vocale , c ) );

     printf( "\n" );
     return 0;
}

/*
1. Senza eseguire il programma al computer, simulatene l’esecuzione su carta e stabilite cosa stampa il
programma quando riceve da standard input la sequenza di caratteri:
u garibaldi fu ferito, fu ferito in una gamba.
Sostituisce le vocali nella frase con la vocale indicata inizialmente.

2. Descrivete a parole cosa fa la funzione garibaldi.
Data b vocale, viene sostituita con il carattere indicato da a. Altrimenti returna la vocale standard passata per parametro.

3. Riassumete a parole cosa fa il programma.

*/