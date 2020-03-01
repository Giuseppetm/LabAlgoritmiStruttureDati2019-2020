#include <stdio.h>
#include <stdbool.h>
bool primo(int n);
int main() {
    int n;
    printf("insert n: ");
    scanf("%d", &n);
    if (primo(n)) {
        printf("primo");
    } else {
        printf("non primo");
    }
}

bool primo(int n) {
    for (int i=2; i < n; i++) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

/*
Scrivete una funzione con parametro un intero n che stabilisca se n è un numero primo. Scrivete la funzione
partendo dal programma che avete scritto per l’esercizio 5 della scheda “L01-lab”.
*/