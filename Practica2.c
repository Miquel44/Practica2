// Importamos las bibliotecas necesarias.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definimos N = 512.
#define N 512
// Declaramos las Matrices.
float Mat[N][N], MatDD[N][N];
// Declaramos los Vectores.
float V1[N], V2[N], V3[N], V4[N];

// Inicialización de Matrices y Vectores.
void InitData(){
    int i,j;
    srand(4422543);
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

// Imprime un vector dado, desde 'from' hasta 'numel'.
void PrintVect(float vect[N], int from, int numel ){
    int i; // Declaramos i como int.
    for (i = from; i <= numel + from; i++){ // Igualamos la variable i al valor introducido en 'from' para comenzar a imprimir por pantalla desde esa posición con la condición de que i no supere el valor 'from + numel', la variable 'numel' es la cantidad de valores que imprimirá a partir de 'from'.
        printf ("%f\n", vect[i]); // Imprimimos el valor que hay en vect[i].
    }
    printf("\n"); // Salto de línea para leer mejor el resultado.
}

// Imprime una fila de una matriz dada, desde 'from' hasta 'numel'.
void PrintRow(float mat[N][N],int row, int from, int numel ){
    int i; // Declaramos la variable i como int.
    for (i = from; i < numel + from; i++){ // Igualamos la variable i al valor introducido en 'from' para comenzar a imprimir por pantalla desde esa posición con la condición de que i no supere el valor 'from + numel', la variable 'numel' es la cantidad de valores que imprimirá a partir de 'from'.
        printf ("%f\n", mat[row][i]); // Imprimimos el valor que hay en mat[row][i].
    }
    printf("\n"); // Salto de línea para leer mejor el resultado.
}

// Multiplica un vector por un escalar y almacena el resultado en otro vector.
void MultEscalar(float vect[N], float vectres[N], float alfa){
    int i; // Declaramos la variable i como int.
    for (i = 0; i < N; i++){ // Para cada valor del vector con tamaño N.
        vectres[i] = vect[i]*alfa; // Se multiplica el valor en vect[i] por alfa y se guarda en la misma posición y en otro vector.
    }
}

// Calcula el producto escalar entre dos vectores.
float Scalar(float vect1[N], float vect2[N]){
    int suma, i; // Declaramos las variables suma e "i" como int.
    for (i = 0; i < N; i++){ // Para cada valor del vector con tamaño N.
        suma += vect1[i]*vect2[i]; // Se multiplica el valor en vect1[i] por el valor en vect2[i] y se realiza un sumatorio de todos los valores.
    }
    return suma; // Retorna el resultado del sumatorio.
}

// Calcula la magnitud de un vector.
float Magnitude(float vect[N] ){
    int suma, i; // Declaramos las variables suma e "i" como int.
    for (i = 0; i < N; i++){ // Para cada valor del vector con tamaño N.
        suma += vect[i]*vect[i]; // Se eleva al cuadrado el valor en vect[i] y se realiza un sumatorio de todos los valores.
    }
    return suma; // Retorna el resultado del sumatorio.
}

// Comprueba si dos vectores son ortogonales.
int Ortogonal(float vect1[N], float vect2[N]){
    if (Scalar(vect1, vect2) == 0){ // Si el valor retornado por la función Scalar() es 0.
        return 1; // Retorna 1 (True).
    }
    else{ // Si no es el caso.
        return 0; // Retorna 0 (False).
    }
}

// Proyecta un vector sobre otro.
void Projection( float vect1[N], float vect2[N], float vectres[N] ){
    float uv, v, div; // Declaramos las variables uv, v, y div como float.
    uv = Scalar(vect1, vect2); // Calculamos el producto escalar entre los dos vectores con la función Scalar() y guardamos el resultado en la variable uv.
    v = Magnitude(vect2); // Calculamos la magnitud del segundo vector con la función Magnitude() y la guardamos en la variable v.
    div = uv / v; // Dividimos el producto escalar de los dos vectores entre la magnitud del segundo y lo guardamos en la variable div.
    MultEscalar(vect2, vectres, div); // Con la función MultEscalar() realizamos la multiplicación del segundo vector por un escalar, que en este caso es el valor guardado en div.
}

// Calcula la norma infinito de una matriz.
float Infininorm(float M[N][N]){
    float max = 0.0, sum; // Declaramos las variables max y sum como float, inicializando también max a 0.0.
    int i, j; // Declaramos las variables "i" y j como int.
    for (i = 0; i < N; i++){
        sum = 0.0;
        for (j = 0; j < N-1; j++){
            sum += fabs(M[i][j]); // Se suma cada valor absoluto de una fila.
        }
        if (sum > max){ // Si la suma de una fila es mayor que el máximo (la suma de una fila más alta hasta ahora).
            max = sum; // La suma de esa fila es el nuevo máximo.
        }
    }
    return max; // Retorna el valor máximo.
}

// Calcula la norma uno de una matriz.
float Onenorm(float M[N][N]){
    float max = 0.0, sum; // Declaramos las variables max y sum como float, inicializando también max a 0.0.
    int i, j; // Declaramos las variables "i" y j como int.
    for (j = 0; j < N; j++){
        sum = 0.0;
        for (i = 0; i < N-1; i++){
            sum += fabs(M[i][j]); // Se suma cada valor absoluto de una columna.
        }
        if (sum > max){ // Si la suma de una columna es mayor que el máximo (la suma de una columna más alta hasta ahora).
            max = sum; // La suma de esa columna es el nuevo máximo.
        }
    }
    return max; // Retorna el valor máximo.
}

// Calcula la norma de Frobenius de una matriz.
float NormFrobenius(float M[N][N]){
    float sum; // Declaramos la variable sum como float.
    int i, j; // Declaramos las variables "i" y j como int.
    for (i = 0; i < N; i++){
        for (j = 0; j < N-1; j++){
            sum += M[i][j] * M[i][j]; // Se realiza un sumatorio de cada valor de la matriz elevado al cuadrado.
        }
    }
    float raiz = sqrt(sum); // Declaramos la variable raiz como float y la igualamos a la raíz cuadrada del sumatorio anterior.
    return raiz; // Retornamos el valor que hay en raiz.
}

// Comprueba si una matriz es diagonal dominante.
int DiagonalDom(float M[N][N]){
    float ediag, sum_no_diag; // Declaramos las variables ediag (Elemento de la diagonal) y sum_no_diag (suma elementos que no son de la diagonal).
    int i, j; // Declaramos las variables "i" y j como int.
    for (i = 0; i < N; i++){
        sum_no_diag = 0.0;
        for (j = 0; j < N; j++){
            if (i == j){
                ediag = fabs(M[i][j]); // Se iguala a ediag el valor del elemento de la diagonal de la fila i.
            }
            else{
                sum_no_diag += fabs(M[i][j]); // Se suman todos los valores que no son de la diagonal a la variable sum_no_diag.
            }
        }
        if (ediag < sum_no_diag){ // Si el valor de la diagonal es menor que la suma de todos los otros valores de la fila.
            return 0; // Retorna 0 (False).
        } // Solo es necesario que una fila cumpla la condición para hacer que la matriz no sea diagonal dominante.
    }
    return 1; // Retorna 1 (True).
}

// Implementa el método de Jacobi para resolver un sistema lineal.
int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ) {
  // Declarar variables locales
  float x[N]; // Vector de soluciones aproximadas
  float error; // Error entre dos soluciones consecutivas
  float sum; // Suma parcial de los productos de los elementos de la matriz y el vector
  int i, j, k; // Índices para recorrer la matriz y el vector
  int converge = 1; // Indicador de convergencia
  if (DiagonalDom(M) == 0) {
      printf("La matriz Mat no es diagonal dominante. No se puede aplicar Jacobi.\n");
      return 0;
      exit(0);
  }
  // Inicializar el vector de soluciones con ceros
  for (i = 0; i < N; i++) {
    x[i] = 0;
  }
  for (k = 0; k < iter; k++) {
    for (i = 0; i < N; i++) {
      sum = 0;
      for (j = 0; j < N; j++) {
        if (i != j) {
          sum += M[i][j] * x[j];
        }
      }
      vectres[i] = (vect[i] - sum) / M[i][i];
    }
    // Calcular el error entre dos soluciones consecutivas, PUNTO EXTRA
    error = 0;
    for (i = 0; i < N; i++) {
      error += fabs(vectres[i] - x[i]);
    }
    // Comprobar si el error es suficientemente pequeño para convergencia, PUNTOEXTRA
    if (error < 0.0001) {
      break;
    }
    // Actualizar el vector de soluciones con el nuevo resultado
    for (i = 0; i < N; i++) {
      x[i] = vectres[i];
    }
  }
  // Si el número de iteraciones alcanza el límite, considerar que no converge
  if (k == iter) {
    converge = 0;
  }
  return converge;
}
int main(){
    InitData();

    // A.
    printf("V1 de 0 a 9:\n");
    PrintVect(V1, 0, 9);
    printf("V2 de 0 a 9:\n");
    PrintVect(V2, 0, 9);
    printf("V3 de 0 a 9:\n");
    PrintVect(V3, 0, 9);

    printf("V1 de 256 a 265:\n");
    PrintVect(V1, 256, 9);
    printf("V2 de 256 a 265:\n");
    PrintVect(V2, 256, 9);
    printf("V3 de 256 a 265:\n");
    PrintVect(V3, 256, 9);
    // B.

    printf("Mat fila 0 de 0 a 9:\n");
    PrintRow(Mat, 0, 0, 9);
    printf("Mat fila 100 de 0 a 9:\n");
    PrintRow(Mat, 100, 0, 9);
    // C.

    printf("MatDD fila 0 de 0 a 9:\n");
    PrintRow(MatDD, 0, 0, 9);
    printf("MatDD fila 100 de 90 a 99:\n");
    PrintRow(MatDD, 100, 90, 9);

    // D.
    printf("Mat:\n");
    printf("Infini-norma: %f\n", Infininorm(Mat));
    printf("Norma ú: %f\n", Onenorm(Mat));
    printf("Norma de Frobenius: %f\n", NormFrobenius(Mat));
    printf("Es Mat diagonal dominant? %d\n\n",DiagonalDom(Mat));

    printf("MatDD:\n");
    printf("Infini-norma: %f\n", Infininorm(MatDD));
    printf("Norma ú: %f\n", Onenorm(MatDD));
    printf("Norma de Frobenius: %f\n", NormFrobenius(MatDD));
    printf("Es Mat diagonal dominant? %d\n\n",DiagonalDom(MatDD));

    // E.
    printf("Producte escalar V1·V2: %f \n", Scalar(V1,V2));
    printf("Producte escalar V1·V3: %f \n", Scalar(V1,V3));
    printf("Producte escalar V2·V3: %f \n\n", Scalar(V2,V3));

    // F.
    printf("Magnitud V1; %f \n", Magnitude(V1));
    printf("Magnitud V2; %f \n", Magnitude(V2));
    printf("Magnitud V3; %f \n\n", Magnitude(V3));

    // G.
    printf("V1 i V2 son ortogonals? %d \n", Ortogonal(V1,V2));
    printf("V1 i V3 son ortogonals? %d \n", Ortogonal(V1,V3));
    printf("V2 i V3 son ortogonals? %d \n\n", Ortogonal(V2,V3));

    // H.
    printf("V4 = V3·2.0:\n");
    MultEscalar(V3, V4, 2.0);
    printf("V4 de 0 a 9:\n");
    PrintVect(V4, 0, 9);
    printf("V4 de 256 a 265:\n");
    PrintVect(V4, 256, 9);

    // I.
    Projection(V2, V3, V4);
    printf("Projecció del V2 sobre V3 (10 primers):\n");
    PrintVect(V4, 0, 10);
    Projection(V1, V2, V4);
    printf("Projecció del V1 sobre V2 (10 primers):\n");
    PrintVect(V4, 0, 10);
    // J
    Jacobi(MatDD,V3,V4,1);
    printf("Els elements 0 a 9 de la solució (1 iter) del sistema d'equacions són:\n");
    PrintVect(V4, 0, 9);
    Jacobi(MatDD,V3,V4,1000);
    printf("Els elements 0 a 9 de la solució (1000 iter) del sistema d'equacions són:\n");
    PrintVect(V4, 0, 9);
    Jacobi(Mat,V3,V4,1);

    }
