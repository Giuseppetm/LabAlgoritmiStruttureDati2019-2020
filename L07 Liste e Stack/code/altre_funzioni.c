/*
1. Scrivete una funzione void list_printInv( Node l ) che stampa gli elementi di una lista (individuata dall’indirizzo
del suo primo elemento).
2. Scrivete una funzione ricorsiva void list_printInv( Node l ) che stampa gli elementi della lista al contrario.
Nel passo iterativo, la funzione dovrà prima richiamare sé stessa sul prossimo nodo e poi concludersi stampando
il valore del nodo corrente.
3. Scrivete una funzione che, data una lista, costruisce un array con gli elementi della lista e ne restituisce l’indirizzo;
l’array va allocato dinamicamente.
4. Scrivete una funzione int* listToArray( Node l ) che, data una lista l contenente n interi, restituisce
l’indirizzo di un array di interi allocato dinamicamente contenente gli elementi della lista.
5. Scrivete una funzione void list_destroy ( Node l ) che cancelli tutti gli elementi della lista e liberi con
free lo spazio che era occupato dai nodi. Provate a scrivere la funzione sia in forma iterativa che in forma
ricorsiva. Perché la funzione è di tipo void?
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
     int info;
     struct node *next;
};

typedef struct node *Node;

/* 1. Scrivete una funzione void list_printInv( Node l ) che stampa gli elementi di una lista (individuata dall’indirizzo
del suo primo elemento). */
void list_printInv(Node l) {
     while (l->next != NULL) {
          printf("%d\n", l->info);
          l = l->next;
     }
}

/* 2. Scrivete una funzione ricorsiva void list_printInv( Node l ) che stampa gli elementi della lista al contrario.
Nel passo iterativo, la funzione dovrà prima richiamare sé stessa sul prossimo nodo e poi concludersi stampando
il valore del nodo corrente. */
void list_printInv( Node l ) {
     if (l == NULL) {
          return;
     }
     if (l->next == NULL) {
          printf("%d\n", l->info);
          return;
     }
     list_printInv(l->next);
     printf("%d\n", l->info);
}

/* 3. Scrivete una funzione che, data una lista, costruisce un array con gli elementi della lista e ne restituisce l’indirizzo;
l’array va allocato dinamicamente. */

// Sembra uguale al 4, rip
int *listToArray(Node l) {
     int *array, k;

     for (Node p = l; p != NULL; p = p->next)
          k++; // Conto quanti elementi ha la lista in modo da poter allocare lo spazio

     array = malloc(k * sizeof(int));

     for (int i=0; i < k; i++) {
          array[i] = l->info;
          l = l->next;
     }
     return array;
}

/* 5. Scrivete una funzione void list_destroy ( Node l ) che cancelli tutti gli elementi della lista e liberi con
free lo spazio che era occupato dai nodi. Provate a scrivere la funzione sia in forma iterativa che in forma
ricorsiva. Perché la funzione è di tipo void? */
void list_destroy(Node l) {
     Node temp;
     if (l == NULL) {
          return;
     } 

     while (l != NULL) {
          temp = l->next;
          free(l);
          l = temp;
     }
     return;
}

// Versione ricorsiva
void list_destroy(Node l) {
     if(l == NULL) {
          return;
     }
     list_destroy(l->next);
     free(l);
     return;
}

// La funzione è di tipo void in quanto deve solo liberare lo spazio allocato dalla lista 