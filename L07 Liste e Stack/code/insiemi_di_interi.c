#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
     int info;
     struct node *next;
};

typedef struct node *Node;

bool present( Node l, int n );
void insert( Node *l, int n );
void delete(struct node **l, int n);
void printList(Node l);
void printListInverted( Node l );
void list_delete(Node l);

int main(void) {
     char c;
     int n, count = 0;
     Node head = NULL;     // Indica l'inizio della lista che rappresenta l'insieme
     while ( (c = getchar()) != 'f') {
          switch (c) {
               // Insert
               case '+':
               scanf("%d",&n);
               insert(&head,n);
               count++;
               break;

               // Delete
               case '-':
               scanf("%d",&n);
               if (present(head,n)) {
                    count--;
                    delete(&head,n);
               } else {
                    printf("Elemento non presente\n");
               }
               break;

               // Appartiene
               case '?':
               scanf("%d", &n);
               if (present(head,n)) {
                    printf("n appartiene all'insieme\n");
               } else {
                    printf("n non appartiene all'insieme\n");
               }
               break;

               // Stampa num. di elementi
               case 'c':
               printf("%d\n", count);
               break;

               // Stampa elementi dell'insieme
               case 'p':
               printList(head);
               break;

               // Stampa elementi dell'insieme al contrario
               case 'o':
               printListInverted(head);
               break;

               // Cancella tutti gli elementi dell'insieme
               case 'd':
               list_delete(head);
               printf("Elementi dell'insieme cancellati\n");
               break;
          }
     }
}

bool present( Node l, int n ) {
     Node current = l;
     while (current != NULL) {
          if (current->info == n) {
               return true;
          }
          current = current->next;
     }
     return false;
}

void insert( Node *l, int n ) {
     if (!present(*l,n)) {
          Node new = malloc(sizeof(struct node)); //Non si può usare Node nella sizeof altrimenti sballa il conto
          new->info = n;
          new->next = *l;
          *l = new;
     }
}

void delete(struct node **l, int n) {
    struct node *curr, *prev;
    for (curr = *l, prev = NULL; curr != NULL; prev = curr, curr = curr->next) {
        if (curr->info == n)
            break;
    }
    if (curr == NULL) //Elemento da cancellare non presente
        return;
    if (prev == NULL) //Elemento da cancellare al primo posto
        *l = (*l)->next;
    else //Elemento da cancellare presente e non al primo posto
        prev->next = curr->next;
    free(curr);
}

void printList(Node l) {
     while (l != NULL) {
          printf("%d\n", l->info);
          l = l->next;
     }
     return;
}

void printListInverted( Node l ) {
     if (l == NULL) {
          return;
     }
     if (l->next == NULL) {
          printf("%d\n", l->info);
          return;
     }
     printListInverted(l->next);
     printf("%d\n", l->info);
     return;
}

void list_delete(Node l) {
     Node tmp;
     while (l != NULL) {
        tmp = l;
        l = l->next;
        free(tmp);
     }
    return;
}