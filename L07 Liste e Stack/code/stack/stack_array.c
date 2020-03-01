#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"
/* Le funzioni dichiarate nell’interfaccia stack.h vanno definite in un file stack.c di implementazione.
Naturalmente è possibile implementare l’interfaccia in molti modi diversi. Quando diciamo che la pila è un tipo di dato
astratto ci riferiamo proprio al fatto che al client è nota l’interfaccia, ma non l’implementazione: il client non può accedere
all’oggetto pila se non attraverso le funzioni fornite dall’interfaccia; inoltre è possibile modificare l’implementazione
dell’interfaccia senza interferire in nessun modo col client.
Dovete implementare la pila in due maniere diverse; ciascuna implementazione richiederà la costruzione di un file
apposito. */

// Implementazione stack: ultimo elemento è il top della pila
int *stack = NULL;
int n = 0, dim;          // Dimensione per riallocare

/* svuota la pila */
void make_empty( void ) {
     free(stack);
     stack = NULL;  // Quando è NULL vuol dire che è vuota
     n = 0;
     return;
}

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
Item is_empty( void ) {
     if (stack == NULL) {
          return 1;
     }
     return 0;
}

/* se la pila non e' vuota, restituisce il top della pila; 
altrimenti esce con messaggio di errore. */
Item top( void ) {
     if (is_empty() == 0) {
          return *(stack+n);
     }
     printf("Errore, pila vuota.");
     return 0;
}

/* se la pila non e' vuota, restituisce il top de1la pila; (e lo rimuove)
altrimenti esce con messaggio di errore. */
Item pop( void ) {
     if (is_empty() == 0) {
          Item final = *(stack+n);
          // Rialloco
          stack = realloc(stack, (--n)*sizeof(Item)); 
          return final;
     }
     printf("Errore, pila vuota.");
     return 0;
}

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push( Item item ) {
     stack = realloc(stack, (++n) * sizeof(Item));
     *(stack+n) = item;
     return;
}

/* stampa il contenuto della pila, partendo dal top. */
void print_stack( void ) {
     int *p;
     if (is_empty() == 0) {
          for ( p=stack+n; p > stack; p--) {
               printf("%d ", *(p));
          }
          printf("\n");
          return;
     }
     printf("Pila vuota.\n");
     return;
}