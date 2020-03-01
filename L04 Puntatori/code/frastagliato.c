#include <stdio.h>
#include <string.h>

void f( char *a[], int n, int i ) {
  if ( i < 0 || i > n-1 )
    return;

  char *p = a[i];
  a[i] = a[n-1];
  a[n-1] = p;
  return;
}

int main( int argc, char **argv ) {
  char **q;
  int i;

  scanf( "%d", &i ); 
  f( argv + 1, argc - 1, i );

  for ( q = argv + 1; q < argv + argc; q++  )  
    printf( "%s ", *q );
  printf( "\n" );
  return 0;
}

/*
Analizzate il codice sorgente e rispondete per iscritto alle seguenti domande. Se avete dubbi, potete testarlo,
eseguendolo su casi di input significativi e modificandolo.
1. Di che tipo è la variabile p? Suggerimento: provate a definire con typedef un tipo String sinonimo di
char *
È puntatore all'elemento a[i].
typedef String char*; o char * String

2. Per cosa viene usata la variabile p?
Per prendere la posizione in memoria dell'elemento in posizione i

3. Perche il primo argomento dell’invocazione di f alla riga 19 è argv+1 e non argv?
Perché argv si riferisce al nome del file, ovvero argv[0]

4. Come mai il primo paramentro della funzione f è dichiarato con char *a[] mentre il primo argomento
passato alla funzione alla riga 19 è argv che è dichiarato alla riga 16 con char** argv?
Sono la stessa cosa, dichiarata in due modi diversi.

5. Senza eseguire il programma al computer, stabilite cosa stampa se viene eseguito con il comando
./a.out zero uno due tre quattro ultimo         Manca l'indice i in input
. Date un nome più significativo alla funzione f.
Si potrebbe chiamare "scambiaElementi"

7. Sarebbe corretto sostituire le rige 8-10 con le righe seguenti? Giustificate la risposta.
strcpy( *p, a[i] );
strcpy( a[i], a[n-1] );
strcpy( a[n-1], p );

Non si può fare in quanto le lunghezze delle stringhe sarebbero diverse, e creerebbe problemi.

8. Riassumete con una frase cosa fa il programma.
Prende in input un indice i, e scambia l'elemento in posizione i e l'ultimo.
*/