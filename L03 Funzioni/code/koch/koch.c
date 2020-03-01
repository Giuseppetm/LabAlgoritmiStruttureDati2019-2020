#include <stdio.h>
#include "libpsgraph.h"
void curvaDiKoch(float x, int i);
void fioccoDiKoch(float x, int i);
int main() {
    start("dennis.ps");
    fioccoDiKoch(0.3,4);
    end();
    return 0;
}

void fioccoDiKoch(float x, int i) {
    turn(300);
    curvaDiKoch(x,i);
    turn(120);
    curvaDiKoch(x,i);
    turn(120);
    curvaDiKoch(x,i);
}


void curvaDiKoch(float x, int i) {
    if ( i == 0 ) {
        draw(x);
    } else {
        int temp = x / 3;
        curvaDiKoch(x,i-1);
        turn(300);
        curvaDiKoch(x,i-1);
        turn(120);
        curvaDiKoch(x,i-1);
        turn(300);
        curvaDiKoch(x,i-1);
    }
}
/*
a questo punto, per disegnare potete usare le seguenti funzioni (che prendono come argomento un double):
– draw(x): disegna un segmento lungo x millimetri;
– move(x): si sposta (senza disegnare) di un segmento lungo x millimetri;
– turn(x): si gira a destra di x gradi;
 alla fine, dovete invocare la funzione end().

Curva di Koch
Realizzate una funzione che, data una lunghezza in millimetri x e un intero i, produce la curva di Koch di ordine
i e di lunghezza x. Essa è definita come segue:
 se i = 0, è un segmento di lunghezza x;
 se i > 0, è ottenuta giustapponendo quattro curve di Koch di ordine i-1 e di lunghezza x/3
Dopo averla realizzata, verificate che funzioni (scrivendo un main che la invoca e guardando il file risultante).

Fiocco di neve di Koch
Realizzate ora una funzione che, data una lunghezza in millimetri x e un intero i, produce il fiocco di neve di
Koch di ordine i e di lunghezza x: esso si ottiene come un triangolo equilatero di lunghezza x i cui lati siano stati
sostituiti con curve di Koch di ordine i e lunghezza x (vedi Figura ??).
*/