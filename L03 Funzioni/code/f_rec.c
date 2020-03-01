Considerate questa funzione ricorsiva f_rec

unsigned long f_rec(int n){
    if ( n == 1 || n == 2 ){
        return 1;
    }
    return f_rec( n - 1 ) + f_rec( n - 2 );
}

Senza eseguire la funzione al computer, rispondete alle seguenti domande:
1. Cosa restituisce la funzione f(7)?   13
2. Perché n è dichiarato come intero mentre il valore restituito è di tipo unsigned long?
Perché la funzione essendo ricorsiva potrebbe returnare un valore enorme.
3. Riassumete a parole cosa restituisce la funzione se riceve come argomento un intero positivo n maggiore
di 0.


Considerate ora le due funzioni f_iter1 e f_iter2

unsigned long f_iter1(int n){
    unsigned long f, f1 = 1, f2 = 1;
    if ( n == 2 | n == 1 ) {
        return 1;
    }
    while (n-- >= 3) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

unsigned long f_iter2(int n){
    unsigned long f, f1 = 1, f2 = 1, i;
    if ( n == 2 | n == 1 ) {
        return 1;
    }

    for ( i = 2; i <= n; i++ ) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

Senza eseguire la funzione al computer, rispondete alle seguenti domande:
4. Considerando solo il valore restituito, le due funzioni sono equivalenti? (ovvero: restituiscono sempre lo
stesso valore?)
5. Le due funzioni sono equivalenti alla funzione f_rec?
6. Modificate (se necessario) le funzioni f_iter1 e f_iter2 in modo che risultino essere equivalenti a f_rec.
7. Stimate il numero di operazioni che si svolgono durante l’esecuzione di f_rec, f_iter1 e f_iter2: sono
paragonabili?

Considerate infine la seguente funzione ricorsiva f_riter

unsigned long f_riter(unsigned long a, unsigned long b, int n){
   if ( n == 2 ) {
       return a;
   }
    if ( n == 1 ) {
        return b;
    }
    return f_riter( a + b, a, n - 1 );
}

Senza eseguire la funzione al computer, rispondete alle seguenti domande:
8. Convincetevi che questa funzione può essere usata per calcolare f_rec. In particolare: con quali argomenti
devo invocare f_riter per ottenere il valore restituito da f_rec(n)?
9. Rappresentate graficamente lo schema delle chiamate ricorsive definiti dall’invocazione f_rec(7) e dalla
chiamata equivalente del tipo f_riter(..., ..., ...).
10. Considerate il numero di chiamate ricorsive effettute da f_rec(n) e dalla chiamata equivalente del tipo
f_riter(..., ..., ...). Sono paragonabili?
11. Usate una variabile globale counter per tenere traccia del numero delle chiamate ricorsive; quindi scrivete
un programma che invoca f_rec e f_riter e stampa, oltre al valore restituito, anche il numero di chiamate
della funzione.
Una volta concluso l’esercizio potete usare il file rec-iter.c per fare degli esperimenti. Analizzate il codice per
capire come usarlo e come interpretarne l’output!