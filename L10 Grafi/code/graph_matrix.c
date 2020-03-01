// Implementazione con matrice di adiacenza
// Si suppone il grafo non orientato
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph {
     int n, m; /* n = num vertici, m = num lati */
     int **A; /* matrice di adiacenza */
};
// typedef struct graph *Graph;

Graph graph_new( int n ) {
     // La calloc ti dà il vantaggio di inizializzare tutti i campi al loro valore 0
     // Invece la Malloc alloca solo lo spazio di memoria
     Graph g = malloc(sizeof(struct graph));
     g -> A = calloc(n, sizeof(int *)); 
     g -> n = n;
     g -> m = 0;
     for (int i = 0; i < g->n; i++)
          g -> A[i] = calloc(n, sizeof(int));     // Dovrei averli già tutti a 0 quindi. Nice
     return g;         
}

void graph_destroy ( Graph g ) {
     for (int i = 0; i < g->n; i++) {
          free(g->A[i]);
     }
     free(g);
     printf("Distruzione grafo avvenuta correttamente.\n");
}

void graph_edgeinsert ( Graph g, int v, int w ) {
     g->A[v][w] = 1;
     g->A[w][v] = 1;            // matrice simmetrica in questo caso (forse, non ero bravo a discreto <3 )
     g->m++;
}

Graph graph_read( void ) {
     int k;         // Numero di vertici
     printf("Inserisci numero di vertici: ");
     scanf("%d", &k);
     Graph g = graph_new(k);
     int v1, v2;

     printf("---Inserire due vertici per volta, da collegare (both -1 to stop)---\n");
     scanf("%d", &v1);
     scanf("%d", &v2);

     // Sto ciclo si può migliorare
     for (;;) {
          if (v1 == -1 || v1 < 0 || v1 >= g->n) {
               printf("Arco non inserito; uscita dal ciclo.\n");
               break;
          }
          if (v2 == -1 || v2 < 0 || v2 >= g->n) {
               printf("Arco non inserito; uscita dal ciclo.\n");
               break;
          }
          graph_edgeinsert(g, v1, v2);
          scanf("%d", &v1);
          scanf("%d", &v2);
     }
     printf("\n");
     return g;
}

void graph_print ( Graph g ) {
     for (int i = 0; i < g->n; i++)
          for (int j = 0; j < g->n; j++) {
               if (j % g->n == 0)
                    printf("\n");
               printf("%d ", g->A[i][j]);
          }
     printf("\n");     
}

// Testing main
int main(void) {
     Graph g = graph_read();
     graph_print(g);
     graph_destroy(g);
}