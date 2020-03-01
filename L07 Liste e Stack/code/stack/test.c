#include "stack.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
     Item item, toplist;
     char c;
     while ( (c = getchar() ) !=  'f') {
          switch (c) {
               case '+':      // Push
               scanf("%d", &item);
               push(item);
               break;

               case '-':      // Pop
               item = pop();
               printf("Popped %d\n", item);
               break;

               case 't':      // Top
               toplist = top();
               printf("%d\n", toplist);
               break;

               case 'p':      // Print
               print_stack();
               break;

               case 'm':      // Make empty
               make_empty();
               break;

               case '?':      // Is empty
               if (is_empty() == 0) {
                    printf("empty\n");
               } else {
                    printf("not empty\n");
               }
               break;
          }
     }
}