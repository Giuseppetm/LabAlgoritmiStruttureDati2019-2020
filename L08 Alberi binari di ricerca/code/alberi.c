/* Il programma deve:
1. generi a caso una sequenza di interi (di lunghezza massima fissata con una opportuna macro) e la memorizzi in un
array;
2. costruisca un albero binario a partire dall’array (come descritto in seguito);
3. stampi l’albero nella reppresentazione a sommario (come descritta in seguito);
4. stampi i nodi dell’albero negli ordini determinati rispettivamente dalle visite in preordine, inordine e postordine.
*/
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct bit_node {
Item item;
struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

// Scrivere le funzioni:
void bit_printnode(Bit_node p) {
     printf("%d ", p->item);
}

Bit_node bit_new( Item item ) {
     Bit_node root; // Probabilmente qua intende creare uno nuovo con radice item
     root = malloc(sizeof(struct bit_node));
     root -> item = item;
     root -> l = NULL;
     root -> r = NULL;
     return root;
}

void bit_inorder ( Bit_node p) {
     if (p) {
          bit_inorder(p->l);
          bit_printnode(p);
          bit_inorder(p->r);
     }
}

void bit_preorder ( Bit_node p ) {
     if (p) {
          bit_printnode(p);
          bit_preorder(p->l);
          bit_preorder(p->r);
     }
}
void bit_postorder ( Bit_node p) {
     if (p) {
          bit_postorder(p->l);
          bit_postorder(p->r);
          bit_printnode(p);
     }
}
/* oltre ad eventuali altre funzioni utili sugli alberi binari, come elencato nelle slide. Ricordate che le funzioni riguardanti
gli alberi sono denotate dal prefisso bit (binary tree), mentre quelle specifiche per gli alberi di ricerca sono denotate dal
prefisso bist (binary search tree). */

/* ALBERI A SOMMARIO
Scrivete quindi una funzione che stampi un albero binario nella rappresentazione usata nei sommari dei libri, oppure in
un file browser. 
Notate che, nel caso in cui un nodo abbia un solo figlio, per poter distinguere tra figlio destro e figlio sinistro, è necessario
evidenziare con una riga vuota l’assenza del figlio mancante.
Per realizzare questa funzione, potete usare una visita in preorder ricorsiva, in cui la funzione di visita è data dalla stampa,
correttamente indentata, del contenuto del nodo. Il numero di spazi può essere dato come parametro della funzione, che
quindi avrà prototipo: */
void bit_printassummary ( Bit_node p, int spaces ) {
     for (int i = 0; i < spaces; i++)
          printf(" ");

     printf("*");
     if (p) {
          bit_printnode(p);
          printf("\n");
          if (p->l || p->r) {
               bit_printassummary(p->l, spaces+1);
               bit_printassummary(p->r, spaces+1);
          }
     } else {
          printf("\n");
     }
     return;
}
/*
e andrà chiamata nel modo seguente:
bit_printassummary ( root , 0 );
*/

/* DAL VETTORE ALL'ALBERO
Scrivete una funzione
Bitnode bit_arr2tree ( Item a[], int size , int i)
che, dato un array a di lunghezza size ed un indice i, costruisca ricorsivamente l’albero binario (completo) con radice
contenente l’Item a[0] e tale che valga la seguente proprietà: se un nodo è etichettato con a[i], allora il suo figlio
sinistro è etichettato con a[2*i+1] e il suo figlio destro è etichettato con a[2*i+2]. */
Bit_node bit_arr2tree ( Item a[], int size , int i) {
     // int a[] = {69, 89, 28, 39, 66, 44, 12, 2, 71};      size = 9, i = 0 : indice dell'elemento che vuoi mettere nell'albero
     Bit_node root = NULL;
     if (i < size) {
          root = bit_new(a[i]);
          root -> l = bit_arr2tree(a, size, 2*i+1);
          root -> r = bit_arr2tree(a, size, 2*i+2);
     }
     return root;
}

int main(void) {
     // Testing main
     Bit_node root ;
     // Testing vettore -> albero
     printf("\ntesting array to albero:\n");
     int a[] = {69, 89, 28, 39, 66, 44, 12, 2};
     root = bit_arr2tree (a, 8, 0);

     printf("preorder: ");
     bit_preorder(root);
     printf("\n\n");
     
     printf("inorder: ");
     bit_inorder(root);
     printf("\n\n");
     
     printf("postorder: ");
     bit_postorder(root);
     printf("\n\n");

     printf("stampa indentata:\n");
     bit_printassummary ( root , 0 );

     printf("\n");
     return 0;
}