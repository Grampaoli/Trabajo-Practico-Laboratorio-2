#include "ListaIngresos.h"

nodoIngreso* inicListaDIngreso(){
    return NULL;
}

nodoIngreso* crearNodoDIngreso(ingreso UnIngreso){

    nodoIngreso * auxListaD = (nodoIngreso*)malloc(sizeof(nodoIngreso));
    auxListaD->Ingreso.DniPaciente = UnIngreso.DniPaciente;
    auxListaD->Ingreso.Eliminado = UnIngreso.Eliminado;
    auxListaD->Ingreso.MatriculaProfesional = UnIngreso.MatriculaProfesional;
    strcpy(auxListaD->Ingreso.FechaIngreso,UnIngreso.FechaIngreso);
    strcpy(auxListaD->Ingreso.FechaRetiro,UnIngreso.FechaRetiro);
    auxListaD->listaPracXingreso = inicListaPracXIngreso();
    auxListaD->siguiente = NULL;
    auxListaD->anterior = NULL;

    return auxListaD;
}
