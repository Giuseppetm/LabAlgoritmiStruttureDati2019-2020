#include <stdio.h>
#include <stdlib.h>

void selectionSort (int *a, int n);
int maxTubi(int *candidati, int n, int lunghezza);

int main(void) {
     int lunghezza, n;
     printf("Insert l: ");
     scanf("%d", &lunghezza);
     printf("Insert n: ");
     scanf("%d", &n);

     int *candidati = malloc(n * sizeof(int));
     for (int i = 0; i < n; i++)
          scanf("%d", &candidati[i]);

     // Ordino l'array
     selectionSort(candidati,n);
     // Vedo quanti ce ne entrano
     int max = maxTubi(candidati, n, lunghezza);
     printf("%d\n", max);
}

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp; 
}

void selectionSort(int *a, int n) {
     int i, j, m; 
     for (i=0; i<n-1;i++) {
          m = i; 
          for (j=i+1; j<n; j++) 
               if (a[j] < a[m])
                    m = j;
          swap(a,i,m);
     }
}

int maxTubi(int *candidati, int n, int lunghezza) {
     int max = 0, sum = 0;
     int i; 
     for (i=0; i<n;i++)
          if (sum + candidati[i] <= lunghezza) {
               sum = sum + candidati[i];
               max++;
          } else
               break; 
     return max;
}