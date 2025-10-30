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
void producto_escalar(int a[N][N], int num);


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



#endif