#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct element {  // definizione di un elemento della lista
  char ch;
  struct element *next;    // prossimo elemento
};

typedef struct queue {
  struct element *head;
  struct element *tail;
  int count;
} *Queue;


Queue init();
void enqueue(char ch, Queue q);
char dequeue(Queue q); // assume che la coda non sia vuota

// inserite qui la funzione extract e eventuali altre funzioni aggiuntive
void extract(Queue q) {
  char ch;
  while (q->count > 0) {
    ch = dequeue(q);
    printf("%c", ch);
  }
}

int main( int argc, char **argv ) {
  // Coda struttura FIFO
  Queue q, v, c, s;

  char param = argv[1][0]; // riceve da linea di comando un parametro, che può essere S, V, oppure C;

  // lettura delle lettere e inserimento nella coda q
  q = init();
  char ch;
  int n = 0;
  while ( (ch = getchar() ) != '\n' ) {
    enqueue(ch,q); 
    n++;
  }

  // estrazione dalla coda e distribuzione delle lettere nelle code v,c,s
  v = init();
  c = init();
  s = init();
  for (int i=0; i < n; i++) {
    ch = dequeue(q);
    /* estrae le lettere, in ordine, dalla coda q e le distribuisce in altre tre code s, v e c, contenenti rispettivamente:
    le lettere straniere,
    le vocali italiane,
    le consonanti italiane; */
    switch(tolower(ch)) {
      // Le lettere straniere sono classificate nel seguente ordine: J - K - W - X - Y
      case 'j':
      case 'k':
      case 'w':
      case 'x':
      case 'y':
      enqueue(ch, s);
      break;

      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      enqueue(ch, v);
      break;

      // Le consonanti decido di sistemarle come caso default in quanto sono le più frequenti
      default:
      enqueue(ch, c);
    }
  }

  // stampa della coda opportuna
  switch(param) {
    case 'V': extract(v);
      break;
    case 'C': extract(c);
      break;
    case 'S': extract(s);
      break;
  }
  
  printf("\n");
  return 0;
}

Queue init(){
  Queue q = malloc(sizeof(struct queue));
  q->head = NULL;
  q->count = 0;
  return q;
}

void enqueue(char ch, Queue q){
  struct element *new = malloc(sizeof(struct element));
  new->ch = ch;
  new->next = NULL;
  if (q->head == NULL)
    q->head = new; // la coda era vuota
  else {
    q->tail->next = new; // attacco in coda
  }
  q->tail = new;
  q->count++;
}

// assumo che la coda non sia vuota
char dequeue(Queue q){
  char ch;
  struct element *testa = q->head;
  ch = testa->ch;
  q->head = q->head->next;
  free(testa);
  q->count--;
  return ch;
}