/*
Il programma conterrà:
 funzioni per la gestione degli Item
 funzioni per la gestione delle catene di collisione
 funzioni per la gestione della tabella di hash
 funzioni per la lettura delle parole e delle righe
 la funzione main
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define HASHSIZE 400

typedef struct {
     char *word;
     int *ln_arr;   // Righe in cui compare la parola
     int ln_dim;
     int ln_realloc_size;
} Item;

struct element {
     Item *item;
     struct element *next;
};
typedef struct element *Chain;

typedef struct ht {
     Chain array[HASHSIZE];
     int count; // parole inserite
} *Dict;

/* deve allocare lo spazio per un nuovo Item e restituirne l’indirizzo 
dopo averlo inizializzato con la chiave w e il numero di riga ln. */
Item *item_new( char *w, int ln ) {
     Item *newItem = calloc(1, sizeof(Item));
     if (newItem == NULL) {
          printf("Errore di allocazione.");
          exit(-1);
     }
     newItem -> word = malloc(sizeof(char *));
     newItem -> ln_arr = malloc(sizeof(int *));
     newItem -> word = w;
     newItem -> ln_arr[0] = ln;
     newItem -> ln_dim = 1;
     newItem -> ln_realloc_size = 10;  // Scelgo 10 per riallocare
     return newItem;
}    // Testato, OK

/* basta che la funzione di modifica sia in grado
di aggiungere un nuovo numero di riga ln al vettore ln_arr, 
riallocandolo opportunamente se necessario */
void item_modify( Item *p, int ln ) {
     if (p->ln_dim == p->ln_realloc_size) {
          p->ln_realloc_size *= 2;
          p->ln_arr = realloc(p->ln_arr, p->ln_realloc_size*sizeof(int));
     }
     p -> ln_arr[p->ln_dim] = ln;
     p->ln_dim++;
     return;
}

/* Cerca nella catena un Item con chiave w e ne restituisce il puntatore
oppure NULL se w non è nella catena. */
Item *chain_find( Chain c, char *w) {
     for (Chain temp = c; temp != NULL; temp = temp -> next) {
          if (strcmp(temp->item->word, w) == 0)
               return temp->item;
     }
     return NULL;
}

/* Crea un nuovo elemento contenente l'Item puntato da p, lo inserisce
in testa alla catena e restituisce l'indirizzo della nuova testa. */
Chain chain_insert( Chain c, Item *p ) {    
     Chain new = calloc(1, sizeof(struct element));
     new -> item = p;
     // Quando inserisco per la prima volta, creo la catena
     if (c == NULL) {
          // Se c è vuota, new non ha elem. successivo
          new -> next = NULL;
          return new;
     }
     // Se c era una catena con già elementi all'interno
     // la concateno a new
     new -> next = c;
     return new;
}

// Stampa gli elementi della catena
void chain_print( Chain c ) {
     printf("Stampa catena: ");
     Chain temp = NULL;
     for (temp = c; temp != NULL; temp = temp->next)
          printf("%s ", temp->item->word);
     printf("\n");
     return;
} 

// Funzione di hash
unsigned long hash( char *str ) {
     unsigned long hash = 5381;
     int c;
     while ( (c = *str ++) )
     hash = (( hash << 5) + hash) + c; /* hash * 33 + c */
     return hash % HASHSIZE;
}

/* alloca lo spazio per il dizionario e inizializza i suoi membri; in particolare 
ricordate di assegnare a NULL tutti gli elementi del vettore. */
Dict dict_init() {
     Dict t = calloc(1, sizeof(struct ht));
     if (t == NULL) {
          printf("Errore di allocazione.\n");
          exit(-1);
     }
     t -> count = 0;
     for (int i=0; i < HASHSIZE; i++) {
          t->array[i] = NULL;
     }
     return t;
}

// La funzione dict_lookup restituisce l’Item contenente la chiave w, oppure NULL se w non è nel dizionario.
Item *dict_lookup( Dict t, char *w ) {
     Item *found;
     unsigned long hashValue = hash(w);
     found = chain_find(t->array[hashValue], w);
     if (found != NULL)
          return found;
     return NULL;
}

// La funzione dict_add aggiunge l’Item nel dizionario assumendo che la chiave p -> w non ci sia già.
void dict_add( Dict t, Item *p ) {
     unsigned long hashValue = hash(p->word);
     t->array[hashValue] = chain_insert(t->array[hashValue], p);
     t->count++;
     return;
}

/* - se w è già presente nel dizionario, ma non è ancora comparsa nella riga corrente, bisogna modificare il relativo
Item aggiungendo il numero di riga corrente a quelli già presenti;
- se w non è già presente nel dizionario, bisogna aggiungerla, con la riga corrente.  */
void dict_insert(Dict t, Item *p, int ln) {
     Item *found = dict_lookup(t,p->word);
     if ( found == NULL ) {  // Non è presente
          dict_add(t, p);
          return;
     } else {
          item_modify(p, ln);
     }
}

// stampa il contenuto del dizionario.
void dict_print( Dict t ) {
     for (int i = 0; i < HASHSIZE; i++)
          if (t->array[i] != NULL)
               chain_print(t->array[i]);
     return;
}

/* Per implementare il comando di lettura delle righe è necessario innanzitutto dividuare le singole parole che compaiono
nella riga e cercarle nel dizionario.*/
void line( Dict t, int ln ) {
     char c;
     while(1) {
          char *dennis = calloc(1, 256 * sizeof(char));
          scanf("%s", dennis);
          Item *p = item_new(dennis, ln);
          dict_insert(t, p, ln);
          
          scanf("%c", &c);
          if (c == '\n') {
               break;
          } else if (c == ' ') {
               continue;
          }
     }
     return;
}

int main(void) {
     Dict dict = dict_init();
     char command, *stringTemp;
     int ln = 0;
     while( (command = getchar()) != 'f') {
          switch(command) {
               case '+': // legge una riga e inserisce parole in dict
               ln++;
               line( dict , ln );            // DA RISOLVERE: NON INSERIRE STESSA STRINGA, SE È LA STESSA NON INSERISCI
               break;

               case '?': // stampa num di riga in cui compare la parola
               stringTemp = malloc(256 * sizeof(char));
               scanf("%s", stringTemp);
               Item *found = dict_lookup(dict, stringTemp);
               if (found != NULL) {
                    printf("%s: ", found->word);
                    for (int i=0; i < found->ln_dim; i++)
                         printf("%d ", found->ln_arr[i]);
                    printf("\n");
               } else {
                    printf("%s NOT FOUND\n", stringTemp);
               }
               break;

               case 'n': // stampa il numero di parole lette
               printf("Lette %d parole distintamente\n", dict->count);
               break;
               
               case 'l': // stampa il numero di righe lette
               printf("Lette %d righe\n", ln);
               break;

               case 'p': // stampa il dizionario
               dict_print(dict);
               break;
          }
    }
    return 0;
}