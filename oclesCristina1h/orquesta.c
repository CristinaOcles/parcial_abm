
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"



int orquesta_Inicializar(eOrquesta array[], int size)
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

int orquesta_buscarEmpty(eOrquesta array[], int size, int* posicion)
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



int orquesta_buscarID(eOrquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquest==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int orquesta_alta(eOrquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    int retornoName;
    int retornoLugar;
    int retornoTipo;


    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idOrquest=*contadorID;
            array[posicion].isEmpty=0;


            retornoName = utn_getName("\nIngrese nombre: ","\nError",1,20,1,array[posicion].nombre);
            retornoLugar = utn_getName("\nIngrese lugar: ","\nError",1,20,1,array[posicion].apellido);
            retornoTipo = utn_getSignedInt("\nIngrese tipo: ", "\n edad invalida",1,99,1,4,3,array[posicion].edad);



            if(!(retornoName && retornoTipo && retornoLugar))
            {
                printf("\nAlta exitosa\n\n");
                    retorno=0;
            }

        }
    }
    return retorno;
}



    int orquesta_imprimir(eOrquesta array[], int size)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
              printf("\n id        nombre      lugar   tipo ");
              printf("\n %d         %s           %s      %d ", array[i].idOrquest, array[i].nombre, array[i].lugar, array[i].tipo);
                retorno = 0;
            }
        }
    }
    return retorno;
}



int orquesta_baja(eOrquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int retor;
    if(array!=NULL && sizeArray>0)
    {
        retor = orquesta_imprimir(array, sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
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
