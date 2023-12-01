#ifndef LISTAINGRESOS_H_INCLUDED
#define LISTAINGRESOS_H_INCLUDED
#include "listaPracXIngreso.h"


//estructuras que permite el manejo de Los empleados del laboratorio y los ingresos que se guardan en el arbol

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


nodoIngreso* inicListaDIngreso(); // Inicializa la lista de ingresos en NULL
nodoIngreso* crearNodoDIngreso(ingreso UnIngreso);//Crea un nodo de ingresos y inicializa sus valores
nodoIngreso* agregarPpioListaIngreso(nodoIngreso* listaIngreso, nodoIngreso * nuevoNodoIngreso);//Agrega los nodo de la lista al principio de la lista

void mostrarSoloUnNodoIngreso(nodoIngreso* nodoAux);//Modularizacion que muestra 1 node siendo recorrido dentro de mostrarLista ingreso
void mostrarUnNOdoIngreso(nodoIngreso * nodoAux,empleadoLab UnEmpleado);//funcion suelta que muestra 1 nodo de una lista
void mostrarListaIngreso(nodoIngreso * listaIngreso,empleadoLab UnEmpleado);//funcion que recorre y muestra lista
nodoIngreso* buscarIngreso(nodoIngreso* listaIngreso,int dato);//busca un ingreso dentro de la lista de ingresos
nodoIngreso* altaDeIngreso(nodoIngreso* listaIngreso,ingreso UnIngreso,pracXIngreso UnaPracIng);//funcion que da de alta un ingreso buscandolos por nro de ingreesos
//esta funcion tambien llama a dar de alta practicas x ingreso

ingreso crearIngreso(ingreso UnIngreso);//crea un ingreso para despues se agrege al la lista


//Fucniones que manejan la creacion del arreglo de empleados
empleadoLab crearEmpleado();
void darAltaAgregarUnEmpleado(empleadoLab Empleados[],int* validosEmpleados);
void insertarEmpleado(empleadoLab Empleados[],int ultimaPos,empleadoLab UnEmpleado);
int buscarUnEmpleado(empleadoLab Empleados[],int validos,empleadoLab UnEmpleado);

void modificarUnEmpleado(empleadoLab Empleados[],int validos);//funcion que permite modificar un empleado
void mostrarEmpleados(empleadoLab Empleados[],int validosEmpleados,empleadoLab UnEmpleado);//Funcion que recorre el arreglo de empleados y lo muestra

//Fucnciones de percistencia del arreglo de empleados
void empleadosToArch(empleadoLab Empleados[],int validosEmpleados);//lo guarda en un archivo
void archToEmpleado(empleadoLab Empleados[],int* validosEmpleados);//lo lee del archivo y lo guarda en el arreglo

empleadoLab buscarUnEmpleadoYConstrasena(empleadoLab Empleados[],int validos,empleadoLab UnEmpleado,int* flag);//busca un empleado
//para validar usuario y contrasena

void mostrarPractica(practicaLab Practicas[],int validosPracticas,empleadoLab UnEmpleado);//muestra el arreglo de practica segun que perfil de empleado
//exista




#endif // LISTAINGRESOS_H_INCLUDED
