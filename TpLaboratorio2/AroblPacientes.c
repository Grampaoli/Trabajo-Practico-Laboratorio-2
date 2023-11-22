#include "ArbolPacientes.h"

nodoArbol* inicArbol(){

 return NULL;
}

nodoArbol* crearNodoArbol(paciente UnPaciente)
{
    nodoArbol* auxArbol = (nodoArbol*)malloc(sizeof(nodoArbol));
    strcpy(auxArbol->Paciente.ApellidoYNombe,UnPaciente.ApellidoYNombe);
    strcpy(auxArbol->Paciente.Direccion,UnPaciente.Direccion);
    strcpy(auxArbol->Paciente.Telefono,UnPaciente.Telefono);
    auxArbol->Paciente.Dni = UnPaciente.Dni;
    auxArbol->Paciente.Edad = UnPaciente.Edad;
    auxArbol->Paciente.Eliminado = UnPaciente.Eliminado;
    auxArbol->listaIngresos = inicListaDIngreso();
    auxArbol->der = NULL;
    auxArbol->izq = NULL;

    return auxArbol;
}

nodoArbol* insertarNodoArbol(nodoArbol* arbolPac,nodoArbol *nuevoNodo){

    if(arbolPac == NULL)
    {
        arbolPac = nuevoNodo;

    }else{

        if(strcmp(nuevoNodo->Paciente.ApellidoYNombe,arbolPac->Paciente.ApellidoYNombe)>0)
        {
            arbolPac->der = insertarNodoArbol(arbolPac->der,nuevoNodo);

        }else{
            arbolPac->izq = insertarNodoArbol(arbolPac->izq,nuevoNodo);
        }

    }

    return arbolPac;
}


void inOrderArbolPac(nodoArbol* arbolPac)
{

    if(arbolPac !=NULL)
    {

        inOrderArbolPac(arbolPac->izq);
        mostrarUnNodo(arbolPac);
        inOrderArbolPac(arbolPac->der);

    }

}

void mostrarUnNodo(nodoArbol* arbolPac)
{
        printf("Datos del paciente------ \n");
        printf("Apellido y nombre: %s\n",arbolPac->Paciente.ApellidoYNombe);
        printf("Edad: %i \n",arbolPac->Paciente.Edad);
        printf("DNI: %i\n",arbolPac->Paciente.Dni);
        printf("Direccion: %s\n",arbolPac->Paciente.Direccion);
        printf("Telefono: %s\n",arbolPac->Paciente.Telefono);
        printf("---------------------------------\n");
}

nodoArbol* buscarNodoArbolPac(nodoArbol * arbolPac,char dato[]){

nodoArbol * rta=NULL;

    if(arbolPac!=NULL)
    {
        if(strcmp(arbolPac->Paciente.ApellidoYNombe,dato) == 0 ){
            rta = arbolPac;
        }
        else{
            if(strcmp(dato,arbolPac->Paciente.ApellidoYNombe)>0)
            {
            rta = buscarNodoArbolPac(arbolPac->der,dato);
            }
            else{
            rta = buscarNodoArbolPac(arbolPac->izq,dato);
            }
        }

    }

        return rta;


}
