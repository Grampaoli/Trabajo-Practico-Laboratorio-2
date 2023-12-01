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
    printf("      Datos de practicas por ingreso----------->\n");
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



void ArchToPrac(practicaLab Practicas[],int* validosPracticas)
{
    FILE* arch = fopen("las_Practicas","rb");

    practicaLab auxPr;


    if(arch != NULL){

        while(fread(&auxPr,sizeof(practicaLab),1,arch)>0)
        {

            Practicas[(*validosPracticas)].NroPract = auxPr.NroPract;
            strcpy(Practicas[(*validosPracticas)].nombrePract,&auxPr.nombrePract);
            Practicas[(*validosPracticas)].Eliminado = auxPr.Eliminado;
            (*validosPracticas)++;
        }
    }

    fclose(arch);



}



practicaLab crearPractica()
{
    practicaLab UnaPractica;

    printf("Ingrese Numero de practica: ");
    scanf("%i",&UnaPractica.NroPract);
    printf("\n");
    printf("Ingrese el nombre de la practica: ");
    fflush(stdin);
    gets(&UnaPractica.nombrePract);
    UnaPractica.Eliminado = 0;

    return UnaPractica;
}

void darAltaAgregarUnaPractica(practicaLab Practicas[],int* validosPracticas){

    practicaLab UnaPractica;
    char seguir = 's';
    int i;
    int flag;

    while(seguir == 's' && (*validosPracticas)<CANTMAXPRACTICAS)
    {
        i = *validosPracticas;
        UnaPractica = crearPractica();

        flag = buscarUnaPractica(Practicas,i,UnaPractica);
        if(flag == 0)
        {
            insertarOPractica(Practicas,i-1,UnaPractica);
            (*validosPracticas)++;

        }else{printf("Ya se encontro esa practica ingrese una nueva");}

        printf("Desea agregar otra practia ? S/N:  ");
        fflush(stdin);
        scanf("%c",&seguir);
    }



}
void insertarOPractica(practicaLab Practicas[],int ultimaPos,practicaLab UnaPractica)
{
    int i = ultimaPos;
    while(i>=0 && (strcmp(UnaPractica.nombrePract,Practicas[i].nombrePract)<0))
    {
        Practicas[i+1] = Practicas[i];
        i--;
    }
    Practicas[i+1] = UnaPractica;

}


int buscarUnaPractica(practicaLab Practicas[],int validos,practicaLab UnaPractica)
{
    int i = 0;
    int flag = 0;


    while(i<validos && flag == 0)
    {
        if(Practicas[i].nombrePract == UnaPractica.nombrePract && Practicas[i].Eliminado == 0)
        {
            flag = 1;
        }
        i++;
    }
    return flag;
}




void persistirPracticas(practicaLab Practicas[],int validos)
{
    FILE *arch = fopen("Las_Practicas", "wb");

     practicaLab UnaPrac;

    if(arch != NULL)
    {

        for(int i = 0;i<validos;i++)
        {


            UnaPrac.NroPract = Practicas[i].NroPract;
            strcpy(&UnaPrac.nombrePract,Practicas[i].nombrePract);
            UnaPrac.Eliminado = Practicas[i].Eliminado;
         fwrite(&UnaPrac,sizeof(practicaLab),1,arch);
        }

    }else{

     printf("No se abrio el archivo");
    }

  fclose(arch);

}
