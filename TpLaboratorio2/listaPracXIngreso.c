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

nodoPracXIngreso * AgregarPpioPracXingreso(nodoPracXIngreso* listaPracXingreso,nodoPracXIngreso * nuevoNodoPracIngreso)
{
    if(listaPracXingreso == NULL)
    {
        listaPracXingreso = nuevoNodoPracIngreso;

    }else{

     nuevoNodoPracIngreso->siguiente = listaPracXingreso;
     listaPracXingreso = nuevoNodoPracIngreso;
    }

    return listaPracXingreso;
}

void mostrarUnNodoPrac(nodoPracXIngreso* nodoAux)
{
    printf("      //////////////////////////////////////////////////////////////\n");
    printf("      Datos de practicas por ingreso-----------\n");
    printf("      Numero de ingreso: %i\n",nodoAux->practicaXIngreso.NroIngreso);
    printf("      Numero de practica: %i\n",nodoAux->practicaXIngreso.NroPractica);
    printf("      Resultado de practica: %s\n",nodoAux->practicaXIngreso.resultado);
    printf("      ---------------------------------------------------\n");
}

void mostrarListaPracXingreso(nodoPracXIngreso* listaIngreso)
{
    nodoPracXIngreso* seg = listaIngreso;

    while(seg !=NULL)
    {
        mostrarUnNodoPrac(seg);
        seg = seg->siguiente;
    }

}

nodoPracXIngreso* altaDePractica(nodoPracXIngreso* listaPracXingreso,int NroIngreso)
{
    char seguir = 's';
    pracXIngreso practDingres;
    nodoPracXIngreso* ingresoBuscado = inicListaDIngreso();
    nodoPracXIngreso* auxNuevo = inicListaDIngreso();
    int dato;
    while(seguir == 's')
    {
        printf("Ingrese Numero de practica: ");
        scanf("%i",&practDingres.NroPractica);
        printf("\n");
        printf("Ingrese resultado de la practica: ");
        fflush(stdin);
        gets(&practDingres.resultado);
        printf("\n");
        practDingres.NroIngreso = NroIngreso;

        auxNuevo = crearNodoPracXingreso(practDingres);

        listaPracXingreso = AgregarPpioPracXingreso(listaPracXingreso,auxNuevo);

        printf("Desea cargarle otra practica al paciente ? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        printf("\n");


    }

    return listaPracXingreso;
}
