#ifndef LISTAINGRESOS_H_INCLUDED
#define LISTAINGRESOS_H_INCLUDED
#include "listaPracXIngreso.h"
#define ADMINISTRADOR "Administrador"
#define TECNICO "Tecnico"
#define ADMINISTRATIVO "Administrativo"
#define BIOQUIMICO "Bioquimico"

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
void mostrarListaIngreso(nodoIngreso * listaIngreso);
nodoIngreso* buscarIngreso(nodoIngreso* listaIngreso,int dato);
nodoIngreso* altaDeIngreso(nodoIngreso* listaIngreso,ingreso UnIngreso,pracXIngreso UnaPracIng);
ingreso crearIngreso(ingreso UnIngreso);


empleadoLab crearEmpleado();
void darAltaAgregarUnEmpleado(empleadoLab Empleados[],int* validos);
void insertarEmpleado(empleadoLab Empleados[],int ultimaPos,empleadoLab UnEmpleado);
int buscarUnEmpleado(empleadoLab Empleados[],int validos,empleadoLab UnEmpleado);

void mostrarEmpleados(empleadoLab Empleados[],int* validos);

#endif // LISTAINGRESOS_H_INCLUDED
