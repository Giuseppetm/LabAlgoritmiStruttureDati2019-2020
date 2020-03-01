#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define L 1

char *read_line( char c ) { // deve leggere una riga terminata dal carattere c;
    char *s;
    int i = 0, size = L;
    s = malloc(size * sizeof(char));
    if (s == NULL) {
        return NULL;
    }
    while( (*(s+i) = getchar()) != c ) {
        i++;        // dato che hai già assegnato, incrementi subito i
        if (i >= size) {
            size *= 2;
            s = realloc(s, size * sizeof(char));
        }
    }
    return s;
}

char *read_word( void ) {
// deve leggere una parola di caratteri alfanumerici 
//(la lettura deve interrompersi al primo carattere non alfanumerico; se il primo carattere letto non è alfanumerico, la stringa restituita sarà la stringa vuota).
    char *s;
    int i = 0, size = L;
    s = malloc(size * sizeof(char));
    if (s == NULL) {
        return NULL;
    }
    getchar();  // mangio l'a capo di prima
    printf("insert characters(senza andare a capo): ");
    while(isalnum(*(s + i) = getchar())) {
        printf("bovghese");
        i++;        // dato che hai già assegnato, incrementi subito i
        if (i >= size) {
            size *= 2;
            s = realloc(s, size * sizeof(char));
        }
    }
    *(s+i) = '\0';     // stringa terminata
    return s;
} 

int main(void) {
    char c;
    printf("read line function:\n");
    printf("insert character until to read: ");
    scanf("%c", &c);
    char *s = read_line(c);

    // Stampo finché non arriva c
    int i = 0;
    while (*(s+i) != c) {
        printf("%c",*(s+i));
        i++;
    }
    
    printf("read word function:");
    char *s2 = read_word();
    return 0;
}
/*
Scrivete due funzioni che leggano da standard input una sequenza di caratteri e la memorizzino in una stringa di dimensione
opportuna allocata dinamicamente (scegliete la strategia che preferite, ad esempio una di quelle proposte
nell’esercizio precedente):
1. char *read_line( char c ) deve leggere una riga terminata dal carattere c;
2. char *read_word( void ) deve leggere una parola di caratteri alfanumerici (la lettura deve interrompersi al
primo carattere non alfanumerico; se il primo carattere letto non è alfanumerico, la stringa restituita sarà la stringa
vuota).
Entrambe le funzioni devono restituire l’indirizzo del primo carattere della stringa memorizzata o il puntatore NULL in
caso di errore.
*/