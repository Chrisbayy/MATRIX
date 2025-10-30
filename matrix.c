#include "IOMATRIX.h"
#include "OPMATRIX.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 5

int main() {
    int opcion;                 //Variable para recoger la opción del usuario

    //Inicialización de la matrices a 0
    int matrizA[N][N] = {0};
    int matrizB[N][N] = {0};
    int resultado[N][N] = {0};

    char archivo[50];           //Variable para almacenar el nombre del archivo para cargar matrices
    int matricesCargadas = 0;   //Variable para comprobar que las matrices se han cargado correctamente antes de realizar cualquier operacion

    do{
        system("cls");
        printf("\n\n\t------------------------------------------------------\n");
        printf("\t\t MENU MATRIX\n");
        printf("\t------------------------------------------------------\n");
        printf("\n\t1. Cargar Matrices\n");
        printf("\n\t2. Operaciones\n");
        // printf("\n\t3. Mostrar Matrices\n" COLOR_OFF);
        // printf("\n\t4. Guardar Resultado en Archivo\n" COLOR_OFF);
        printf("\n\t5. Salir\n");
        printf("\n\tSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion){
            case 1: 
                printf("Ingrese el nombre del archivo para cargar la matriz A: ");
                scanf("%s", archivo);
                if(cargarMatrices(archivo, matrizA)) {
                    printf("Matriz A cargada correctamente \n");
                    matricesCargadas |= 1;  //Marcamos la matriz A como cargada
                    //logOperacion
                } else {
                    printf("Error al cargar la matriz A.\n");
                }

                //Pasamos ahora a cargar la matriz B
                printf("Ingrese el nombre del archivo para cargar la matriz B: ");
                scanf("%s", archivo);
                if(cargarMatrices(archivo, matrizB)) {
                    printf("Matriz A cargada correctamente \n");
                    matricesCargadas |= 2;  //Marcamos la matriz A como cargada
                    //logOperacion
                } else {
                    printf("Error al cargar la matriz B.\n");
                }
                break;

            case 2: 
                printf("\n\t-------- OPERACIONES --------\n");
                printf("\n\t1. Sumar Matrices (A + B)\n" );
                printf("\n\t2. Restar Matrices (A - B)\n");
                //printf("\n\t3. Multiplicar Matrices (A * B)\n");
                //printf("\n\t4. Producto Escalar (k * A)\n");
                //printf("\n\t5. Transponer Matriz (A^T)\n");
                //printf("\n\t6. Verificar Simetria de la Matriz A\n");
                printf("\n\tSeleccione una operacion: ");
                int operacion;
                scanf("%d", &operacion);

                switch (operacion){
                    case 1: 
                        if(matricesCargadas == 3) {
                            sumar_matrices(matrizA, matrizB, resultado);
                            visualizarMatriz(matrizA);
                            printf("\n\t  +\n");
                            visualizarMatriz(matrizB);
                            printf("\n\t  =\n");
                            printf("\n\tResultado:\n");
                            visualizarMatriz(resultado);
                            //logOperacion

                        } else {
                            printf("Ambas matrices deben estar cargadas para realizar la suma.\n");
                        }
                        break; 
                    
                    case 2: 
                        if(matricesCargadas == 3) {
                            restar_matrices(matrizA, matrizB, resultado);
                            visualizarMatriz(matrizA);
                            printf("\n\t  -\n");
                            visualizarMatriz(matrizB);
                            printf("\n\t  =\n");
                            printf("\n\tResultado:\n");
                            visualizarMatriz(resultado);
                            //logOperacion

                        } else {
                            printf("Ambas matrices deben estar cargadas para realizar la resta.\n");
                        }
                        break;
                }
                break; 

            case 3: break; 
            case 4: break;
            case 5: break; 

            default: 
                printf("Opcion no valida.\n");
                break;
        }

        printf("\n\tPresione Enter para continuar...");
        getchar(); // Captura la tecla enter para continuar
        getchar(); // Captura el segundo enter para esperar entrada

    } while (opcion != 5);
}