#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct element {  // elemento di lista
  char ch;
  struct element *next;    // prossimo elemento
};

struct graph {
  int n, m;
  struct element **A; // vettore delle liste di adiacenza
};

typedef struct graph *Graph;

/* crea una struttura grafo con n nodi */
Graph newGraph( int n ){
	Graph g = malloc(sizeof(struct graph));
	if(!g) {
    fprintf(stderr,"Errore di Allocazione\n");
	  exit(EXIT_FAILURE);
	}
	g -> n = n;
  g -> m = 0;
	g -> A = calloc( n, sizeof( struct element* ) ); // vettore delle liste di adiacenza: g -> A [i] e' la lista dell'i-esimo nodo
	return g;
}

// inserimento in liste di adiacenza
struct element *list_insert( struct element *list, char ch ) {
	struct element *new = malloc( sizeof( struct element ) );
	new -> ch = ch;
	new -> next = list;
	return new;
}

// inserisce nel grafo l'arco x -> y
void addEdge( Graph g, char x, char y){
  g->A[x-'A'] = list_insert(g->A[x-'A'],y);
  g->m++; // Va anche incrementato il numero di archi.
}

/* stampa su standard output le liste di adiacenza di g */
void printGraph( Graph g ){
	printf( "\n************** stampo grafo\n" );
	int n = g -> n;
	struct element **al = g -> A;
	struct element *curr;

	printf( "%d nodi\n%d archi\n", n, g -> m );

	for ( int i = 0; i < n; i++ ) {
		printf( "%c:", 'A'+i );
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
			printf( " %c", curr -> ch );
		}
		printf( "\n" );
	}
	printf( "fine stampa grafo *************************\n\n");

}

/* Legge da standard input
un intero m positivo,
un insieme R di m regole della forma XY;
costruisce un grafo che rappresenta R;
ne restituisce l'indirizzo.
NB: Per leggere una regola della forma XY potete usare scanf( " %c%c", &x, &y ) con x e y definite opportunamente. */
Graph read() {
  Graph g = newGraph(24);   // Metto tutte le lettere dell'alfabeto, probabilmente si può fare in modo smart
  int m;
  char x,y;

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf( " %c%c", &x, &y);
    addEdge(g,x,y); 
  }
  return g;
}

/*
Ha per argomento una lettera K e un grafo che rappresenta un insieme di regole R,
stampa tutte le lettere che possono seguire K rispettando R. */
void followers(Graph g, char k) {
  struct element *p = g->A[k-'A'];
  while (p != NULL) {
    printf("%c", p->ch);
    p = p->next;
  }
  printf("\n");
  return;
}

/* Ha per argomento un grafo che rappresenta un insieme di regole R,
stampa in ordine alfabetico tutte e sole le lettere che possono essere seguite dal maggior numero di lettere, rispettando R. */
void max(Graph g) {
  // Calcolo prima il numero massimo di lettere
  int max = 0;
  int count;
  for (int i=0; i < g->n; i++) {
    count = 0;
    struct element *temp = g->A[i];
    while (temp != NULL) {
      count++;
      temp = temp -> next;
    }
    if (count > max)
      max = count;
  }

  for (int i = 0; i < g->n; i++) {
    count = 0;
    struct element *temp = g->A[i];
    while (temp != NULL) {
      count++;
      temp = temp -> next;
    }
    if (count == max)
      printf("%c", 'A'+i);
  }
  printf("\n");
  return;
}


int main( int argc, char *argv[]){      // Il main non può essere modificato a sua detta :(
  Graph g = read();
  //printGraph(g);
  char c;
  scanf( " %c", &c );
  followers(g,c);
  max(g);
  return 0;
}