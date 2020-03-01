#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
int main(void) {
     char token[10]; // Si presuppone che i numeri abbiano al massimo 10 cifre
     int v1,v2;
     while (scanf("%s", token) != EOF) {
          if (isdigit(token[0])) { // Caso token = numero
               push(atoi(token));
          } else {       // Caso token = operatore
               v1 = pop();
               v2 = pop();
               switch (token[0]) {
                    case '+':
                    push(v1+v2);
                    break;
                    case '-':
                    push(v1-v2);
                    break;
                    case '*':
                    push(v1*v2);
                    break;
                    case '/':
                    push(v1/v2);
                    break;
               }
          }
     }
     printf("result: %d\n", pop());
     make_empty();
     return 0; 
}