#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int idMusi;
    char nombre[50];
    char apellido[50];
    int edad;
    int idOrquesta;
    int idInstrumento;
    int isEmpty;

}eMusico;

int musico_Inicializar(eMusico array[], int size);
int musico_buscarEmpty(eMusico array[], int size, int* posicion);
int musico_buscarID(eMusico array[], int size, int valorBuscado, int* posicion);
int musico_alta(eMusico array[], int size, int* contadorID);
int musico_baja(eMusico array[], int sizeArray);
int musico_imprimir(eMusico array[], int size);
