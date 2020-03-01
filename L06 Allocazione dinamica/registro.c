/* L’obiettivo dell’esercizio è scrivere un programma per gestire un registro di prenotazione di posti numerati da 0 a n-1.
Il valore di n (numero dei posti prenotabili) è inserito dall’utente all’atto della creazione del registro. Un cliente è
identificato da una stringa. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LEN 100
char **newBook(int n);
bool book(int k, char *name, char **book);
bool cancel(int k, char **book);
bool move(int from, int to, char **book);
void printBook(char **book, int n);
int main(void) {
     char c;
     char word[LEN];          // forse c'è un modo migliore
     int n, k, f, t;
     char **reg;
     while( ( c = getchar () ) != 'f' ) {
          switch(c){

               case 'b': // b n --> newBook(n)
               scanf("%d", &n);
               reg = newBook(n);
               break;

               case '+': // + k name --> book(k, name)
               scanf("%d %s", &k, word);
               if (!book(k,word,reg)) {
                    printf("book(%d,%s): errore\n", k, word);
               }
               break;

               case '-': // - k --> cancel(k)
               scanf("%d", &k);
               if (!cancel(k,reg)) {
                    printf("cancel(%d):errore\n", k);
               }
               break;

               case 'm': // m from to ---> move from to
               scanf("%d %d", &f, &t);
               if (!move(f,t,reg)) {
                    printf("move(%d,%d): errore\n", f, t);
               }
               break;

               case 'p': // p ---> printBook()
               printBook(reg,n);
               break;
          }
     }
     return 0;
}

/* Crea un nuovo registro che permetta la prenotazione di n posti, da 0 a n - 1. Se esiste già un registro di
prenotazione, quest’ultimo deve essere cancellato. */
char **newBook(int n) {  // Poi serve il vecchio book da rimpiazzare quindi secondo parametro
     // Penso che il registro sia un vettore di stringhe da 0 a n-1. Ogni posizione contiene una stringa associata al nome string del cliente
     // Associo n spazi in memoria per questo array di stringhe (ogni stringa è un char *)
     char **newBook;
     newBook = malloc(n * sizeof(char *));
     return newBook;
}

/* Se il posto k è libero, prenota il posto k per il cliente identificato da name. Altrimenti, stampa un messaggio di
errore. */
bool book(int k, char *name, char **book) {
     if (book[k] != NULL) {
          return false;       // Non è andata a buon fine. Il posto è già occupato
     }
     book[k] = malloc( (strlen(name)+1) * sizeof(char) );
     strcpy(book[k], name);
     return true;
}

// Se il posto k è occupato, cancella la prenotazione di k. Altrimenti, stampa un messaggio di errore.
bool cancel(int k, char **book) {
     if (book[k] != NULL) {   // se è occupato libero lo spazio
          free(book[k]);
          book[k] = NULL;     // e dico che c'è null in quello spazio in modo da far capire alle altre funzioni che è libero
          return true;
     }
     return false;
}

/* Sposta il cliente dal posto from al posto to se ciò è possibile (ossia from occupato e to libero). Altrimenti,
stampa un messaggio di errore. */
bool move(int from, int to, char **book) {
     if (book[from] == NULL || book[to] != NULL) {     // devono essere entrambi liberi per poter spostare
        return false;
     }

     book[to] = book[from];
     book[from] = NULL;
     return true;
}

// Stampa il contenuto del registro (posti prenotati).
void printBook(char **book, int n) {
     printf("REGISTER[0..%d]:\n",n-1);
     for (int i=0; i < n; i++) {
          if (book[i] != NULL) {
               printf("%d --> %s\n", i, book[i]);
          }
     }
     return;
}

/*

Notate che l’implementazione in C delle precedenti operazioni di alto livello può richiedere l’uso di parametri in più
rispetto a quelli indicati. Riflettete quindi su quali siano i prototipi più opportuni da implementare! 

Struttura dati:

Per rappresentare il registro occorre usare un array book allocato dinamicamente in quanto la dimensione è stabilita
durante l’esecuzione del programma.
Sia n la dimensione di book. Allora, in ogni istante del programma per ogni 0 <= k < n deve valere la seguente proprietà:
- Se il posto k è prenotato da w, allora book[k] è l’indirizzo a un vettore contenente w.
- Altrimenti, book[k] vale NULL (indirizzo 0).
Anche se avete la tentazione di definire book come una variabile globale, provate a definirla nel main e a passarla come
argomento alle varie funzioni.

Formato di input e output
Il programma deve leggere da standard input una sequenza di istruzioni secondo il formato nella tabella, dove k, n, f rom
e to sono interi e name una parola.

Riga di input            Operazione
b n                      newBook (n)
+ k                      name book(k;name)
- k                      cancel(k)
m from to                move( f rom; to)
p                        printBook()
f                        Termina l’esecuzione

I vari elementi sulla riga sono separati da uno o più spazi. Quando una riga è letta, viene eseguita l’operazione associata;
le operazioni di stampa sono effettuate sullo standard output, e ogni operazione deve iniziare su una nuova riga.
Si assume che l’input sia inserito correttamente. Conviene scrivere le istruzioni di input in un file in.txt ed eseguire il
programma redirigendo lo standard input.

La lettura e l’interpretazione dei comandi può essere gestita con un ciclo contenente uno switch:
while( ( c = getchar () ) != ’f’ ){
switch(c){
case ’b’: // b n --> newBook(n)
// ...
break;
case ’+’: // + k name --> book(k, name)
//...
break;
case ’-’: // - k --> cancel(k)
// ...
break;
case ’m’: // m from to ---> move from to
// ..
break;
case ’p’: // p ---> printBook()
// ...
break;
}
}

*/