char ** creaMatrice( int n ){
     char **m;
     int r, c;

     m = malloc( n * sizeof( char * ) );
     for ( r = 0; r < n; r++ ) {
          *(m+r) = malloc( n * sizeof( char ) );       // m[r] =malloc(n * sizeof(char));
     }

     for ( r = 0; r < n; r++ )
          for ( c = 0; c < n; c++ )
               m[r][c] = ’.’;          // *(*(m+r)+c) = '.'

     return m;
}

/*
 A cosa serve l’assegnamento nella riga 5?
Serve ad allocare lo spazio per i puntatori delle righe.

 Riscrivete la riga 7 usando la notazione degli array invece della notazione dei puntatori
k

 A cosa serve l’assegnamento della riga 7?
Serve ad allocare lo spazio per una riga, e assegna i relativi puntatori.

 Riscrivete la riga 12 con la notazione dei puntatori anziché quella degli array.
k

 Cosa restituisce la funzione?
Restituisce un puntatore al puntatore del primo elemento della matrice
*/