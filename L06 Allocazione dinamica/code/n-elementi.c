#include <stdio.h>
#include <stdlib.h>
void *my_malloc( size_t n ) {
  void *p;
  p = malloc( n );
  if ( p == NULL ) {
      printf( "Spazio insufficiente.\n" );
      exit( EXIT_FAILURE );
  } 
  
  return p;
}

int *read_n( int *num ) {
  int *a, i;
  scanf( "%d", num );
  
  a = my_malloc( *num * sizeof(int) );
  for ( i = 0; i < *num; i++ ) {
    scanf( "%d", &a[i] ); // scanf("%d", a+i);
  }

  return a;
}

int main(void) {
  // Restituisce un puntatore alla zona allocata dall'array
  int *mem, n;
  printf("insert n: ");
  mem = read_n(&n);
  
  int *p;
  printf("\n\n");
  for (p=mem; p < mem+n; p++)
    printf("%d ", *p);

  return 0;
}

/*
 Qual è lo scopo del ciclo nelle righe 6-8?
Riempire un array tramite standard input.

 Riscrivete la riga 7 usando la notazione dei puntatori invece che quella degli array.
// scanf("%d", a+i);

 Lo spazio allocato per il puntatore a è allocato sullo stack o sullo heap?
Sullo stack, è un puntatore.

 I valori letti da standard input (scritti in memoria tramite l’invocazione di scanf nella riga 7) sono memorizzati
nello stack oppure nello heap. Perché?
Nello heap.

 Perché num è dichiarato come puntatore a intero?
Sennò non si potrebbe modificare n.

 Cosa restituisce la funzione?
Puntatore al primo elemento dell'array.

 Oltre a restituire un valore, la funzione ha degli effetti collaterali (es: produzione di output, modifica dello stato
della memoria)?
Viene modificato il valore di num per sapere quanti elementi ci sono nell'array.

 Scrivete un main per testare la funzione; rappresentate con dei disegni lo stato della memoria subito prima e subito
la chiamata della funzione read_n nel main. Distinguete tre zone: quella che rappresenta lo heap, quella che
rappresenta il record di attivazione della funzione read_n e quella che rappresenta il recordi di attivazione del
main.


 Modificate il programma in modo da memorizzare n caratteri invece che n numeri interi.

*/