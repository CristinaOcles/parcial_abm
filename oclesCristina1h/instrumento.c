
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "instrumento.h"




int instrumento_Inicializar(eInstrumento array[], int size)
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

int instrumento_buscarEmpty(eInstrumento array[], int size, int* posicion)
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



int instrumento_buscarID(eInstrumento array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idIns==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int instrumento_alta(eInstrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    int retornoName;
    int retornoTipo;


    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idIns=*contadorID;
            array[posicion].isEmpty=0;


            retornoName = utn_getName("\nIngrese nombre: ","\nError",1,20,1,array[posicion].nombre);
            retornoTipo = utn_getName("\nIngrese lugar: ","\nError",1,20,1,array[posicion].tipo);




            if(!(retornoName && retornoTipo))
            {
                printf("\nAlta exitosa\n\n");
                    retorno=0;
            }

        }
    }
    return retorno;
}



    int instrumento_imprimir(eInstrumento array[], int size)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
              printf("\n id        nombre      lugar  ");
              printf("\n %d         %s           %s       ", array[i].idIns, array[i].nombre, array[i].tipo);
                retorno = 0;
            }
        }
    }
    return retorno;
}



int instrumento_baja(eInstrumento array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int retor;
    if(array!=NULL && sizeArray>0)
    {
        retor = instrumento_imprimir(array, sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,3,3,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
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

