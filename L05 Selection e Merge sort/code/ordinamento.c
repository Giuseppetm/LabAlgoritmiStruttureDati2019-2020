#include <stdio.h>
#include <math.h>
#define MAX 100
int x[MAX]; // l'array di supporto potrebbe avere len (a+b)
void stampa( int a[], int lung );
void scambia( int a[], int i, int j );
void selectionsort ( int a[], int n );
void mergesort( int a[], int sx , int dx );

int main(void) {
    int a[MAX] = {4,5,1,2,67,56,45,34,23,78,45,56,23}; // Input non presente
    int n = 13;
    /* lettura di un array di interi da standard input */
    /* scegliere uno dei due algoritmi:
    selectionsort( a, N);
    mergesort( a, 0, N);
    */

    stampa( a, n );

    int k;
    printf("order by selection(0) or merge(1)? ");
    scanf("%d", &k);
    if (k == 0) {
        selectionsort( a, n);
    } else {
        mergesort( a, 0, n);
    }

    stampa( a, n );
    return 0;   
}

void selectionsort( int a[], int n ) {
    if (n == 0 || n == 1)
        return;
    
    int iMax = 0;
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            iMax = i;
            max = a[i];
        }
    }
    scambia(a,iMax,n-1);
    return selectionsort(a,n-1);
}


void merge(int a[], int sx, int m, int dx) {
    int i1 = sx;
    int i2 = m;
    int k = 0;

    while (i1 < m && i2 < dx) {
        if (a[i1] < a[i2]) {
            x[k] = a[i1];
            i1++;
        } else {
            x[k] = a[i2];
            i2++;
        }
        k++;
    }

    while (i1 < m) {
        x[k++] = a[i1++];
    }

    while (i2 < dx) {
        x[k++] = a[i2++];
    }

    for (int i = 0; i < k; i++) {
        a[sx + i] = x[i];
    }
    return;
}

void mergesort( int a[], int sx , int dx ) {
    if (dx-sx <= 1)
        return;

    int m = (dx+sx)/2;
    mergesort(a,sx,m);
    mergesort(a,m,dx);
    merge(a,sx,m,dx);
}

void stampa( int a[], int lung ) {
    for (int i=0; i < lung; i++)
        printf("%d ", a[i]);

    printf("\n");
    return;
}

void scambia( int a[], int i, int j ) {
    int c = a[i];
    a[i] = a[j];
    a[j] = c;
    return;
}