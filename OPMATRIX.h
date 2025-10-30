#ifndef _OPMATRIX_H_
#define _OPMATRIX_H_

//tamaño matrices
#define N 5


//Cabecera: void sumar_matrices(int a[][], int b[][], int r[][]);
//Precondición: matrices tienen que estar cargadas del fichero correspondiente
//Postcondición: rellena la matriz r que almacena el resultado de la suma de ambas matrices
void sumar_matrices(int a[N][N], int b[N][N], int r[N][N]);

//Cabecera: void restar_matrices(int a[][], int b[][], int r[][]);
//Precondición: matrices tienen que estar cargadas del fichero correspondiente
//Postcondición: rellena la matriz r que almacena el resultado de la resta de ambas matrices
void restar_matrices(int a[N][N], int b[N][N], int r[N][N]);

//Cabecera: void multiplicar_matrices(int a[][], int b[][], int r[][])
//Precondición: matrices tienen que estar cargadas del fichero correspondiente
//Postcodición: rellena la matriz r que almacena el resultado del producto de ambas matrices
void multiplicar_matrices(int a[N][N], int b[N][N], int r[N][N]);

//Cabecera: void producto_escalar(int a[][], int num, int r[][])
//Precondición: matrices tienen que estar cargadas del fichero correspondiente
//Postcondición: rellena la matriz r que almacena el resultado de multiplicar la matriz por el numero
void producto_escalar(int a[N][N], int num, int r[N][N]);

void transponerMatriz(int A[N][N], int R[N][N]);

int verificarSimetria(int A[N][N]);
//IMPLEMENTACIÓN OPERACIONES
inline void sumar_matrices(int a[N][N], int b[N][N], int r[N][N]){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            r[i][j]=a[i][j] + b[i][j];
        }
    } 

}

inline void  restar_matrices(int a[N][N], int b[N][N], int r[N][N]){
    int i, j;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            r[i][j]=a[i][j] - b[i][j];
        }
    }

    
}


inline void multiplicar_matrices(int a[N][N], int b[N][N], int r[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            r[i][j] = 0; 
            for (int k = 0; k < N; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

inline void producto_escalar(int a[N][N], int num, int r[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            r[i][j]=num*a[i][j];
        }
    }
}

// Implementa la transposición de una matriz 5x5
void transponerMatriz(int A[N][N], int R[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Transponer A[i][j] a B[j][i]
            R[j][i] = A[i][j];
        }
    }
}


//Verifica si es una matriz 5x5 es simétrica
int verificarSimetria(int A[N][N]){
     int R[N][N];
    transponerMatriz(A, R);

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != R[i][j]) {
                return 0; // No es simétrica
            }
        }
    }
    return 1; // Es simétrica
}



#endif