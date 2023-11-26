#include <stdio.h>
#include <stdlib.h>
#include "ArbolPacientes.h"


int main()
{

        //nodoArbol* arbolPac = inicArbol();
       // arbolPac = cargarUnPacienteAlNodo(arbolPac);
       // practicaLab Practicas[100];
       // int validos;
       // validos = ArchToPrac(Practicas);

        empleadoLab Empleados[CANTMAXEMPLEADOS];
        int* validos = 0;

        darAltaAgregarUnEmpleado(Empleados,&validos);
        mostrarEmpleados(Empleados,&validos);

    return 0;
}
