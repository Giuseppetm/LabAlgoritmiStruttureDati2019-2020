#include <stdlib.h>
#include <stdio.h>

void *my_malloc( size_t n ) {
  void *p;
  p = malloc( n );
  if ( p == NULL ) {
      printf( "Spazio insufficiente.\n" );
      exit( EXIT_FAILURE );
  } 
  
  return p;
}
/*
A cosa serve la condizione nell’if nella riga 7?
A controllare che l'allocamento sia andato a buon fine.

 Cosa indica la macro EXIT_FAILURE?
Restituisce un piccolo ammontare di informazione per indicare che c'è stato un errore.
This macro can be used with the exit function to indicate unsuccessful program completion 
in a general sense. On POSIX systems, the value of this macro is 1.

 Qual’è l’effetto della funzione exit comando nella riga 9?
Restituisce 1.

 Completate la printf nella riga 8 con un messaggio opportuno.
// Spazio insufficiente.

 Confrontate il prototipo delle funzione my-malloc con quella di malloc definita in stdlib.h.


 Scrivete un’analoga funzione my-realloc con lo stesso prototipo della funzione malloc
*/