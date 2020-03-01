#include <string.h>
#include <stdio.h>
void farfallino(char *s);
int main(int argc, char **argv) {
    for (int i=1; i < argc; i++) {
        farfallino(argv[i]);
    }
}

void farfallino(char *s) {
    char *p;
    int len = strlen(s);
    for (p=s; p < s + len; p++) {
        switch (*p) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            printf("f%cf",*p);
            break;
            default: // consonante
            printf("%c",*p);
            break;
        }
    }
    return;
}
/*
Quando la vostra docente di laboratorio di algoritmi era bambina, usava a volte, per comunicare con le sue
amiche, uno speciale alfabeto, detto alfabeto farfallino. L’alfabeto farfallino consiste nel sostituire, a ciascuna
vocale, una sequenza di tre lettere della forma vocale-f-vocale. Per esempio, alla lettera a viene sostituita la
sequenza afa, alla lettera e la sequenza efe e così via.
1. Scrivete un programma, di nome farf che, ricevendo come argomento (sulla riga di comando) una parola,
ne stampi la traduzione in alfabeto farfallino. Potete assumere che la stringa in input non contenga lettere
maiuscole.
Nota: Il programma deve stampare la parola in alfabeto farfallino, ma non è richiesto che la parola tradotta
sia memorizzata come stringa.
Esempio di funzionamento
$./farf mamma
mafammafa
$./farf aiuola
afaifiufuofolafa
$./farf farfalla
fafarfafallafa
2. Modificate il programma in modo che accetti più parole sulla riga di comando.
*/