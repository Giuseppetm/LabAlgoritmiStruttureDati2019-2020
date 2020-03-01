/*
1. Scrivete una funzione struct node *olist_insert( int n, struct node *l ) che inserisca un elemento di
valore n nella lista ordinata l. Per trovare la posizione corretta in cui inserire n potete scorrere la lista fintanto che
il nodo corrente contiene un valore minore di quello di n.
2. Scrivete una funzione struct node *olist_search( int n, struct node *l ) che cerca un elemento di
valore n nella lista ordinata l. In quali casi si può interrompere la scansione della lista prima di arrivare all’ultimo
elemento?
*/
#include <stdio.h>
#include <stdlib.h>

struct node {   
  int info;   
  struct node *next;
};
                    
typedef struct node *Node;    // Uso Node perché struct è brutto <3

/* Inserisce un elemento di valore n nella lista ordinata l. Per trovare la posizione corretta in cui inserire n potete scorrere la lista fintanto che
il nodo corrente contiene un valore minore di quello di n. */
Node olist_insert( int n, Node l ) {
     Node prev = NULL;
     Node curr = l;
     while (curr != NULL && curr->info < n) {
          // Devo scorrere. Nel frattempo aggiorno previous e current
          prev = curr;
          curr = curr->next;
     }
     // Alloco lo spazio per il nuovo nodo
     Node new = malloc(sizeof(struct node));
     new->info = n;
     new->next = curr;
     prev->next=new;
     // Caso in cui n deve essere inserito all'inizio della lista
     if (prev == NULL) {
          l = new;
          return l;
     }
     return l;
}

/* Cerca un elemento di valore n nella lista ordinata l. (E penso restituisca il nodo in cui è contenuto) */
Node olist_search( int n, Node l ) {
     Node current = l;
     while (current != NULL) {
          if (current->info == n) {
               return current;
          }
          current = current->next;
     }
     return NULL;
}

//  In quali casi si può interrompere la scansione della lista prima di arrivare all’ultimo elemento?
/* Se ho trovato info == n, quindi l'elemento che cercavo.