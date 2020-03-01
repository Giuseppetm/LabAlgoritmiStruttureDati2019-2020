#include <stdlib.h>
#include <stdio.h>

//#define L 2
//#define L0 3
#define L 1

/* 
Alloca spazio per 3 interi. Riceve in input n, se è 0 finisce.
i = 0
Se i >= 3, aggiungi a size spazio per altri 2 elementi, e riallochi ad a spazio per 2 elementi in più.
a[i] = n (elemento inserito)
i++
Adesso la i nel Main, diventa esattamente il numero di elementi inseriti, mentre a punta al primo elemento dell'array.
Alla fine stamperà dall'ultimo elemento dell'array al primo.
*/

int *read_lin( int *num ) {
  int *a, i = 0, n;   
  //int size = L0;
  int size = L;
  
  a = malloc( size * sizeof(int) );  
  while ( 1 ) {   // loop infinito
    scanf( "%d", &n );
    
    if ( n == 0 )
      break;

    if ( i >= size  ) {
      // size += L;
      size *= 2;
      a = realloc( a, size * sizeof(int) ); // ridimensiona lo spazio puntato da a alla nuova dimensione size e restituisce il puntatore al primo elemento (oppure NULL):
    }
    
    a[i++] = n; // assegna ad a[i] <- n, e incrementa i
  }

  *num = i;
  return a; // e restituisce l'indirizzo del primo elemento dell'array
}

int main( ) {
  int i;
  int *a = read_lin( &i );

  while ( i-- > 0 )
    printf( "a[%d] = %d\n", i, a[i] ); 
}

/* Senza eseguirlo al computer, tracciate l’esecuzione del programma quando riceve il seguente input:
1 2 3 4 5 6 7 8 9 0
Stampa dall'ultimo elemento dell'array al primo escluso lo 0. a[8] = 9; a[7] = 8; ....

 Rappresentate con un disegno lo stato della memoria subito prima della lettura del numero 6. In particolare,
quant’è grande lo spazio cui punta a?
 Sullo stesso input, quante volte viene eseguita la funzione realloc?
Ogni qual volta i supera il limite di memoria disponibile allocata.

 A cosa servono le variabili size e i?
Size è la quantità di elementi che si possono inserire nell'array, e va incrementata ogni volta che non c'è più spazio per nuovi elementi.
i rappresenta il numero di elementi nell'array

 Cosa restituisce la funzione read_lin?
Restituisce la posizione in memoria del primo elemento dell'array (dove inizia l'array).

 A cosa serve il parametro num?
Il parametro num serve a tenere conto dell'indirizzo di dove inizia l'array (prima della chiamata di funzione) e dove finisce (dopo la chiamata).

 Riassumete con una frase cosa fa il programma.
Dati N elementi, stampa dall'ultimo elemento al primo, stampando anche la posizione dei vari elementi.

 Modificate il programma in modo che lo spazio re-allocato raddoppi ogni volta invece di crescere linearmente.
done.
*/