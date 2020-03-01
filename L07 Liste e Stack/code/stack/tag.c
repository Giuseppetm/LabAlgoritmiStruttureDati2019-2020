#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main(void) {
     char token[10];
     while (scanf("%s", token) != EOF) {
          if (token[1] != '/') {
               push(token[1]);
          } else {
               if (token[2] != pop()) {
               printf("Non ben formattato.\n");
               return 0;
            }
        }
    }
    printf("Ben formattato.\n");
    make_empty();
    return 0;
}