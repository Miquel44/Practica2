// Importem les llibreries necessaries.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Definim N = 512.
#define N 512 
// Declarem les Matrius.
float Mat[N][N], MatDD[N][N]; 
// Declarem els Vectors.
float V1[N], V2[N], V3[N], V4[N]; 

// Inicialització Matrius i Vectors.
void InitData(){ 
	int i,j;
	srand(8824553);
	for( i = 0; i < N; i++ )
		for( j = 0; j < N; j++ ){
			Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
			if ( (abs(i - j) <= 3) && (i != j))
				MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
			else if ( i == j )
				MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
			else MatDD[i][j] = 0.0;
		}
		for( i = 0; i < N; i++ ){
			V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
			V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
			V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
		}
}

void PrintVect(float vect[N], int from, int numel ){
	int i; // Declarem i com a int.
	for (i = from; i < numel + from; i++){ // Igualem la variable i al valor introduit from per començar a imprimir per pantalla desde aquella posició amb la condicio que i no passi del valor from + numel, la variable numel es la cantitat de valors que imprimira a partir del from.
		printf ("%f\n", vect[i]); // Imprimim el valor que hi ha a vect[i].
	}
	printf("\n"); // Salt de linea per llegir millor el resultat.
}


