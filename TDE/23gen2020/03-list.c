#include <stdio.h>
#include <stdlib.h>
  
struct node {   
  int info;   
  struct node *next;
};
                    
typedef struct node *Node;

Node new_node(int n) {
     Node p = malloc(sizeof(struct node));
     p->info = n;
     p->next = NULL;
     return p;
}

void list_print(Node list) {
     Node temp = list;
     while (temp != NULL) {
          printf("%d ", temp->info);
          temp = temp -> next;
     }
     printf("\n");
     return;
}

// Si chiede di scrivere una funzione che inserisca in testa alla lista un nuovo nodo, e restituisca la lista ottenuta.
Node list_insert(Node list, Node new) { 
  new -> next = list;
  return new; 
}

// Si chiede di scrivere una funzione che effettua il reverse della lista, senza l'utilizzo di memoria aggiuntiva
Node list_reverse(Node list) {
     Node curr = list;
     Node prev = NULL;
     Node next = list->next;

     while (curr != NULL) {
          curr->next = prev;
          prev = curr;
          curr = next;

          if (next != NULL) {
               next = next -> next;
          }
     }
     return prev;
}



int main(void) {
     Node list = new_node(6);
     
     Node p1 = new_node(5);
     Node p2 = new_node(7);
     Node p3 = new_node(8);
     Node p4 = new_node(1);
     Node p5 = new_node(2);

     list = list_insert(list, p1);
     list = list_insert(list, p2);
     list = list_insert(list, p3);
     list = list_insert(list, p4);
     list = list_insert(list, p5);
     list_print(list);

     Node reversedList = list_reverse(list);
     list_print(reversedList);
     return 0;
}