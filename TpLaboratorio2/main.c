#include <stdio.h>
#include <stdlib.h>
#include "ArbolPacientes.h"
#include "listaPracXIngreso.h"

int main()
{

    char seguir = 's';
    nodoArbol * arbolPac;
    arbolPac = inicArbol();
    paciente UnPaciente;

    while(seguir == 's')
    {
        nodoArbol * aux = inicArbol();
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

        arbolPac = insertarNodoArbol(arbolPac,crearNodoArbol(UnPaciente));
        printf("\n");

    printf("Desea seguir cargando datos ? S/N");
    fflush(stdin);
    scanf("%c",&seguir);

    }

    inOrderArbolPac(arbolPac);
    char dato[20];
    int i = 0;

    while(i<3)
    {
    printf("Ingrese un Dni a buscar :");
    fflush(stdin);
    gets(&dato);
    printf("\n");
    printf("%s",dato);
    nodoArbol * rta;
    rta = buscarNodoArbolPac(arbolPac,dato);
    if(rta !=NULL)
    {
        mostrarUnNodo(rta);
    }else{
        printf("No se encontro un paciente con ese DNI\n");
    }
    i++;
    }

    return 0;
}
