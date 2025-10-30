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
            printf("%d ", matriz[i][j]);
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

void guardar2operaciones(FILE* archivo, int mA[N][N], int mB[N][N], int mR[N][N]) {
    fprintf(archivo, "Matriz A:\n");
    escribirMatriz(archivo, mA);
    fprintf(archivo, "Matriz B:\n");
    escribirMatriz(archivo, mB);
    fprintf(archivo, "Resultado:\n");
    escribirMatriz(archivo, mR);
    fprintf(archivo, "\n");
}


void logOperacion(Operacion operacion, int mA[N][N], int mB[N][N], int mR[N][N], int escalar)
{
    FILE* archivo = fopen("log.txt", "a");

    switch (operacion) {
        case SUMA:
            fprintf(archivo, "SUMA\n");
            guardar2operaciones(archivo, mA, mB, mR);
            break;
        case RESTA:
            fprintf(archivo, "RESTA\n");
            guardar2operaciones(archivo, mA, mB, mR);
            break;
        case MULTIPLICACION:
            fprintf(archivo, "MULTIPLICACION\n");
            guardar2operaciones(archivo, mA, mB, mR);
            break;
        case PRODUCTO_ESCALAR:
            fprintf(archivo, "PRODUCTO_ESCALAR\n");
            fprintf(archivo, "Matriz A:\n");
            escribirMatriz(archivo, mA);
            fprintf(archivo, "Escalar B:\n%d\n", escalar);
            fprintf(archivo, "Resultado:\n");
            escribirMatriz(archivo, mR);
            fprintf(archivo, "\n");
            break;


        case TRASPUESTA:
            fprintf(archivo, "TRANSPUESTA\n");
            fprintf(archivo, "Matriz A:\n");
            escribirMatriz(archivo, mA);
            fprintf(archivo, "Resultado:\n");
            escribirMatriz(archivo, mR);
            fprintf(archivo, "\n");
            break;

        case SIMETRICA:
            fprintf(archivo, "SIMETRICA\n");
            fprintf(archivo, "Matriz:\n");
            escribirMatriz(archivo, mA);
            fprintf(archivo, "Resultado:\n%d\n", escalar);
            fprintf(archivo, "\n");
            break;

        case CARGA_MATRIZ:
            fprintf(archivo, "CARGA_MATRIZ\n");
            fprintf(archivo, "Matriz:\n");
            escribirMatriz(archivo, mA);
            fprintf(archivo, "\n");
            break;
        case GUARDADO_MATRIZ:
            fprintf(archivo, "GUARDADO_MATRIZ\n");
            fprintf(archivo, "Matriz:\n");
            escribirMatriz(archivo, mA);
            fprintf(archivo, "\n");
            break;
    }
}


#endif