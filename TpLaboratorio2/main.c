#include <stdio.h>
#include <stdlib.h>
#include "ArbolPacientes.h"


int main()
{

        nodoArbol* arbolPac = inicArbol();
       arbolPac = cargarUnPacienteAlNodo(arbolPac);

       // arbolPac = modificarSoloNodoIngreso(arbolPac);
       // arbolPac = modificarSoloNodoPractica(arbolPac);
      // arbolPac = darBajaIngresoYPrac(arbolPac);
     //   mostrarUnNodoArbol(arbolPac);

       // arbolPac = modificarSoloNodoArbol(arbolPac);
       // arbolPac = darDeBajaUnPaciente(arbolPac);

       // empleadoLab EMPLEADOS[CANTMAXEMPLEADOS];
       // int* validosEmpleados = 0;

       // darAltaAgregarUnEmpleado(EMPLEADOS,&validosEmpleados);
       // mostrarEmpleados(EMPLEADOS,&validos);
        practicaLab PRACTICAS[CANTMAXPRACTICAS];
        int* validosPracticas = 0;

       darAltaAgregarUnaPractica(PRACTICAS,&validosPracticas);
        mostrarPractica(PRACTICAS,&validosPracticas);

    darDeBajaUnaPractica(arbolPac,PRACTICAS,&validosPracticas);
    printf("%i",PRACTICAS[0].Eliminado);

    return 0;
}
