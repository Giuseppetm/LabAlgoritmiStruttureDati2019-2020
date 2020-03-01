#include <stdio.h>
#include <string.h>
typedef char * String;
int smallest_word_index(String s[], int n );
String *smallest_word_address( String s[], int n );
int main() {
    String s[] = { "ciao", "mondo", "come", "funziona", "bene", "il", "programma" };
    int lun = 7, indice;

    indice = smallest_word_index(s,lun);
    printf("Indice trovato: %d\n", indice);
    printf("Indirizzo relativo: %d\n", smallest_word_address(s,lun));
    return 0;
}

int smallest_word_index(String s[], int n ) {
    // Vuole l'indice della parola "più piccola"
    int val,k;
    for (int i=1; i < n; i++) {
        val = strcmp(s[i],s[i-1]);
        if (val < 0) {
            k = i;
        }
    }
    return k;
}

String *smallest_word_address( String s[], int n ) {
    // restituisca l’indirizzo dell’elemento più piccolo dell’array (sempre secondo l’ordine alfabetico).
    int val;
    String *k;
    for (int i=1; i < n; i++) {
        val = strcmp(s[i],s[i-1]);
        if (val < 0) {
            k = s+i;
        }
    }
    return k;
}
/*
1. Scrivete una funzione con prototipo int smallest_word_index( char *s[], int n ) che, dato un
array s lungo n di stringhe, restituisca l’indice della parola più piccola (secondo l’ordine alfabetico)
contenuta nell’array.
Per effettuare confronti tra stringhe, potete usare la funzione strcmp dal file di intestazione string.h.
2. Definite usando typedef un nuovo tipo String sinonimo di char * e modificate il programma usando
String ovunque sia opportuno.
3. Partendo dala funzione smallest_word_index scrivete una nuova funzione con prototipo
String *smallest_word_address( String s[], int n )
che, dato un array s di n stringhe, restituisca l’indirizzo dell’elemento più piccolo dell’array (sempre
secondo l’ordine alfabetico).
Suggerimento: riguardate l’esercizio “Puntatore al minimo” e osservate le somiglianze tra i prototipi delle
funzioni smallest e smallest_word_address.
4. Riscrivete il prototipo della funzione smallest_word_address senza usare il tipo String.
*/