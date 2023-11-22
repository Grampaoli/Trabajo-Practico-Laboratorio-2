#include "listaPracXIngreso.h"
nodoPracXIngreso * inicListaPracXIngreso(){
    return NULL;
}

nodoPracXIngreso * crearNodoPracXingreso(pracXIngreso UnaPractica){
    nodoPracXIngreso* auxPrac = (nodoPracXIngreso*)malloc(sizeof(nodoPracXIngreso));
    auxPrac->practicaXIngreso.NroIngreso = UnaPractica.NroIngreso;
    auxPrac->practicaXIngreso.NroPractica = UnaPractica.NroPractica;
    strcpy(auxPrac->practicaXIngreso.resultado,UnaPractica.resultado);
    auxPrac->siguiente = NULL;

    return auxPrac;
}

