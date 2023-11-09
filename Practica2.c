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


void PrintRow(float mat[N][N],int row, int from, int numel ){
	int i; // Declarem la variable i com a int.
	for (i = from; i < numel + from; i++){ // Igualem la variable i al valor introduit from per començar a imprimir per pantalla desde aquella posició amb la condicio que i no passi del valor from + numel, la variable numel es la cantitat de valors que imprimira a partir del from.
		printf ("%f\n", mat[row][i]); // Imprimim el valor que hi ha a mat[row][i].
	}
	printf("\n"); // Salt de linea per llegir millor el resultat.
}

void MultEscalar(float vect[N], float vectres[N], float alfa){
	int i; // Declarem la variable i com a int.
	for (i = 0; i < N; i++){ // Per cada valor del vect amb mida N.
		vectres[i] = vect[i]*alfa; // Es multiplica el valor a vect[i] per alfa i es guarda a la mateixa posició i en un altre vector.
	}
}

float Scalar(float vect1[N], float vect2[N]){
	int suma, i; // Declarem les variables suma i "i" com a int.
	for (i = 0; i < N; i++){ // Per cada valor del vect amb mida N.
		suma += vect1[i]*vect2[i]; // Es multiplica el valor a vect1[i] per el valor a vect2[i] i es fa un sumatori de tots els valors.
	}
	return suma; // Retorna el resultat del sumatori
float Magnitude(float vect(N)){
	int result,i;
	for (i = 0; i < N; i++){
		result += vect[i] * vect[i]
		}
	result = sqrt(result)
	return result
       }
int Ortogonal(float vect1[N],float vect2[N]){
	if Scalar(vect1,vect2) == 0{
		return 1;
	}
	else{
		return 0;
		}
	}
void Projection(float vect1[N],float vect2[N],float vectres[N]){
	float ScalarV, result;
	ScalarV = Scalar(vect1,vect2) / fabs(vect2);  //fabs es un comando de c para el valor absoluto de un vector
	result = MultEscalar(vect2,vectres,ScalarV);
}

float infininorm(float M[N][N]){
	int i,j;// Declarem les variables "i" i j com a int.
	float max=0.0,suma; // Declarem les variables max i sum com a float, inicialitzant també max a 0.0.
	for (i = 0; i < N; i++){
		for (i = 0; i < N; i++){
			suma += fabs(M[i][j]);
		}
		if (suma > max){ // La suma d'aquella fila és el nou máxim.
		max=suma;
		}
		
	}
	return max;
}
float Onenorm(float M[N][N]){
	float max = 0.0, sum; 
	int i, j; 
	for (j = 0; j < N; j++){
		sum = 0.0;
		for (i = 0; i < N-1; i++){
			sum += fabs(M[i][j]); 
		}
		if (sum > max){ 
		max = sum; // La suma d'aquella columna és el nou máxim.
		}
	}
	return max; 
}
//La diferencia amb el infininorm es el ordre dels fors, aixi un recorreix las columnes i el altre les files
float NormFrobenius(float M[N][N]){
	float sum; // Declarem la variable sum com a float.
	int i, j; // Declarem les variables "i" i j com a int.
	for (i = 0; i < N; i++){
		for (j = 0; j < N-1; j++){
			sum += M[i][j] * M[i][j]; // Es fa un sumatori de cada valor de la matriu elavat al quadrat.
		}
	}
	float arrel = sqrt(sum); // Declarem la variable arrel com a float i la igualem a l'arrel quadrada del sumatori anterior.
	return arrel; // Retornem el valor que hi ha a arrel.
}

int DiagonalDom(float M[N][N]){
	float ediag, sum_no_diag; // Declarem les variables ediag(Element de la diagonal) i sum_no_diag(suma elements que no son de la diagonal).
	int i, j; // Declarem les variables "i" i j com a int.
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (i == j){
				ediag = fabs(M[i][j]); // S'iguala a ediag el valor del element de la diagonal de la fila i.
			}
			else{
				sum_no_diag += fabs(M[i][j]); // Es sumen tots els valors que no son de la diagonal a la variable sum_no_diag.
			}
		}
		if (ediag < sum_no_diag){ // Si el valor de la diagonal és més petit que la suma de tots els altres valors de la fila.
			return 0; // Retorna 0 (False)
		} // Només cal que una fila compleixi la condició per fer que la matriu no sigui diagonal dominant.

	}
	return 1; // Retorna 1 (True)
}