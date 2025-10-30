#ifndef IOMATRIX_H
#define IOMATRIX_H

#include <stdio.h>

#ifndef __cplusplus  // evita conflicto con C++
typedef int bool;
#define true 1
#define false 0
#endif

#define N 5

typedef enum {
    SUMA,
    RESTA,
    MULTIPLICACION,
    PRODUCTO_ESCALAR,
    SIMETRICA,
    TRASPUESTA,
    CARGA_MATRIZ,
    GUARDADO_MATRIZ
}Operacion;

void visualizarMatriz(int matriz[N][N]);
int cargarMatriz(const char* nombre, int m[N][N]);


void visualizarMatriz(int matriz[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

int cargarMatriz(const char* nombre, int m[N][N])
{
    FILE* archivo = fopen(nombre, "r");
    if (archivo == NULL) 
    {
        printf("Error al abrir el archivo\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j= 0; j < N; j++)
        {
            fscanf(archivo, "%d", &m[i][j]);
        }
    }

    fclose(archivo);
    return true;
}








#endif