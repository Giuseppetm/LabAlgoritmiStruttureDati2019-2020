#include <stdio.h>
#include <stdlib.h>
  
struct node {   
  int info;   
  struct node *next;
};
                    
typedef struct node *Node;


Node list_insert(int n, Node l) {       // struct node *list_insert( int n, struct node *l )
  Node new = malloc(sizeof(struct node));     // struct node *new = malloc(sizeof(struct node));
  new -> info = n;    // (pointer_name)->(variable_name); quando hai un puntatore a struct non puoi usare il . per accedere ai campi
  new -> next = l;
  return new; 
}

/*
Node list_insert(int n, Node *l) {    
  Node new = malloc(sizeof(struct node));    
  new -> info = n;  
  new -> next = l;
  *l = new;
}
*/

Node list_search( int n, Node l) {    // struct node *list_search( int n, struct node *l )
  /*while ( l != NULL && l -> info != n )
    l = l -> next;
  return l; */

    // Versione for
    for (Node p = l; p != NULL; p = p-> next) {
      if (p->info == n) {
        return p;
      }
    }
  return NULL;
}

// Versione ricorsiva di list_search
Node list_search_ric(int n, Node l) {
  if (l != NULL) {
    if (l->info == n) {
      return l;
    } else {
      return list_search_ric(n, l->next);
    }
  }
  return NULL;
}

/*
1. Completate la riga 7 dimensionando opportunamento lo spazio richiesto tramite la malloc.
k

2. Usate la typedef per definire un nuovo tipo Node, puntatore a struct node. Riscrivete le righe 6, 7 e 13 usando
il nuovo tipo Node.
k

3. Cosa succede quanto la funzione list_insert viene invocata con NULL come secondo argomento?
Avrà come puntatore a next NULL, quindi sarà l'ultimo in teoria.

4. Senza eseguirlo al computer, tracciate l’esecuzione della funzione list_search quando riceve come argomenti il
numero 7 e l’indirizzo del terzo nodo della lista nella figura sotto.

5. Riscrivete la funzione list_search usando un ciclo for invece che un ciclo while.
k

6. Cosa restituisce la funzione list_search se il valore passato come primo argomento è contenuto in più di un
nodo?
Il primo nodo che contiene l'argomento.

7. Scrivete una funzione ricorsiva list_search_rec che cerchi un elemento all’interno di una lista.
k

8. Notate che l’istruzione alla riga 10 è necessaria poiché la funzione modifica la testa della lista; pertanto quando si
invoca list_insert è necessario aggiornare la testa della lista con un assegnamento del tipo
list = list_insert( 3, list );
Riscrivete la funzione list_insert in modo che modifichi direttamente il puntatore alla testa della lista passata
come argomento. Per farlo è opportuno passare tale puntatore per riferimento, quindi il secondo argomento passato
alla funzione deve essere l’indirizzo del puntatore in cui è memorizzato l’indirizzo del primo elemento della lista.

k

 */