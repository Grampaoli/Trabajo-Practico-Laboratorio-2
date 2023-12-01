#ifndef ARBOLPACIENTES_H_INCLUDED
#define ARBOLPACIENTES_H_INCLUDED
#include "listaPracXIngreso.h"
#include "ListaIngresos.h"

// Estrucuteras donde se guardan los datos de los pacientes
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


// esta estrcutura es para guardar los datos en el archivo y asi poder persistir Arbol de lista de lista
typedef struct{

    paciente UnPaciente;
    ingreso UnIngreso;
    pracXIngreso UnaPractica;

}pacienteDatos;


nodoArbol* inicArbol();//Inicializa un arbol en NULL
nodoArbol* crearNodoArbol(paciente Paciente); //Crea y devuelve un nodo arbol con un Paciente
nodoArbol* insertarNodoArbol(nodoArbol* arbolPac, nodoArbol* nuevoNodo); //Inserta en el Arbol Un nodo de tipo arbol
void inOrderArbolPac(nodoArbol* arbolPac,empleadoLab UnEmpleado);//Muestra el arbol IN ORDER
void mostrarSoloNodoArbol(nodoArbol* arbolPac); // esta es la modularizacion de la funcion para mostrar los datos in order
void mostrarUnNodoArbol(nodoArbol* arbolAux,empleadoLab UnEmpleado); //esta funcion solo muestra un arbol
paciente crearUnPaciente(paciente UnPaciente); // esta funcion devuelve y crea un paciente para luego se pueda insertar en el nodo de arbol
// pide ingresar los datos por usuario
nodoArbol* buscarNodoArbolPac(nodoArbol * arbolPac,char UnPaciente[]);// Busca y devuelve un nodo del arbol buscandolo por nombre y apellido
nodoArbol* buscarNodoArbolPacDni(nodoArbol * arbolPac,int Dni,nodoArbol* rta);// busca y devuelve un nodo del arbol buscandolo por dni
nodoArbol* AltaDePacienteIngresar(nodoArbol* arbolPac,paciente UnPaciente,ingreso UnIngreso,pracXIngreso UnaPracIng);//Esta funcion da de alta al paciente
//preguntando si existe y si no lo crea, tambien esta funcion llama a dar alta de la lista

void menuOpcModArbol(); // esta funcion Es imprime en pantalla opciones para modificar un paciente del arbol
nodoArbol* modArbolCatch(nodoArbol* buscadoModif); //Esta opcion pregunta y agarra las opciones que se puedan elegir para modificar un paciente
nodoArbol* modificarSoloNodoArbol(nodoArbol* arbolPac);//Esta funcion te permite modificar un paciente

nodoArbol* darDeBajaUnPaciente(nodoArbol* arbolPac); //esta opcion deja dar de baja un paciente, buscandolo en el arbol y cambiandole el valor
// de eliminado a 1

//aca estan las funciones para modificar una listade ingreso buscandola por nodo y luego que ingreso
void menuOpcListaIngreso(); //imprime que opciones a modificar
nodoIngreso* modIngresoCatch(nodoIngreso* listaIngreso);//maneja la opciones a modificar
nodoArbol* modificarSoloNodoIngreso(nodoIngreso* arbolPac);
//---------------------------------------------------------------------------

//Aca estan las funciones que permiten modificar una Prac x ingreso
void menuOpcionListaPrac();//Imprime opciones a modificar
nodoPracXIngreso* buscarUnNodoPrac(nodoPracXIngreso* listaPrac,int dato);//aca se puede buscar una prac en el arbol para saber si existe o no
nodoPracXIngreso * modCatchPractica(nodoPracXIngreso* buscadoModPracLista);//maneja la opcion a modificar
nodoArbol* modificarSoloNodoPractica(nodoArbol* arbolPac);


nodoArbol* darBajaIngresoYPrac(nodoArbol* arbolPac);//permite dar de baja un ingreso y su practica cambiandole a Lista->ingreso.elimando a 1

void recorrerListaPrac(nodoPracXIngreso* listaPrac,int UnaPrac,int* flag);//funcion que recorre la lista de practicas x ingreso
void recorrerListaIngresoYbuscarPrac(nodoIngreso* listaIngreso,int UnaPrac,int* flag);//Esta funcion recorre las lista por ingreso buscando una practica
void recorrerArbolYbuscarPrac(nodoArbol* arbolPac,int UnaPrac,int* flag);//esta funcion recorre el arbol para encontrar la lista y luego la prac
//las 3 funciones anterior comprenden 1 sola son todas modularizaciones

void darDeBajaUnaPractica(nodoArbol* arbolPac,practicaLab Practicas[],int validosPracticas);//Te permite dar debaja una practica siempre y cuando
// no se encuentre en un ingreso

//persistencia de datos del arbol
void guardarArbolEnArch(nodoArbol* arbolPac,FILE* archA);
void recorrerYescribirEnArbol(nodoArbol* arbolPac,FILE* archA);
void persistirDatosDelArbol(nodoArbol* arbolPac);
//---------------------------------------------------------------------

//esta funcion lee los datos guardados y los pone en el arbol para usarlos en el sistema
nodoArbol* guardarDatosArchiEnArbol(nodoArbol* arbolPac);

//funciones que maneja la interfaz de usuario
void ingresarSistema(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosPracticas,empleadoLab Empleados[],int* validosEmpleados);
void checkearUsuario(nodoArbol* arbolPac,empleadoLab Empleados[],int* validosEmpleados,practicaLab Practicas[],int* validosPracticas);


void sistemaModoAdministrativo(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosP,empleadoLab Empleados[],int* validosE);

void menuDeSistemaTecnico();
void sistemaModoTecnico(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosP,empleadoLab Empleados[],int* validosE);

void menuDeSistemaAdministrador();
void sistemaModoAdministrador(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosPracticas,empleadoLab Empleados[],int* validosEmpleados);
#endif // ARBOLPACIENTES_H_INCLUDED

