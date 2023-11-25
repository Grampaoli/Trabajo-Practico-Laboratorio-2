#ifndef LISTAPRACXINGRESO_H_INCLUDED
#define LISTAPRACXINGRESO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct{
    int NroPract;
    char nombrePract[30];
    int Eliminado;
}practicaLab;

typedef struct{

    int NroIngreso;
    int NroPractica;
    char resultado[40];

}pracXIngreso;

typedef struct nodoPracXIngreso{

    pracXIngreso practicaXIngreso;
    struct nodoPracXIngreso * siguiente;

}nodoPracXIngreso;

nodoPracXIngreso * inicListaPracXIngreso();
pracXIngreso crearUnaPracXingreso(pracXIngreso UnaPracIng);
nodoPracXIngreso * crearNodoPracXingreso(pracXIngreso PracticasXingreso);
nodoPracXIngreso * AgregarPpioPracXingreso(nodoPracXIngreso* listaPracXingreso,nodoPracXIngreso * nuevoNodoPracIngreso);
void mostrarUnNodoPrac(nodoPracXIngreso* nodoAux);
void mostrarListaPracXingreso(nodoPracXIngreso* listaIngreso);
int ArchToPrac(practicaLab Practicas[]);

#endif // LISTAPRACXINGRESO_H_INCLUDED
