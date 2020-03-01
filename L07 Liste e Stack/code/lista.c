/* Considerate il codice contenuto nel file lista.c. 
Il codice contiene la definizione del tipo Node, usato per implementare
una lista concatenata. La funzione main crea una lista di due nodi, 
memorizzando l’indirizzo del primo nodo della lista
nella variabile head. */

#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int val;
};

typedef struct node *Node;

Node newNode( int val, Node p );
int f1 ( Node p );
Node f2 ( Node p );
Node f3 ( Node p, Node q );

int main(){
	Node x = newNode( 1, NULL );
	Node head = newNode( 2, x );
}


Node newNode( int val, Node p ){
	Node new = malloc( sizeof (struct node));
	new -> val = val;
	new -> next = p;
	return new;
}

int f1 ( Node p ){
	getchar();
	if ( p -> next == NULL )
		return 1;
	else
		if ( p -> val < p -> next -> val )
			return 0;
		else
			return f1( p -> next );
}

Node f2 ( Node p ){
	getchar();
	if (  p -> next == NULL ) 
		return p;
	else 
		return f3( p -> next, p );
}


Node f3 ( Node p, Node q ){
	Node temp;
	if ( p -> val < q -> val )
		temp = p;
	else
		temp = q;
	if ( p -> next == NULL )
		return temp;
	else 
		return f3( p -> next, temp );
	
}
/*
Si immagini di eseguire la funzione f1 sulla lista nella figura sopra e si risponda alle domande seguenti.
1. Quale valore restituisce la funzione se invocata sul nodo con val pari a 1?
return 1

2. Se si invoca f1(head), quale delle seguenti affermazioni è corretta? Si giustifichi la risposta.
(a) La funzione f1 viene chiamata su entrambi i nodi della lista e restituisce su entrambi il valore 0.
FALSO

(b) La funzione f1 viene chiamata su entrambi i nodi della lista e restituisce sul primo il valore 0 e sul secondo
il valore 1.
FALSO

(c) La funzione f1 viene chiamata su entrambi i nodi della lista e restituisce su entrambi il valore 1.
VERO

(d) La funzione f1 viene chiamata soltanto sul nodo con val pari a 2 e restituisce 0.
FALSO

(e) La funzione f1 viene chiamata soltanto sul nodo con dato 2 e restituisce 1.
FALSO

3. Completate la frase seguente:
Se head è il puntatore alla testa di una lista qualsiasi formata da almeno 2 nodi, allora la chiamata
f1(head) restituisce 1 se e solo se..   VAL(primo nodo) < VAL(secondo nodo)
Considerate ora le funzioni f2 e f3:
4. Se la funzione f2 viene eseguita sulla lista mostrata nella figura sopra, tramite l’invocazione f2(head), cosa
restituisce?
1

5. Si completi la frase seguente:
Se head è il puntatore alla testa di una lista qualsiasi formata da almeno 2 nodi, allora la chiamata
f2(head) restituisce un puntatore a . . .
*/