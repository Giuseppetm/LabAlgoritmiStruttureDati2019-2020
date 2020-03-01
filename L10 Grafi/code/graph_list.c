// Implementazione lista di adiacenza
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "coda.h"
#include <time.h>

struct listnode {
     struct listnode *next;
     int v;
};

struct graph {
     int n, m;      // Numero nodi, numero archi
     struct listnode **A;       // Ogni nodo ha la sua lista di adiacenza (quali gli sono vicini)
};
//typedef struct graph *Graph;
typedef struct listnode *Listnode;

/* crea un grafo con n nodi */
Graph graph_new( int n ) {
     Graph g;
     // Alloco lo spazio per n vertici
     g = calloc(1, sizeof(struct graph));
     if (!g) {
          printf("Errore di allocazione.\n");
          exit(EXIT_FAILURE);
     }
     // L'inizializzazione va fatta nella funzione, come dice il buon Dario!
     g -> n = n;
     g -> m = 0;    // Inizialmente ho 0 archi
     g -> A = calloc(n, sizeof(struct listnode*));     // Alloco lo spazio per n liste di adiacenza (una per ogni nodo)
     printf("---Grafo creato, nodi presenti: ");
     for (int i = 0; i < g->n; i++) {
          printf("%d ", i);
     }
     printf(" ---\n");
     return g;
}

Listnode newNode(int p) {
     Listnode nodo = malloc(sizeof(struct listnode));
     nodo -> v = p;
     nodo -> next = NULL;
     return nodo;
}

// Funzione per inserire i vertici nelle liste di adiacenza
Listnode arco(Listnode list, int k) {
     Listnode p = newNode(k);
     Listnode head = list;
     if (!head)
          return p;

     while (list -> next != NULL) {     // Inserisco alla fine della lista
          list = list -> next;
     }
     list -> next = p;
     return head;
}

/* inserisce l’arco (v,w) nel grafo g */
void graph_edgeinsert ( Graph g, int v, int w ) {
     g -> A[v] = arco( g->A[v], w);
     g -> A[w] = arco( g->A[w], v);
     g->m++;
}

/* legge da standard input un grafo (specificare il formato!!) */
Graph graph_read(void) {
     int k;         // Numero di vertici
     printf("Inserisci numero di vertici: ");
     scanf("%d", &k);
     Graph g = graph_new(k);
     int v1, v2;

     printf("---Stabilire le connessioni tra i vertici (-1 -1 to stop)---\n");
     scanf("%d", &v1);
     scanf("%d", &v2);

     while (v1 != -1 && v2 != -1 && v1 >= 0 && v1 < g->n && v2 >= 0 && v2 < g -> n) {
          graph_edgeinsert(g, v1, v2);
          scanf("%d", &v1);
          scanf("%d", &v2);
     }
     return g;
}

/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print ( Graph g ) {
     printf("\n---Stampa grafo---\nNum. vertici(n): %d\nNum. archi(m): %d\n\n", g->n, g->m);

     // Fai una funzione che stampa la lista di adiacenza di un nodo
     /* printf("---Inserisci nodo di cui stampare lista di adiacenza---\n");
     int n;
     scanf("%d", &n);
     Listnode temp = g-> A[n];
     printf("---Stampa lista di adiacenza---\n");
     while (temp != NULL) {
          printf("%d ", temp -> v);
          temp = temp -> next;
     }
     printf("\n"); */

     // 04.02.2020 - Stampo tutte le liste di adiacenza dei nodi
     printf("---Dettagli archi---\n");
     for (int i = 0; i < g->n; i++) {
          Listnode temp = g->A[i];
          if (temp == NULL)   // Lo faccio pulito in caso non ho inserito quel nodo
               continue;
          printf("Nodo %d -> ", i);
          while (temp != NULL) {
               printf("%d ", temp->v);
               temp = temp -> next;
          }
          printf("\n");
     }
}

/* distrugge il grafo g */
void graph_destroy ( Graph g ) {
     // Credo che si debba liberare ogni listnode **A associato al grafo, e infine il grafo stesso
     for(int i = 0; i < g -> n ; i++){
           free(g -> A[i]);
     }
     free(g);
     printf("\nDistruzione avvenuta correttamente. Mr Incredibile, terminato.\n");
}

void dfs(Graph g, int vertex, int *visited) {    // Visita in profondità
     Listnode temp = g->A[vertex];
     
     visited[vertex] = 1;
     printf("Visited %d\n", vertex);

     while (temp != NULL) {
          int connectedV = temp->v;
          if (visited[connectedV] == 0) {
               dfs(g, connectedV, visited);
          }
          temp = temp -> next;
     }
}

void bfs(Graph g, int startV) {      // Visita in ampiezza
     Coda q = new_coda();
     int *visited = calloc(g->n, sizeof(int));
     visited[startV] = 1;
     enQueue(q, startV);

     while (!isEmpty(q)) {
          //printCoda(q);
          int currentV = deQueue(q);
          printf("Visited %d\n", currentV);

          Listnode temp = g->A[currentV];
          while (temp) {
               int adjV = temp->v;
               if (visited[adjV] == 0) {
                    visited[adjV] = 1;
                    enQueue(q, adjV);
               }
               temp = temp -> next;
          }
     }
     printf("Visita BFS completata.\n");
     free(visited);
}

/* 1. gen (p) genera un grafo casuale, a partire dalla probabilità p compresa tra 0 e 1 (inclusi).
Il modello matematico di riferimento è il seguente: si considerano tutti i possibili archi includendoli nel grafo con
probabilità p. Più esplicitamente, per ogni possibile coppia di vertici, si genera un numero reale compreso tra 0 e
1; se questo è minore di p si inserisce l’arco, altrimenti non lo si inserisce.
NB: potete usare questa operazione per generare grafi su cui testare la correttezza dei vostri programmi! */
Graph gen(double p, int n) {
     // p compreso tra 0 e 1
     Graph g = graph_new(n);
     srand(time(0));
     for (int i = 0; i < g->n -1; i++) {
          for (int j = 0; j < g->n -1; j++) {
               printf("ciclo entrato\n");
               double res = rand() % 1;
               printf("numero generato\n");
               if ( res < p ) {
                    // Inserisci arco, ma dovresti anche controllare che non sia già stato inserito
                    graph_edgeinsert(g, i, j);
               }
               graph_print(g);
          }
     }

}

/* 2. degree (v) calcola il grado del vertice v.
Si ricorda che il grado di un vertice è definito come il numero di vertici ad esso adiacenti. */
int degree(Graph g, int v) {
     int degree = 0;
     Listnode adiacent = g->A[v];
     while (adiacent != NULL) {
          degree++;
          adiacent = adiacent -> next;
     }
     return degree;
}

int main(void) {
     // Graph g = graph_read();
     // Graph g = graph_new(7);
     // graph_edgeinsert(g, 0, 1);
     // graph_edgeinsert(g, 0, 2);
     // graph_edgeinsert(g, 1, 2);
     // graph_edgeinsert(g, 1, 4);
     // graph_edgeinsert(g, 1, 3);
     // graph_edgeinsert(g, 2, 4);
     // graph_edgeinsert(g, 3, 4);

     // Test L
     Graph g = graph_new(7);
     graph_edgeinsert(g, 0, 1);
     graph_edgeinsert(g, 1, 2);
     graph_edgeinsert(g, 2, 3);
     graph_edgeinsert(g, 0, 4);
     graph_edgeinsert(g, 4, 5);
     graph_edgeinsert(g, 5, 6);
     graph_print(g);

     /*
     printf("\n---Stampa BFS (Visita in ampiezza)---\n");
     bfs(g, 0);
     */

     /*
     int *visited = calloc(g->n, sizeof(int));
     printf("\n---Stampa DFS (Visita in profondità)---\n");
     dfs(g, 0, visited);
     printf("Visita DFS completata.\n");
     graph_destroy(g);
     */


     // Testing generazione grafo casuale
     printf("\n---Testing generazione casuale di un grafo---\n");
     Graph gRand = gen(0.3, 5);      // Argomenti: p , n
     graph_print(gRand);
     //bfs(gRand, 0);
}