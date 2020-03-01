// Palindrome con argomenti da linea di comando
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool palindroma(char *s);
int main( int argc, char *argv[]  ) {
    // argc numero di argomenti, argv array di stringhe
    if (palindroma(argv[1])) {
        printf("palindroma");
    } else {
        printf("not palindroma");
    }
    return 0;
}

bool palindroma(char *s) {  // Passi l'indirizzo del primo carattere
    int len = strlen(s);
    bool check = true;
    char *sx, *dx;
    sx = s;
    dx = len + s -1;
    
    while (check == true && sx < dx) {
        if (*sx != *dx) {
            check = false;
            break;
        }
        sx++;
        dx--;
    }
    return check;
}

/*
1. Scrivete una funzione che stabilisca se il suo argomento è una parola palindroma oppure no,
usando due puntatori per scorrere la parola partendo dall’inizio e dalla fine.
Nota bene. Come va dichiarato l’argomento della funzione? Come vanno dichiarati i due 
puntatori? Osservate a che cosa puntano...
2. Scrivete un programma che riceve una parola come argomento da linea di comando, quindi invoca la
funzione appena scritta per stabilire se si tratta di una parola palindroma oppure no.
3. Modificate il proramma affinché riceva da linea di comando una sequenza di parole e stabilisca, per
ciascuna di esse, se si tratta di una parola palindroma oppure no.
*/