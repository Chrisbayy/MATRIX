#include "IOMATRIX.h"
#include "OPMATRIX.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int main() {
    int opcion;                 //Variable para recoger la opción del usuario

    //Inicialización de la matrices a 0
    int matrizA[N][N] = {0};
    int matrizB[N][N] = {0};
    int resultado[N][N] = {0};

    char archivo[50];           //Variable para almacenar el nombre del archivo para cargar matrices
    int escalar;
    int matricesCargadas = 0;   //Variable para comprobar que las matrices se han cargado correctamente antes de realizar cualquier operacion
    int seleccionMatriz;

    do{
        system("cls");
        printf("\n\n\t------------------------------------------------------\n");
        printf("\t\t MENU MATRIX\n");
        printf("\t------------------------------------------------------\n");
        printf("\n\t1. Cargar Matrices\n");
        printf("\n\t2. Operaciones\n");
        printf("\n\t3. Mostrar Matrices\n");
        printf("\n\t4. Guardar Resultado en Archivo\n");
        printf("\n\t5. Salir\n");
        printf("\n\tSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion){
           case 1:
                printf("Ingrese el nombre del archivo para cargar la matriz A: ");
                scanf("%s", archivo);

                int correcto = 0;
                while (correcto == 0) {
                    if (cargarMatrices(archivo, matrizA)) {
                        printf("Matriz A cargada correctamente.\n");
                        matricesCargadas |= 1;  // Marcamos la matriz A como cargada
                        logOperacion(CARGA_MATRIZ, matrizA, matrizB, matrizA, 0);
                        correcto = 1;
                    } else {
                        printf("Error al cargar la matriz A. Intente de nuevo.\n");
                        printf("Ingrese el nombre del archivo para cargar la matriz A: ");
                        scanf("%s", archivo);
                    }
                }

                // Ahora pasamos a cargar la matriz B
                printf("Ingrese el nombre del archivo para cargar la matriz B: ");
                scanf("%s", archivo);

                correcto = 0;
                while (correcto == 0) {
                    if (cargarMatrices(archivo, matrizB)) {
                        printf("Matriz B cargada correctamente.\n");
                        matricesCargadas |= 2;  // Marcamos la matriz B como cargada
                        logOperacion(CARGA_MATRIZ, matrizA, matrizB, matrizB, 0);
                        correcto = 1;
                    } else {
                        printf("Error al cargar la matriz B. Intente de nuevo.\n");
                        printf("Ingrese el nombre del archivo para cargar la matriz B: ");
                        scanf("%s", archivo);
                    }
                }
                break;


            case 2: 
                printf("\n\t-------- OPERACIONES --------\n");
                printf("\n\t1. Sumar Matrices (A + B)\n" );
                printf("\n\t2. Restar Matrices (A - B)\n");
                printf("\n\t3. Multiplicar Matrices (A * B)\n");
                printf("\n\t4. Producto Escalar (k * A)\n");
                printf("\n\t5. Transponer Matriz (A^T)\n");
                printf("\n\t6. Verificar Simetria de la Matriz A\n");
                printf("\n\tSeleccione una operacion: ");
                int operacion;
                scanf("%d", &operacion);

                switch (operacion){
                    case 1: 
                        if(matricesCargadas == 3) {
                            sumar_matrices(matrizA, matrizB, resultado);
                            printf("\n\tMatriz A:\n");
                            visualizarMatriz(matrizA);
                            printf("\n\t  +\n");
                            printf("\tMatriz B:\n");
                            visualizarMatriz(matrizB);
                            printf("\n\t  =\n");
                            printf("\n\tResultado:\n");
                            visualizarMatriz(resultado);
                            logOperacion(SUMA, matrizA, matrizB, resultado, 0);

                        } else {
                            printf("Ambas matrices deben estar cargadas para realizar la suma.\n");
                        }
                        break; 
                    
                    case 2: 
                        if(matricesCargadas == 3) {
                            restar_matrices(matrizA, matrizB, resultado);
                            printf("\n\tMatriz A:\n");
                            visualizarMatriz(matrizA);
                            printf("\n\t  -\n");
                            printf("\tMatriz B:\n");
                            visualizarMatriz(matrizB);
                            printf("\n\t  =\n");
                            printf("\n\tResultado:\n");
                            visualizarMatriz(resultado);
                            logOperacion(RESTA, matrizA, matrizB, resultado, 0);

                        } else {
                            printf("Ambas matrices deben estar cargadas para realizar la resta.\n");
                        }
                        break;
                    
                    case 3: 
                            if(matricesCargadas == 3) {
                            multiplicar_matrices(matrizA, matrizB, resultado);
                            printf("\n\tMatriz A:\n");
                            visualizarMatriz(matrizA);
                            printf("\n\t  *\n");
                            printf("\tMatriz B:\n");
                            visualizarMatriz(matrizB);
                            printf("\n\t  =\n");
                            printf("\n\tResultado:\n");
                            visualizarMatriz(resultado);
                            logOperacion(MULTIPLICACION, matrizA, matrizB, resultado, 0);

                        } else {
                            printf("Ambas matrices deben estar cargadas para realizar la multiplicación.\n");
                        }
                        break;
                    
                    case 4: 
                        if(matricesCargadas & 1) {  //Solo necesitamos la matriz A cargada
                            printf("Ingrese el valor escalar: ");
                            printf("Ingrese el valor escalar: ");
                            scanf("%d", &escalar);
                            producto_escalar(matrizA, escalar, resultado);
                            printf("\n\tProducto escalar %d * A:\n");
                            visualizarMatriz(matrizA);
                            printf("\n\t  *\n");
                            printf("\t  %d\n", escalar);
                            printf("\n\t  =\n");
                            printf("\n\tResultado:\n");
                            visualizarMatriz(resultado);
                            logOperacion(PRODUCTO_ESCALAR, matrizA, matrizB, resultado, escalar);
                        }
                        else {
                            printf("La matriz A debe estar cargada para realizar el producto escalar.\n");
                        }
                        break;  
                    
                    case 5: // Matriz Transpuesta
                        printf("\n\tCalcular transpuesta de (1=Matriz A, 2=Matriz B): ");
                        scanf("%d", &seleccionMatriz);

                        if (seleccionMatriz == 1 && (matricesCargadas & 1)) {
                            // Usuario eligió A y A está cargada
                            transponerMatriz(matrizA, resultado);
                            printf("\n\tTranspuesta de A (guardada en Resultado):\n");
                            visualizarMatriz(resultado);
                            logOperacion(TRASPUESTA, matrizA, matrizB, resultado, 0); // Asumiendo que TRASPUESTA es un tipo de log
                        
                        } else if (seleccionMatriz == 2 && (matricesCargadas & 2)) {
                            // Usuario eligió B y B está cargada
                            transponerMatriz(matrizB, resultado);
                            printf("\n\tTranspuesta de B (guardada en Resultado):\n");
                            visualizarMatriz(resultado);
                            logOperacion(TRASPUESTA, matrizB, matrizA, resultado, 0); // O como gestiones el log
                        
                        } else {
                            printf("Error: Opción no válida o la matriz seleccionada no está cargada.\n");
                        }
                        break;

                    case 6: 
                        printf("\n\tComprobar simetría de (1=Matriz A, 2=Matriz B): ");
                        scanf("%d", &seleccionMatriz);

                        if (seleccionMatriz == 1 && (matricesCargadas & 1)) {
                            // Usuario eligió A y A está cargada
                            printf("\n\tComprobando Matriz A:\n");
                            visualizarMatriz(matrizA);
                            if (verificarSimetria(matrizA)) {
                                printf("\n\t>> Resultado: La Matriz A ES simétrica.\n");
                            } else {
                                printf("\n\t>> Resultado: La Matriz A NO ES simétrica.\n");
                            }
                            logOperacion(SIMETRICA, matrizA, matrizB, resultado, 0); // Asumiendo SIMETRIA
                        
                        } else if (seleccionMatriz == 2 && (matricesCargadas & 2)) {
                            // Usuario eligió B y B está cargada
                            printf("\n\tComprobando Matriz B:\n");
                            visualizarMatriz(matrizB);
                            if (verificarSimetria(matrizB)) {
                                printf("\n\t>> Resultado: La Matriz B ES simétrica.\n");
                            } else {
                                printf("\n\t>> Resultado: La Matriz B NO ES simétrica.\n");
                            }
                            logOperacion(SIMETRICA, matrizB, matrizA, resultado, 0);

                        } else {
                            printf("Error: Opción no válida o la matriz seleccionada no está cargada.\n");
                        }
                        break;

                    default:
                        printf("Opcion no valida en operaciones.\n");
                        break;
                }
                break; 

            case 3: 
                if(matricesCargadas == 3){
                    printf("\n\tMatriz A:\n");
                    visualizarMatriz(matrizA);
                    printf("\n\tMatriz B:\n");
                    visualizarMatriz(matrizB);
                } else {
                    printf("Las matrices deben estar cargadas para mostrarlas.\n");
                }

                break;
            
            case 4: 
                    if (matricesCargadas == 3) {
                        printf("\nIngrese el nombre del archivo para guardar el resultado: ");
                        scanf("%s", archivo);
                        guardarMatrices(archivo, resultado);
                        printf("Resultado guardado correctamente en %s\n", archivo);
                    } else {
                        printf("El resultado no se puede guardar sin realizar operaciones primero.\n");
                    }
                    break;

            case 5:  
                printf("Gracias por usar el programa.\n");
                break;

            default: 
                printf("Opcion no valida.\n");
                break;
        }

        printf("\n\tPresione Enter para continuar...");
        getchar(); // Captura la tecla enter para continuar

    } while (opcion != 4);

}
