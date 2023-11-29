#ifndef LISTAPRACXINGRESO_H_INCLUDED
#define LISTAPRACXINGRESO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define CANTMAXEMPLEADOS 50
#define ADMINISTRADOR "Administrador"
#define TECNICO "Tecnico"
#define ADMINISTRATIVO "Administrativo"
#define BIOQUIMICO "Bioquimico"
#define CANTMAXPRACTICAS 200




typedef struct{
    int NroPract;
    char nombrePract[60];
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
void ArchToPrac(practicaLab Practicas[],int* validos);

void darAltaAgregarUnaPractica(practicaLab Practicas[],int* validosPracticas);
void insertarOPractica(practicaLab Practicas[],int ultimaPos,practicaLab UnaPractica);
int buscarUnaPractica(practicaLab Practicas[],int validos,practicaLab UnaPractica);
void mostrarPractica(practicaLab Practicas[],int* validosPracticas);
nodoPracXIngreso* buscarUnNodoPrac(nodoPracXIngreso* listaPrac,int dato);
#endif // LISTAPRACXINGRESO_H_INCLUDED
