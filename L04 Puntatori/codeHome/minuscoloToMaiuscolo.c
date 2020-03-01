#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LENGTH 100
char *maiuscolo( char *stringa );
int main() {
    char s[LENGTH];
    char *c = s;

    while ( (*c = getchar()) != '\n')
        c++;

    maiuscolo(s);
    printf("%s\n", s);
    return 0;
}

char *maiuscolo( char *stringa ) {
    int len = strlen(stringa);
    for (int i=0; i < len; i++) {
        stringa[i] = toupper(stringa[i]);
    }
    return stringa;
}
/*1. Scrivete una funzione con prototipo char *maiuscolo( char *stringa ) che trasformi 
da minuscolo in maiuscolo tutte le lettere del suo argomento stringa e ne restituisca 
un puntatore al primo carattere.
Potete assumere che stringa sia dato da una stringa terminata da ’\0’ contenente caratteri 
ASCII (non solo lettere). Potete usare la funzione toupper della libreria ctype.h.
2. Testate la funzione inserendola in un programma che legga da standard input una frase 
terminata da a-capo,
la memorizzi in una stringa s, invochi la funzione, quindi ristampi la frase tutta in 
maiuscolo.
3. Come avete dichiarato s? Spiegate perché.
4. Spiegate se c’è differenza, e se sì quale, tra le seguenti dichiarazioni per la funzione 
maiuscolo:
char *maiuscolo( char *stringa )
char *maiuscolo( char stringa[] )
*/