#include "listaPracXIngreso.h"
nodoPracXIngreso * inicListaPracXIngreso(){
    return NULL;
}


pracXIngreso crearUnaPracXingreso(pracXIngreso UnaPracIng)
{

        printf("Ingrese Numero de practica: ");
        scanf("%i",&UnaPracIng.NroPractica);
        printf("\n");
        printf("Ingrese resultado de la practica: ");
        fflush(stdin);
        gets(&UnaPracIng.resultado);
        printf("\n");

        return UnaPracIng;
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
    printf("      Datos de practicas por ingreso-----------\n");
    printf("      Numero de ingreso: %i\n",nodoAux->practicaXIngreso.NroIngreso);
    printf("      Numero de practica: %i\n",nodoAux->practicaXIngreso.NroPractica);
    printf("      Resultado de la Practica: %s\n",nodoAux->practicaXIngreso.resultado);
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

int ArchToPrac(practicaLab Practicas[])
{
    FILE* arch = fopen("lasPracticas","rb");
    int validos = 0;
    practicaLab auxPr;


    if(arch == NULL){

        while(fread(&auxPr,sizeof(practicaLab),1,arch)>0)
        {

            Practicas[validos] = auxPr;
            validos++;
        }
    }



    fclose(fclose);


    return validos;
}


