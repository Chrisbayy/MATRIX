#ifndef IOMATRIX_H
#define IOMATRIX_H

#include <stdio.h>

#include <stdbool.h>

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
int cargarMatrices(const char* nombre, int m[N][N]);
void guardarMatrices(const char* nombre, int m[N][N]);


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

int cargarMatrices(const char* nombre, int m[N][N])
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


void escribirMatriz(FILE* archivo, int m[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(archivo, "%d", m[i][j]);
        }
        fprintf(archivo, "\n");
    }
}

void guardarMatrices(const char* nombre, int m[N][N]) {
    FILE* archivo = fopen(nombre, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }
    escribirMatriz(archivo, m);
    fclose(archivo);
}







#endif