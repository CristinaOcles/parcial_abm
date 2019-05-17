#include <stdio.h>
#include <stdlib.h>
#include "musico.h"

#define  CANT_DIG_MIN   1
#define  CANT_DIG_MAX   10

int musico_Inicializar(eMusico array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}


int musico_buscarEmpty(eMusico array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int musico_buscarID(eMusico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusi==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}




int musico_alta(eMusico array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    int retornoName;
    int retornoApellido;
    int retornoEdad;
    int retornoOrques;
    int retornoInstr;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idMusi=*contadorID;
            array[posicion].isEmpty=0;


            retornoName = utn_getName("\nIngrese nombre: ","\nError",1,20,1,array[posicion].nombre);
            retornoApellido = utn_getName("\nIngrese Apellido: ","\nError",1,20,1,array[posicion].apellido);
            retornoEdad = utn_getSignedInt("\nIngrese edad: ", "\n edad invalida",1,99,1,4,3,array[posicion].edad);

            retornoOrques = utn_getSignedInt("\nIngrese ID Orquesta","\nid incorrecta",1,1,3,3,4, array[posicion].idOrquesta);
            retornoInstr = utn_getSignedInt("\nIngrese Id Instrumento", "\nid incorrecta",1,1,4,3,4,array[posicion].idInstrumento);

            if(!(retornoName && retornoApellido && retornoEdad && retornoInstr && retornoOrques))
            {
                printf("\nAlta exitosa\n\n");
                    retorno=0;
            }

        }
    }
    return retorno;
}




int musico_baja(eMusico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int retor;
    if(array!=NULL && sizeArray>0)
    {
        retor = musico_imprimir(array, sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty = 0;


            retorno=0;
        }
    }
    return retorno;

}




    int musico_imprimir(eMusico array[], int size)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
              printf("\n id        nombre      apellido    instrumento");
              printf("\n %d         %s           %s           %d", array[i].idMusi, array[i].nombre, array[i].apellido, array[i].idInstrumento);
                retorno = 0;
            }
        }
    }
    return retorno;
}

