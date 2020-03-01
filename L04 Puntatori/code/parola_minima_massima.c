#include <stdio.h>
#include <string.h>

void smallest_largest(char *s[], int n, char **smallest, char **largest) {
    *smallest = *s;
    *largest = *s;
    
    for (char **p = s + 1; p < s + n; p++) {
        if (strcmp(*p, *smallest) < 0)
            *smallest = *p;
        if (strcmp(*p, *largest) > 0)
            *largest = *p;
    }
    return;
}

int main(void) {
    char *s[] = {"Mamma", "Guarda", "Come", "Mi", "Diverto", "Ciao"};
    int n = 6;
    char *smallest = NULL;
    char *largest = NULL;
    smallest_largest(s, n, &smallest, &largest);
    printf("Smallest=%s\nLargest=%s\n", smallest, largest);
    return 0;
}

/*Scrivete una funzione con prototipo
void smallest_largest( char *s[], int n, char **smallest, char **largest )
che, dato un array s lungo n di stringhe, trovi gli elementi minimo e massimo nell’array (secondo l’ordine
alfabetico) e memorizzi gli indirizzi delle loro posizioni nel vettore s negli indirizzi di memoria puntati
rispettivamente da smallest e da largest.
Suggerimenti: vedete somiglianze con la funzione max_secondmax? Prima di cominciare rappresentate graficamente
quale deve essere lo stato della memoria subito dopo l’invocazione della funzione e subito prima del
return.*/