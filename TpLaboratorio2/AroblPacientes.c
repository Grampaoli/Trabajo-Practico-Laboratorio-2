#include "ArbolPacientes.h"
#include "ListaIngresos.h"
#include "listaPracXIngreso.h"

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
        mostrarUnNodoArbol(arbolPac);
        inOrderArbolPac(arbolPac->der);

    }

}

void mostrarUnNodoArbol(nodoArbol* arbolPac)
{
        printf("Datos del paciente------ \n");
        printf("Apellido y nombre: %s\n",arbolPac->Paciente.ApellidoYNombe);
        printf("Edad: %i \n",arbolPac->Paciente.Edad);
        printf("DNI: %i\n",arbolPac->Paciente.Dni);
        printf("Direccion: %s\n",arbolPac->Paciente.Direccion);
        printf("Telefono: %s\n",arbolPac->Paciente.Telefono);
        printf("-------------------------------------------------------------------------\n");
        mostrarListaIngreso(arbolPac->listaIngresos);

}

nodoArbol* buscarNodoArbolPac(nodoArbol * arbolPac,paciente UnPaciente){ //esta funcion busca un nombre segun el critero de ordenamiento haciendo eficiente la busqueda

nodoArbol * rta=NULL;

    if(arbolPac!=NULL)
    {
        if(strcmp(arbolPac->Paciente.ApellidoYNombe,UnPaciente.ApellidoYNombe) == 0 ){
            rta = arbolPac;
        }
        else{
            if(strcmp(UnPaciente.ApellidoYNombe,arbolPac->Paciente.ApellidoYNombe)>0)
            {
            rta = buscarNodoArbolPac(arbolPac->der,UnPaciente);
            }
            else{
            rta = buscarNodoArbolPac(arbolPac->izq,UnPaciente);
            }
        }

    }

        return rta;


}

nodoArbol* buscarNodoArbolPacDni(nodoArbol * arbolPac,int Dni,nodoArbol * rta){


    if(arbolPac!=NULL)
    {

       rta = buscarNodoArbolPacDni(arbolPac->izq,Dni,rta);
        if(arbolPac->Paciente.Dni == Dni)
        {
            rta = arbolPac;
            return rta;

        }
       rta = buscarNodoArbolPacDni(arbolPac->der,Dni,rta);

    }

return rta;

}

nodoArbol* cargarUnPacienteAlNodo(nodoArbol* arbolPac)
{



    ingreso UnIngreso;
    paciente UnPaciente;
    pracXIngreso UnaPracIng;


    char seguir = 's';

    while(seguir == 's')
    {
        UnPaciente = crearUnPaciente(UnPaciente);
        UnIngreso.DniPaciente = UnPaciente.Dni;
        UnIngreso = crearIngreso(UnIngreso);
        fflush(stdin);
        UnaPracIng.NroIngreso = UnIngreso.NroIngreso;
        UnaPracIng = crearUnaPracXingreso(UnaPracIng);
        fflush(stdin);

        arbolPac = AltaDePacienteIngresar(arbolPac,UnPaciente,UnIngreso,UnaPracIng);

        printf("Desea seguir agregando datos ?\n");
        fflush(stdin);
        scanf("%c",&seguir);

    }
}


paciente crearUnPaciente(paciente UnPaciente){


        printf("Ingrese los datos del paciente:\n");
        printf("Nombre y apellido: ");
        fflush(stdin);
        gets(&UnPaciente.ApellidoYNombe);
        printf("\n");
        printf("Edad : ");
        scanf("%i",&UnPaciente.Edad);
        printf("\n");
        printf("DNI : ");
        fflush(stdin);
        scanf("%i",&UnPaciente.Dni);
        printf("\n");
        printf("Direccion: ");
        fflush(stdin);
        gets(&UnPaciente.Direccion);
        printf("\n");
        printf("Telefono: ");
        fflush(stdin);
        gets(&UnPaciente.Telefono);
        printf("\n");
        UnPaciente.Eliminado = 0;


    return UnPaciente;
}


nodoArbol* AltaDePacienteIngresar(nodoArbol* arbolPac,paciente UnPaciente,ingreso UnIngreso,pracXIngreso UnaPracIng){
    nodoArbol* rta = inicArbol();

    rta = buscarNodoArbolPacDni(arbolPac,UnPaciente.Dni,rta);

    if(rta ==NULL){
     nodoArbol* nuevoNodo = crearNodoArbol(UnPaciente);
     nuevoNodo->listaIngresos = altaDeIngreso(nuevoNodo->listaIngresos,UnIngreso,UnaPracIng);
     arbolPac = insertarNodoArbol(arbolPac,nuevoNodo);

    }else{
       rta->listaIngresos =  altaDeIngreso(rta->listaIngresos,UnIngreso,UnaPracIng);
    }


    return arbolPac;

}
