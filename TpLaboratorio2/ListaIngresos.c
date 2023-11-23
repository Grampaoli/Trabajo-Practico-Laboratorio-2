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
    printf("Datos del ingreso--------\n");
    printf("Numero de ingreso: %i\n",nodoAux->Ingreso.NroIngreso);
    printf("Dni del Paciente %i\n",nodoAux->Ingreso.DniPaciente);
    printf("Matricula del profesional: %i\n",nodoAux->Ingreso.MatriculaProfesional);
    printf("Fecha de ingreso: %s\n",nodoAux->Ingreso.FechaIngreso);
    printf("Fecha de Retiro: %s \n",nodoAux->Ingreso.FechaRetiro);
    printf("-------------------------------------------------------------------------\n");


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

nodoIngreso* altaDeIngreso(nodoIngreso* listaIngreso,int Dni)
{
    char seguir = 's';
    ingreso Ingreso;
    nodoIngreso* ingresoBuscado = inicListaDIngreso();
    nodoIngreso* auxNuevo = inicListaDIngreso();
    int dato;
    while(seguir == 's')
    {
        do{
        printf("Ingrese Numero de ingreso: ");
        scanf("%i",&Ingreso.NroIngreso);
        printf("\n");
        dato = Ingreso.NroIngreso;
        ingresoBuscado = buscarIngreso(listaIngreso,dato);
            if(ingresoBuscado !=NULL)
            {
            printf("ese ingresio ya esta hecho ingrese otro\n");
            }
        }while(ingresoBuscado !=NULL);
       printf("Ingrese fecha del ingreso: ");
       fflush(stdin);
       gets(&Ingreso.FechaIngreso);
       printf("\n");
       printf("Ingrese fecha de retiro del ingreso: ");
       fflush(stdin);
       gets(&Ingreso.FechaRetiro);
       printf("\n");
       printf("Ingrese Matricula del profesional: ");
       scanf("%i",&Ingreso.MatriculaProfesional);
       printf("\n");
       Ingreso.DniPaciente = Dni;
       //aqui agregaremos la otra lista de Practica por ingreso

       auxNuevo = crearNodoDIngreso(Ingreso);
       listaIngreso = agregarPpioListaIngreso(listaIngreso,auxNuevo);

       printf("Desea cargarle otro ingreso al paciente ? S/N");
        fflush(stdin);
        scanf("%c",&seguir);
        printf("\n");
    }

    return listaIngreso;

}
