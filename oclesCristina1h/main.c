#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"

#define SIZEMUSICOS 1000

int main()
{
    int estado;
    int idMusico = 100;
    eMusico music[SIZEMUSICOS];

    usico_Inicializar(music, SIZEMUSICOS);
    musico_alta(music,SIZEMUSICOS,idMusico);




    return 0;
}
