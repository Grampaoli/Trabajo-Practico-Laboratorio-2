#ifndef ARBOLPACIENTES_H_INCLUDED
#define ARBOLPACIENTES_H_INCLUDED
#include "listaPracXIngreso.h"
#include "ListaIngresos.h"

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


typedef struct{

    paciente UnPaciente;
    ingreso UnIngreso;
    pracXIngreso UnaPractica;

}pacienteDatos;


nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(paciente Paciente);
nodoArbol* insertarNodoArbol(nodoArbol* arbolPac, nodoArbol* nuevoNodo); //Para comparar cadenas -1 si la primera menor 1 si la primera mayor y 0 si son iguales (siendo a menor y z mayor de todas)
void inOrderArbolPac(nodoArbol* arbolPac);
void mostrarSoloNodoArbol(nodoArbol* arbolPac);
void mostrarUnNodoArbol(nodoArbol* arbolAux);
paciente crearUnPaciente(paciente UnPaciente);
nodoArbol* buscarNodoArbolPac(nodoArbol * arbolPac,char UnPaciente[]);
nodoArbol* buscarNodoArbolPacDni(nodoArbol * arbolPac,int Dni,nodoArbol* rta);
nodoArbol* AltaDePacienteIngresar(nodoArbol* arbolPac,paciente UnPaciente,ingreso UnIngreso,pracXIngreso UnaPracIng);
void arbolAArchivo(nodoArbol* arbol);
void menuOpcModArbol();
nodoArbol* modArbolCatch(nodoArbol* buscadoModif);
nodoArbol* modificarSoloNodoArbol(nodoArbol* arbolPac);

nodoArbol* darDeBajaUnPaciente(nodoArbol* arbolPac);


void menuOpcListaIngreso();
nodoIngreso* modIngresoCatch(nodoIngreso* listaIngreso);
nodoArbol* modificarSoloNodoIngreso(nodoIngreso* arbolPac);



void menuOpcionListaPrac();
nodoPracXIngreso* buscarUnNodoPrac(nodoPracXIngreso* listaPrac,int dato);
nodoPracXIngreso * modCatchPractica(nodoPracXIngreso* buscadoModPracLista);
nodoArbol* modificarSoloNodoPractica(nodoArbol* arbolPac);


nodoArbol* darBajaIngresoYPrac(nodoArbol* arbolPac);

void recorrerListaPrac(nodoPracXIngreso* listaPrac,int UnaPrac,int* flag);
void recorrerListaIngresoYbuscarPrac(nodoIngreso* listaIngreso,int UnaPrac,int* flag);
void recorrerArbolYbuscarPrac(nodoArbol* arbolPac,int UnaPrac,int* flag);
void darDeBajaUnaPractica(nodoArbol* arbolPac,practicaLab Practicas[],int* validosPracticas);

void guardarArbolEnArch(nodoArbol* arbolPac,FILE* archA);
void recorrerYescribirEnArbol(nodoArbol* arbolPac,FILE* archA);
void persistirDatosDelArbol(nodoArbol* arbolPac);

nodoArbol* guardarDatosArchiEnArbol(nodoArbol* arbolPac);

void ingresarSistema(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int validosPracticas);
void checkearUsuario(nodoArbol* arbolPac,empleadoLab Empleados[],int validosEmpleados,practicaLab Practicas[],int validosPracticas);

#endif // ARBOLPACIENTES_H_INCLUDED

