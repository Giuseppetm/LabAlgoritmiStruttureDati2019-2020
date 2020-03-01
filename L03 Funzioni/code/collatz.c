#include <stdio.h>
void collatz(int n);
int main() {
    int n;
    printf("insert n: ");
    scanf("%d",&n);
    collatz(n);
}

void collatz(int n) {
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n *= 3;
            n++;
        }
        printf("%d ", n);
    }
    printf("\n");
}



/*
Considerate la seguente regola: dato un numero intero positivo n, se n è pari lo si divide per 2, se è dispari lo si
moltiplica per 3 e si aggiunge 1 al risultato. Quando n è 1 ci si ferma.
Questa semplice regola permette di costruire delle sequenze: la sequenza che si costruisce a partire dal numero
n è detta sequenza di Collatz di n. Ad esempio, la sequenza di Collatz di 7 è:
7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
E’ un noto problema aperto stabilire se ogni sequenza di Collatz termina (cioè, se arriva a 1).
Scrivete innanzitutto una funzione che, dato un numero, dia il successivo in una sequenza di Collatz. Quindi,
inseritela in un programma che chiede all’utente un numero e mostra la sequenza di Collatz del numero (con
tanto di lunghezza).
Esempi di funzionamento
Numero: 7
7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Lunghezza: 17
Numero: 9
9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Lunghezza: 20
*/