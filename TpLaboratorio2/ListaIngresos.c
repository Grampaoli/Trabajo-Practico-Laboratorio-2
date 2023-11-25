#include "ListaIngresos.h"

nodoIngreso* inicListaDIngreso(){
    return NULL;
}

nodoIngreso* crearNodoDIngreso(ingreso UnIngreso){

    nodoIngreso * auxListaD = (nodoIngreso*)malloc(sizeof(nodoIngreso));
    auxListaD->Ingreso.DniPaciente = UnIngreso.DniPaciente;
    auxListaD->Ingreso.NroIngreso = UnIngreso.NroIngreso;
    auxListaD->Ingreso.Eliminado = UnIngreso.Eliminado;
    auxListaD->Ingreso.MatriculaProfesional = UnIngreso.MatriculaProfesional;
    strcpy(auxListaD->Ingreso.FechaIngreso,UnIngreso.FechaIngreso);
    strcpy(auxListaD->Ingreso.FechaRetiro,UnIngreso.FechaRetiro);
    auxListaD->listaPracXingreso = inicListaPracXIngreso();
    auxListaD->siguiente = NULL;
    auxListaD->anterior = NULL;

    return auxListaD;
}


nodoIngreso * agregarPpioListaIngreso(nodoIngreso * listaIngreso, nodoIngreso* nuevoNodoIngreso)
{

    if(listaIngreso == NULL)
    {
        listaIngreso = nuevoNodoIngreso;
    }else{

        nuevoNodoIngreso->siguiente = listaIngreso;
        listaIngreso->anterior = nuevoNodoIngreso;
        listaIngreso = nuevoNodoIngreso;

    }

    return listaIngreso;
}
void mostrarUnNodoIngreso(nodoIngreso * nodoAux)
{

    printf("   Datos del ingreso--------\n");
    printf("   Numero de ingreso: %i\n",nodoAux->Ingreso.NroIngreso);
    printf("   Dni del Paciente %i\n",nodoAux->Ingreso.DniPaciente);
    printf("   Matricula del profesional: %i\n",nodoAux->Ingreso.MatriculaProfesional);
    printf("   Fecha de ingreso: %s\n",nodoAux->Ingreso.FechaIngreso);
    printf("   Fecha de Retiro: %s \n",nodoAux->Ingreso.FechaRetiro);
    printf("   -------------------------------------------------------------------------\n");
    mostrarListaPracXingreso(nodoAux->listaPracXingreso);


}

void mostrarListaIngreso(nodoIngreso * listaIngreso)
{
    nodoIngreso* seg = listaIngreso;
    while(seg !=NULL)
    {
        mostrarUnNodoIngreso(seg);
        seg = seg->siguiente;
    }

}



nodoIngreso* buscarIngreso(nodoIngreso* listaIngreso,int dato)
{
    nodoIngreso* seg = listaIngreso;
    nodoIngreso* encontrado = inicListaDIngreso();

    while(seg !=NULL)
    {
        if(seg->Ingreso.NroIngreso == dato)
        {
            encontrado = seg;
        }
        seg = seg->siguiente;
    }

    return encontrado;
}

ingreso crearIngreso(ingreso UnIngreso)
{
        printf("Ingrese Numero de ingreso: ");
        scanf("%i",&UnIngreso.NroIngreso);
        printf("\n");
       printf("Ingrese fecha del ingreso: ");
       fflush(stdin);
       gets(&UnIngreso.FechaIngreso);
       printf("\n");
       printf("Ingrese fecha de retiro del ingreso: ");
       fflush(stdin);
       gets(&UnIngreso.FechaRetiro);
       printf("\n");
       printf("Ingrese Matricula del profesional: ");
       scanf("%i",&UnIngreso.MatriculaProfesional);
       printf("\n");

    return UnIngreso;
}



nodoIngreso* altaDeIngreso(nodoIngreso* listaIngreso,ingreso UnIngreso,pracXIngreso UnaPracIng)
{
    nodoIngreso* ingresoBuscado = inicListaDIngreso();

    ingresoBuscado = buscarIngreso(listaIngreso,UnIngreso.NroIngreso);

    if(ingresoBuscado == NULL)
    {
       nodoIngreso* nuevoNodo = crearNodoDIngreso(UnIngreso);
        nuevoNodo->listaPracXingreso = AgregarPpioPracXingreso(nuevoNodo->listaPracXingreso,crearNodoPracXingreso(UnaPracIng));
        listaIngreso = agregarPpioListaIngreso(listaIngreso,nuevoNodo);
    }else{
      ingresoBuscado->listaPracXingreso = AgregarPpioPracXingreso(ingresoBuscado->listaPracXingreso,crearNodoPracXingreso(UnaPracIng));
    }



    return listaIngreso;

}
