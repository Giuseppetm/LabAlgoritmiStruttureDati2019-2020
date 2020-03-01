#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
int main(void) {
     char token[10];
     while (scanf("%s", token) != EOF) {
          if (isdigit(token[0])) {
               printf("%s ", token);
          } else {
               switch (token[0]) {
               case '(':
                    break;
               case ')':
                    printf("%c ", pop());
                    break;
               case '+':
               case '-':
               case '*':
               case '/':
                    push(token[0]);
                    break;
               }
          }
     }
}