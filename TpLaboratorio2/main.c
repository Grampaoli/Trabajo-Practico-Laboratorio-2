#include <stdio.h>
#include <stdlib.h>
#include "ArbolPacientes.h"


int main()
{

    // ESTAS FUNCIONES SON NECESARIAS PARA EL CORRECTO FUNCIONAMIENTO DEL SISTEMA
        practicaLab PRACTICAS[CANTMAXPRACTICAS];
        int* validosPracticas = 0;
        ArchToPrac(PRACTICAS,&validosPracticas); //CARGA LAS PRACTICAS GUARDADAS

        empleadoLab EMPLEADOS[CANTMAXEMPLEADOS];
        int* validosEmpleados = 0;
        archToEmpleado(EMPLEADOS,&validosEmpleados); // CARGA LOS EMPLEADOS GUARDADOS

        nodoArbol* arbolPac = inicArbol();
        arbolPac = guardarDatosArchiEnArbol(arbolPac);

        checkearUsuario(arbolPac,EMPLEADOS,validosEmpleados,PRACTICAS,validosPracticas);

   //------------------------------------------------------------------->

      // darAltaAgregarUnaPractica(PRACTICAS,&validosPracticas);
       // persistirPracticas(PRACTICAS,validosPracticas);

       // mostrarPractica(PRACTICAS,&validosPracticas);


      // arbolPac = cargarUnPacienteAlNodo(arbolPac);

       // persistirDatosDelArbol(arbolPac);

       // arbolPac = modificarSoloNodoIngreso(arbolPac);
       // arbolPac = modificarSoloNodoPractica(arbolPac);
      // arbolPac = darBajaIngresoYPrac(arbolPac);
      // mostrarUnNodoArbol(arbolPac);

       // arbolPac = modificarSoloNodoArbol(arbolPac);
       // arbolPac = darDeBajaUnPaciente(arbolPac);


       // darAltaAgregarUnEmpleado(EMPLEADOS,&validosEmpleados);
       // mostrarEmpleados(EMPLEADOS,&validosEmpleados);

       // empleadosToArch(EMPLEADOS,validosEmpleados);
  //  darDeBajaUnaPractica(arbolPac,PRACTICAS,&validosPracticas);



    return 0;
}
