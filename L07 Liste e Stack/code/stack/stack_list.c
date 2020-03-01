#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

struct node {
    int info;
    struct node *next;
};

typedef struct node *Node;

Node head = NULL;

/* svuota la pila */
void make_empty( void ) {
     Node temp = head;
     while (head != NULL) {
          temp = head;   // ricordati che lavori su puntatori
          head = head->next;
          free(temp);
     }
     return;
}

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
Item is_empty( void ) {
     if (head == NULL)
          return 1;
     return 0;
}

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
Item top( void ) {
     if (!is_empty())
          return head->info;
     printf("Impossibile eseguire top su una pila vuota\n");
     exit(EXIT_FAILURE);
}

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
Item pop( void ) {
     if (!is_empty()) {
          Node temp = head;
          int popped = head->info;
          head = head->next;
          free(temp);
          return popped;
     }
     printf("Impossibile eseguire pop su una pila vuota\n");
     exit(EXIT_FAILURE);
}

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push( Item item ) {
     Node new = malloc(sizeof(struct node));
     new -> info = item;
     new -> next = head;
     head = new;
}

/* stampa il contenuto della pila, partendo dal top. */
void print_stack( void ) {
     Node l = head;
     while (l != NULL) {
          printf("%d ", l->info);
          l = l-> next;
     }
     return;
}
