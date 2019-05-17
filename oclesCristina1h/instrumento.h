#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idIns;
    char nombre[50];
    char tipo[50];
    int isEmpty;

}eInstrumento;


int instrumento_Inicializar(eInstrumento array[], int size);
int instrumento_buscarEmpty(eInstrumento array[], int size, int* posicion);
int instrumento_buscarID(eInstrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_alta(eInstrumento array[], int size, int* contadorID);
int instrumento_imprimir(eInstrumento array[], int size);
int instrumento_baja(eInstrumento array[], int sizeArray);

