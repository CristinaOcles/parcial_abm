#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct
{
    int idOrquest;
    char nombre[50];
    char lugar[100];
    int tipo;
    int isEmpty;

}eOrquesta;


int orquesta_Inicializar(eOrquesta array[], int size);
int orquesta_buscarEmpty(eOrquesta array[], int size, int* posicion);
int orquesta_buscarID(eOrquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_alta(eOrquesta array[], int size, int* contadorID);
int orquesta_imprimir(eOrquesta array[], int size);
int orquesta_baja(eOrquesta array[], int sizeArray);
