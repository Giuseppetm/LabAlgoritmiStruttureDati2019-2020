#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef char *String;
typedef struct{
  int size;
  int count;
  String *content;    
} *Elenco;


int main( void ) {
  // Size dichiarata come variabile locale, è inutile.
  Elenco b = malloc( sizeof(Elenco) );
  b -> size = 4;
  b -> count = 0;
  b -> content = calloc( b->size, sizeof(String) );

  int i = 0;
  while(1) {    // Molto meglio fare un loop che viene interrotto quando si inserisce "FINE"
    char *name = calloc(N+1,sizeof(char));    // Name va dichiarata dinamicamente.
    scanf( "%s", name );
    if (strcmp(name, "FINE") == 0)
      break;
    b -> count++;   // Numero di elementi incrementato man mano che si inserisce

    if ( b -> count == b -> size ) {
      b -> size*=2;   // Raddoppio la grandezza dell'array
      b-> content = realloc(b-> content, (b->size * sizeof(String)));   // E lo rialloco
    }

    b -> content[i] = name;
    i++;
  }

  for ( int k = 0; k < b -> count; k++ )    // Stampa
      printf( "%s\n", b -> content[k] );

  return 0;
}

/*
Esaminate il programma che trovate in calce, rilevate gli errori e correggeteli.

Il programma deve:

- leggere da standard input un elenco di parole, scritte una per riga, terminato dalla parola FINE (ogni parola è una sequenza
di caratteri alfabetici senza spazi, la parola FINE non fa parte dell'elenco);

- memorizzare le parole lette in un array allocato dinamicamente, membro di una struttura che rappresenta l'elenco;

- ristampare tutti i nomi letti.

Per ogni correzione, annotate un commento che spiega qual era l'errore e come l'avete corretto.
NOTA IMPORTANTE: effettuate le modifiche necessarie a correggere gli errori ma senza stravolgere il programma.
*/