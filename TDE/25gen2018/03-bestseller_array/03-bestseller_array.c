#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//FORMATO: title TAB author TAB publisher TAB mm/dd/yyyy TAB Fiction
typedef struct bestseller {
  char *title;
  char *author;
  char *publisher;
  char *date; /* mese/giorno/anno */
  char *fiction;
} *Bs;

Bs read_bs(); // legge una riga con i dati di un bestseller
void print_bs( Bs b); // stampa i dettagli di un bestseller


int main(){
  char comando = '\0';
  char *date;
  Bs temp;

  int elem = 0, dim = 10;
  Bs *b = malloc(dim * sizeof(struct bestseller));

  while( (comando = getchar()) != 'f' ) {
    switch( comando ) {

    case '+': // seguito da riga con dettagli su un bestseller
      printf("entered +\n");
      temp = read_bs();
      b[elem] = temp;
      elem++;
      if (elem == dim) {
        dim *=2;
        b = realloc(b, dim*sizeof(struct bestseller));
      }
      break;

    case '?': // seguito da una data. stampa il libro bestseller in quella data
      printf("entered ?\n");
      date = malloc(20*sizeof(char));
      scanf("%s", date);
      for (int i = 0; i < elem; i++) {
        if (strcmp(b[elem]->date, date) == 0)
          printf("%s: %s - %s\n", b[elem]->date, b[elem]->title, b[elem]->author);
          break;
      }
      break;

    }
  }

  return 0;
}

// legge da standard input fino a quando non trova un carattere di tabulazione (e ignorando gli spazi iniziali)
char *read_tab( void ) {
  char *p, c;
  int size = 2;
  int n = 0;

  p = malloc( size );
  while ( isspace( c = getchar() ) )  // Ignoro gli spazi iniziali
      ;

  while ( c != EOF ) {

    /* se ho terminato lo spazio, raddoppio l'allocazione */
    if ( n >= size ) {
      size *=2;
      //printf( "\nnew size = %d\n", size );
      p = realloc( p, size * sizeof(char) );
    }

    /* memorizzo l'n-esimo elemento */
    if ( c == '\t' ) { /* se leggo '\t', memorizzo '\0' e interrompo */
      p[n] = '\0';
      break;
    }

    p[n++] = c;
    c = getchar();
  }

  printf( "%s\n", p );
  return p;
}

Bs new_bs() {
  Bs b = malloc(sizeof(struct bestseller));
  b -> title = malloc(256*sizeof(char));
  b -> author = malloc(256*sizeof(char));
  b -> publisher = malloc(256*sizeof(char));
  b -> date= malloc(256*sizeof(char));
  b -> fiction = malloc(256*sizeof(char));
  return b;
}

// legge una riga con i dati di un bestseller e la memorizza in una struttura di cui restituisce l'indirizzo
Bs read_bs(){
  // faccio read_tab finché non incontro \n
  Bs new = new_bs();
  new -> title = read_tab();
  new -> author = read_tab();
  new -> publisher = read_tab();
  new -> date = read_tab();
  new -> fiction = read_tab();
  return new;
}

// stampa i dettagli di un bestseller
void print_bs( Bs b) {
  //....
}