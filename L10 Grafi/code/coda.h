#ifndef CODA_H
#define CODA_H
#include <stdbool.h>
struct node {
    int info;
    struct node *next;
};
typedef struct node *Node;

struct coda {
     Node primo, ultimo;
     int size;
};
typedef struct coda *Coda;

Coda new_coda();  
Node new_node(int n);
bool isEmpty(Coda c);
void enQueue(Coda c, int n); 
int deQueue(Coda c);
int first(Coda c);
void printCoda(Coda c);
void destroyCoda(Coda c);

#endif