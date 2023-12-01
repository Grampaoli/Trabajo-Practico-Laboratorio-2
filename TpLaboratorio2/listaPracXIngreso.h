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



//Estructura que maneja la lista de practica y todas sus variables, tambien se encuentra la estructura de Practicas
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
//---------------------------------------------------------------------------

nodoPracXIngreso * inicListaPracXIngreso();//Inicializa una lista de practicas x ingreso
pracXIngreso crearUnaPracXingreso(pracXIngreso UnaPracIng);//crea un nodo una practicaxIngreso
nodoPracXIngreso * crearNodoPracXingreso(pracXIngreso PracticasXingreso);//Crea un nodo de practica por ingreso para inicializar sus valores
nodoPracXIngreso * AgregarPpioPracXingreso(nodoPracXIngreso* listaPracXingreso,nodoPracXIngreso * nuevoNodoPracIngreso);//agrega al principio de la lista
void mostrarUnNodoPrac(nodoPracXIngreso* nodoAux);//Modularizacion para mostrar un nodo de prac
void mostrarListaPracXingreso(nodoPracXIngreso* listaIngreso);//Recorre la lista de prac para mostrar todos sus nodos
void ArchToPrac(practicaLab Practicas[],int* validos);//lectura de las parccticas guardadas en un archivo

//funciones que manejan el arreglo de practicas
void darAltaAgregarUnaPractica(practicaLab Practicas[],int* validosPracticas);//Funcion que da de alta una practica preguntando si existe la misma x numero de practica
void insertarOPractica(practicaLab Practicas[],int ultimaPos,practicaLab UnaPractica);//Funcion que inserta una practica en orden en el arreglo de practica
//----------------------------------------------------------------------------------------
int buscarUnaPractica(practicaLab Practicas[],int validos,practicaLab UnaPractica);//esta funcion busca una practica para preguntar si existe
nodoPracXIngreso* buscarUnNodoPrac(nodoPracXIngreso* listaPrac,int dato);//Busca un nodo de prac para devolverlo y asi poder trabajar con el
#endif // LISTAPRACXINGRESO_H_INCLUDED
