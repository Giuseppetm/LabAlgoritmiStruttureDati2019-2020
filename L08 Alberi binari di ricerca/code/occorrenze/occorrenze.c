#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "item.h"
#define WORD "STOP"

/*
typedef struct{
    char *s;
    int rep;
}Item;
*/

struct node{
    Item item;
    struct node *l, *r;
};
typedef struct node *Node;

Item newItem(char *s){
    char *s2 = (char*)malloc(sizeof(char) * 256);
    strcpy(s2, s);
    Item res = {s2, 1};
    return res;
}

void printItem(Item i){
    printf("<%s, %d>\n", i.s, i.rep);
}

Node newNode(Item item, Node l, Node r){
    Node result = malloc(sizeof(struct node));
    result -> item = item;
    result -> l = l;
    result -> r = r;
    return result;
}

void insertInOrder(Node *tree, Item new){
    if(*tree == NULL){
        *tree = newNode(new, NULL, NULL);
        return;
    }
    int comp = strcmp(new.s,(*tree)->item.s);

    if(comp == 0){
        (*tree)->item.rep++;
        return;
    }
    if(comp < 0){
        insertInOrder(&((*tree)->l),new);
        return;
    }
    if(comp > 0){
        insertInOrder(&((*tree)->r),new);
        return;
    }
}

void printInOrder(Node tree){
    if(tree->l == NULL){
        printItem(tree->item);
        if(tree->r != NULL){
            printInOrder(tree->r);
        }
    }else{
        printInOrder(tree->l);
        printItem(tree->item);
        if(tree->r != NULL){
            printInOrder(tree->r);
        }
    }
}

void printInvertedOrder(Node tree){
    if(tree->r == NULL){
        printItem(tree->item);
        if(tree->l != NULL){
            printInvertedOrder(tree->l);
        }
    }else{
        printInvertedOrder(tree->r);
        printItem(tree->item);
        if(tree->l != NULL){
            printInvertedOrder(tree->l);
        }
    }
}

int main(void) {
    Node root = NULL;
    char *s = malloc(256 * sizeof(char *));

    scanf("%s", s);
    while( strcmp(s,WORD) != 0 ) {
        insertInOrder(&root, newItem(s));
        scanf("%s", s);
    }

    //printInOrder(root);
    //printInvertedOrder(root);
}