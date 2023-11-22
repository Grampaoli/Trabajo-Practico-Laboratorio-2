#ifndef LISTAINGRESOS_H_INCLUDED
#define LISTAINGRESOS_H_INCLUDED
#include "listaPracXIngreso.h"
typedef struct{

    int DniEmpleado;
    char ApellidoYnombreEmpleado[40];
    char Usuario[20];
    char Contraseña[20];
    char perfil[20];

}empleadoLab;


typedef struct{
    int NroIngreso;
    char FechaIngreso[10];
    char FechaRetiro[10];
    int DniPaciente;
    int MatriculaProfesional;
    int Eliminado = 0;

}ingreso;

typedef struct nodoIngreso{

    ingreso Ingreso;
    nodoPracXIngreso * listaPracXingreso;
    nodoIngreso* anterior;
    nodoIngreso* siguiente;

}nodoIngreso;

nodoIngreso* inicListaDIngreso();
nodoIngreso* crearNodoDIngreso(ingreso UnIngreso);


#endif // LISTAINGRESOS_H_INCLUDED
