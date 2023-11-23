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
    int Dni;
    int i = 0;
    nodoArbol * rta;
    rta = inicArbol();

    while(i<5)
    {
    printf("Ingrese un Dni a buscar :");
    fflush(stdin);
    scanf("%i",&Dni);
    printf("\n");

   rta = buscarNodoArbolPac(arbolPac,Dni,rta);
    if(rta !=NULL)
    {
        printf("Si se encontro el paciente con el dni \n");
        mostrarUnNodo(rta);
    }else{
        printf("No se encontro un paciente con ese DNI\n");
    }
    i++;
    }




    return 0;
}
