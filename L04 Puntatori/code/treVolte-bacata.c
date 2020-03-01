#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

void treVolte( char *a[], int n ) {
  char **p, *q;
  int conta = 0;

  for ( p = a; p < a + n; p++ ) {
    int contae = 0;

    char *c;
    c = *p;

    while ( *c ) {
      if ( *c == 'e' )
	      contae++;

      if ( contae == 3 ) {
	      conta++;
        break;
      }
      c++;
    }

    if ( conta == 3 ) {
      // Gli strcopy non funzionerebbero
      q = *p;
      *p = a[0];
      a[0] = q;
      return;
    }

  }
}

int main( int argc, char **argv ) {
  treVolte( argv + 1, argc - 1);
  
  // Deve iniziare a stampare da argv+1 e non argv
  for ( char** p = argv + 1; p < (argv + argc); p++  )  
    printf( "%s ", *p );

  printf( "\n" );
  return 0;
}

/*Considerate il codice contenuto nel file treVolte-bacata.c. Esaminate il programma, rilevate gli errori e
correggeteli. Per ogni correzione, annotate un commento che spiega qual era l’errore e come l’avete corretto.
Il programma deve ricevere una sequenza di stringhe da linea di comando, invocare la funzione treVolte per
individuare la terza stringa, tra quelle lette, che contiene almeno 3 volte la lettera ‘e’ (minuscola) e scambiarla
con la prima, quindi stampare le stringhe nel nuovo ordine. Se non esiste nessuna stringa che soddisfa la proprietà
precedente, il programma deve stampare le stringhe nell’ordine in cui apparivano nella linea di comando. Ad
esempio, eseguendo il programma con comando
./a.out certamentissimamente signora non vorrei essere scortese posso ripetere le istruzioni
il programma deve stampare
ripetere signora non vorrei essere scortese posso certamentissimamente le istruzioni
NOTA: effettuate le modifiche necessarie a correggere gli errori ma senza stravolgere il programma.*/