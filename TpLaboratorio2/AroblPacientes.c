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

nodoArbol* AltaDePacienteIngresar(nodoArbol* arbolPac){
    nodoArbol* rta = inicArbol();
    paciente UnPaciente;
    char seguir ='s';
    nodoArbol* aux = inicArbol();
    int Dni;
    while(seguir == 's')
    {

        printf("Ingrese los datos del paciente:\n");
        do{
        printf("Nombre y apellido: ");
        fflush(stdin);
        gets(&UnPaciente.ApellidoYNombe);
        rta = buscarNodoArbolPac(arbolPac,UnPaciente);
        if(rta != NULL)
        {
            printf("\n");
            printf("ese paciente ya fue ingresado ingrese otro paciente\n");
        }
        }while(rta != NULL);
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

        Dni = UnPaciente.Dni;
        aux = crearNodoArbol(UnPaciente);
        aux->listaIngresos = altaDeIngreso(aux->listaIngresos,Dni);

        arbolPac = insertarNodoArbol(arbolPac,aux);

        printf("\n");

    printf("Desea cargar otro paciente ? S/N");
    fflush(stdin);
    scanf("%c",&seguir);

    }

    return arbolPac;

}
