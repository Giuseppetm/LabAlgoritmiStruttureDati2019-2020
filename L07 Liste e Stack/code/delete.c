#include <stdio.h>
#include <stdlib.h>
  
struct node {   
  int info;   
  struct node *next;
};

void list_delete( int n, struct node **l){
  struct node *curr, *prev;
  for ( curr = *l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
    if (curr -> info == n ) break;
  }
  if (curr == NULL)
    return; // Non hai trovato l'elemento, quindi non si trova nella lista
  if (prev == NULL)
    *(l) = (*l) -> next;  // Se l'elemento che vuoi eliminare è all'inizio, allora stacchi l'elemento iniziale e fai iniziare la lista da quello successivo
  else 
    prev -> next = curr -> next; // Altrimenti, se è nel mezzo ad esempio, il successivo del precedente diventa il successivo del current (di quello che vuoi deletare)
  free(curr);
}

int main() {
  struct node *first = NULL;
  int n = 10;
  list_delete( n , &first );
  list_print( first );
  return 0;
}

/*
1. Quando viene eseguita la riga 10? Fornite un esempio specifico.
L'elemento che stai cercando non si trova nella lista.
Vuol dire che sei arrivato all'ultimo elemento che punta NULL.
n = 2, l={20,3,1,4}

2. Quando viene eseguita la riga 12? Fornite un esempio specifico.
Se l'elemento che stai cercando si trova all'inizio della lista. (è l'elemento iniziale)
n = 10, l={10,4,5,3,2}

3. Quando viene eseguita la riga 14? Fornite un esempio specifico.
Quando l'elemento che vuoi eliminare non si trova all'inizio della lista, ma nel mezzo ad esempio.
n = 5, l = {10,5,4,3,2}

4. Commentate la funzione list_delete in modo da documentare quando vengono eseguiti i vari casi.
k

5. Considerate gli esempi che avete scritto prima: in quale caso l’invocazione della funzione list_delete e della
successiva stampa nelle righe 22 e 23 non produce l’effetto desiderato?
Quando l'elemento si trova all'inizio, perché non stai lavorando con l'indirizzo del primo elemento della lista.

6. Modificate la funzione list_delete e la sua invocazione nel main in modo da eliminare il problema rilevato
sopra.
k
*/