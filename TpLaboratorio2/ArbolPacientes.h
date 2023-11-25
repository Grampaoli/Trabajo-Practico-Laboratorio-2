#ifndef ARBOLPACIENTES_H_INCLUDED
#define ARBOLPACIENTES_H_INCLUDED
#include "ListaIngresos.h"
#include "listaPracXIngreso.h"


typedef struct{
char ApellidoYNombe[40];
int Edad;
int Dni;
char Direccion[30];
char Telefono[15];
int Eliminado;
}paciente;

typedef struct nodoArbol{
paciente Paciente;
struct nodoIngreso* listaIngresos;
struct nodoArbol* izq;
struct nodoArbol* der;
}nodoArbol;



nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(paciente Paciente);
nodoArbol* insertarNodoArbol(nodoArbol* arbolPac, nodoArbol* nuevoNodo); //Para comparar cadenas -1 si la primera menor 1 si la primera mayor y 0 si son iguales (siendo a menor y z mayor de todas)
void inOrderArbolPac(nodoArbol* arbolPac);
void mostrarUnNodoArbol(nodoArbol* arbolAux);
paciente crearUnPaciente(paciente UnPaciente);
nodoArbol* buscarNodoArbolPac(nodoArbol * arbolPac,paciente UnPaciente);
nodoArbol* buscarNodoArbolPacDni(nodoArbol * arbolPac,int Dni,nodoArbol* rta);
nodoArbol* AltaDePacienteIngresar(nodoArbol* arbolPac,paciente UnPaciente,ingreso UnIngreso,pracXIngreso UnaPracIng);
#endif // ARBOLPACIENTES_H_INCLUDED

