#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 100
 
char cifra( char c, int k );
 
int main( int argc, char *argv[] ) {
 
  int k, i = 0;
  char op = argv[1][0];   // Essendo argv[1] una stringa, per prelevare il carattere occorre argv[1][0]
  char testo[N];
  char *modificato;
 
  while ( ( testo[i] = getchar() ) != '\n' ) {
    i++;
  }
  testo[i] = 0;   // Aggiungo un terminatore
  modificato = malloc(i * sizeof(char));  // Mancava l'allocazione della stringa modificato
 
  scanf( "%d", &k );  // k = chiave, servirebbe un controllo
  if ( op == 'D' )
    k = k * -1;
 
 
  i = 0;
  while ( testo[i]  != '\0' ) {
    modificato[i] = cifra( testo[i], k );
    i++;
  }
 
 
  printf ( "Testo inserito: %s\n", testo );
  if ( op == 'C')
    printf ( "Testo cifrato:" );
  else
    printf ( "Testo decifrato:");
  printf ( " %s\n", modificato );
 
  return 0;
}
 
char cifra( char c, int k) {
  int neg = 0;
  if ( k < 0 ) {
    neg = 1;
    k = k * -1;
  } 

  if ( isalpha( c ) ) {
    for (int j=1; j<=k; j++) {
      if (islower(c)) {
        if (neg) {
          if (c != 'a')
            c--;
          else
            c = 'z';
          } else if ( c != 'z')
          c++;
        else
          c = 'a';
      } else {
        if (neg) {
          if (c != 'A')
            c--;
          else
            c = 'Z';
          } else if ( c != 'Z')
          c++;
        else
          c = 'A';
      }
    }
    return c;   // Mancava il return
  }
 
  else return c;
}