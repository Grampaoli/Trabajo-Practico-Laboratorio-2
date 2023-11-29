#include <stdio.h>
#include <stdlib.h>
#include "ArbolPacientes.h"


int main()
{
        practicaLab PRACTICAS[CANTMAXPRACTICAS];
        int* validosPracticas = 0;
        ArchToPrac(PRACTICAS,&validosPracticas);


       //darAltaAgregarUnaPractica(PRACTICAS,&validosPracticas);
       // persistirPracticas(PRACTICAS,validosPracticas);

        //mostrarPractica(PRACTICAS,&validosPracticas);

      //  nodoArbol* arbolPac = inicArbol();
      // arbolPac = cargarUnPacienteAlNodo(arbolPac);

       // arbolPac = modificarSoloNodoIngreso(arbolPac);
       // arbolPac = modificarSoloNodoPractica(arbolPac);
      // arbolPac = darBajaIngresoYPrac(arbolPac);
     //   mostrarUnNodoArbol(arbolPac);

       // arbolPac = modificarSoloNodoArbol(arbolPac);
       // arbolPac = darDeBajaUnPaciente(arbolPac);

        empleadoLab EMPLEADOS[CANTMAXEMPLEADOS];
        int* validosEmpleados = 0;
        archToEmpleado(EMPLEADOS,&validosEmpleados);
       // darAltaAgregarUnEmpleado(EMPLEADOS,&validosEmpleados);
        mostrarEmpleados(EMPLEADOS,&validosEmpleados);
       // empleadosToArch(EMPLEADOS,validosEmpleados);
  //  darDeBajaUnaPractica(arbolPac,PRACTICAS,&validosPracticas);


    return 0;
}
