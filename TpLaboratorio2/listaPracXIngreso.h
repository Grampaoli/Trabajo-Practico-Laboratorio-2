#ifndef LISTAPRACXINGRESO_H_INCLUDED
#define LISTAPRACXINGRESO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct{
    int NroPract;
    char nombrePract[30];
    int eliminado = 0;
}practicaLab;

typedef struct{

    int NroIngreso;
    int NroPractica;
    char resultado[40];

}pracXIngreso;

typedef struct nodoPracXIngreso{

    pracXIngreso practicaXIngreso;
    nodoPracXIngreso * siguiente;

}nodoPracXIngreso;

#endif // LISTAPRACXINGRESO_H_INCLUDED
