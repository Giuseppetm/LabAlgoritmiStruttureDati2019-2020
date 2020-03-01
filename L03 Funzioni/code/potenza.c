// Scrivete una funzione ricorsiva avente due parametri interi b ed e che calcoli la potenza be.
#include <stdio.h>
int potenza(int b, int e);
int main() {
    int b,e;
    printf("insert b and e: ");
    scanf("%d %d", &b, &e);
    printf("%d", potenza(b,e));
}

int potenza(int b, int e) {
    if (e == 0) {
        return 1;
    }
    return (b * potenza(b,e-1));
}