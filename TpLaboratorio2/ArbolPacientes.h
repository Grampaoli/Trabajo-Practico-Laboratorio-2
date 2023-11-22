#ifndef ARBOLPACIENTES_H_INCLUDED
#define ARBOLPACIENTES_H_INCLUDED
#include "ListaIngresos.h"


typedef struct{
char ApellidoYNombe[40];
int Edad;
char Direccion[30];
char Telefono[15];
int Eliminado = 0;
}paciente;

typedef struct nodoArbol{
paciente Paciente;
nodoIngresos* listaIngresos;
struct nodoArbol* izq;
struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(paciente Paciente);
nodoArbol* insertarNodoArbol(nodoArbol* arbolPac, paciente Paciente);


#endif // ARBOLPACIENTES_H_INCLUDED
