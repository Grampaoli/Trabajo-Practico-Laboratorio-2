#ifndef LISTAINGRESOS_H_INCLUDED
#define LISTAINGRESOS_H_INCLUDED
#include "listaPracXIngreso.h"
typedef struct{

    int DniEmpleado;
    char ApellidoYnombreEmpleado[40];
    char Usuario[20];
    char Contrasena[20];
    char perfil[20];

}empleadoLab;


typedef struct{
    int NroIngreso;
    char FechaIngreso[10];
    char FechaRetiro[10];
    int DniPaciente;
    int MatriculaProfesional;
    int Eliminado;

}ingreso;

typedef struct nodoIngreso{

    ingreso Ingreso;
    nodoPracXIngreso * listaPracXingreso;

    struct nodoIngreso* anterior;
    struct nodoIngreso* siguiente;

}nodoIngreso;

nodoIngreso* inicListaDIngreso();
nodoIngreso* crearNodoDIngreso(ingreso UnIngreso);
nodoIngreso* agregarPpioListaIngreso(nodoIngreso* listaIngreso, nodoIngreso * nuevoNodoIngreso);
void mostrarUnNOdoIngreso(nodoIngreso * nodoAux);
void mostrarLista(nodoIngreso * listaIngreso);

#endif // LISTAINGRESOS_H_INCLUDED
