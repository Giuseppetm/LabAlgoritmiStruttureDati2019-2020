// Coda: struttura FIRST IN, FIRST OUT
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "coda.h"

/*
struct node {
    int info;
    struct node *next;
};
typedef struct node *Node;

struct coda {
     Node primo, ultimo;
     int size;
};
typedef struct coda *Coda;
*/

Coda new_coda() {   // Qua devi mettere primo e ultimo NULL
     Coda c = calloc(1, sizeof(struct coda));
     c -> primo = NULL;
     c -> ultimo = NULL;
     c -> size = 0;
     return c;
}    

Node new_node(int n) {
     Node node = calloc(1, sizeof(struct node));
     node -> info = n;
     node -> next = NULL;
     return node;
}

bool isEmpty(Coda c) {
     if (c->size == 0)
          return true;
     return false;
}

void enQueue(Coda c, int n) {
     Node p = new_node(n);
     if (c->primo == NULL) {
          c -> primo = p;
          c -> ultimo = p;
     } else {
          c->ultimo->next = p;
          c->ultimo = p;       // Sembra sbagliato ma in realtà funziona, perché prima riassegni il next dell'ultimo attuale
          // Poi l'ultimo attuale diventa p che è appunto il next del precedente ultimo
     }
     c->size++;
}

int deQueue(Coda c) {
     int x = c->primo->info;
     c->primo = c->primo->next;
     if (c->primo == NULL)
          c->ultimo = NULL;
     c->size--;
     return x;
}

int first(Coda c) {
     if (!isEmpty(c)) {
          return c->primo->info;
     }
     return -1;
}

void printCoda(Coda c) {
     Node temp = c->primo;
     if (!isEmpty(c)) {
          while (temp != NULL) {
               printf("%d ", temp->info);
               temp = temp -> next;
          }
     } else {
          printf("La coda è vuota.");
     }
     printf("\n");
}

void destroyCoda(Coda c) {
     free(c);  // Da implementare correttamente
}