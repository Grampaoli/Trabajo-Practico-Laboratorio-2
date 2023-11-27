#include "ArbolPacientes.h"
#include "ListaIngresos.h"
#include "listaPracXIngreso.h"

nodoArbol* inicArbol(){

 return NULL;
}

nodoArbol* crearNodoArbol(paciente UnPaciente)
{
    nodoArbol* auxArbol = (nodoArbol*)malloc(sizeof(nodoArbol));
    strcpy(auxArbol->Paciente.ApellidoYNombe,UnPaciente.ApellidoYNombe);
    strcpy(auxArbol->Paciente.Direccion,UnPaciente.Direccion);
    strcpy(auxArbol->Paciente.Telefono,UnPaciente.Telefono);
    auxArbol->Paciente.Dni = UnPaciente.Dni;
    auxArbol->Paciente.Edad = UnPaciente.Edad;
    auxArbol->Paciente.Eliminado = 0;
    auxArbol->listaIngresos = inicListaDIngreso();
    auxArbol->der = NULL;
    auxArbol->izq = NULL;

    return auxArbol;
}

nodoArbol* insertarNodoArbol(nodoArbol* arbolPac,nodoArbol *nuevoNodo){

    if(arbolPac == NULL)
    {
        arbolPac = nuevoNodo;

    }else{

        if(strcmp(nuevoNodo->Paciente.ApellidoYNombe,arbolPac->Paciente.ApellidoYNombe)>0)
        {
            arbolPac->der = insertarNodoArbol(arbolPac->der,nuevoNodo);

        }else{
            arbolPac->izq = insertarNodoArbol(arbolPac->izq,nuevoNodo);
        }

    }

    return arbolPac;
}


void inOrderArbolPac(nodoArbol* arbolPac)
{

    if(arbolPac !=NULL)
    {

        inOrderArbolPac(arbolPac->izq);
        mostrarUnNodoArbol(arbolPac);
        inOrderArbolPac(arbolPac->der);

    }

}

void mostrarSoloNodoArbol(nodoArbol* arbolPac)
{
        printf("Datos del paciente---------> \n");
        printf("Apellido y nombre: %s\n",arbolPac->Paciente.ApellidoYNombe);
        printf("Edad: %i \n",arbolPac->Paciente.Edad);
        printf("DNI: %i\n",arbolPac->Paciente.Dni);
        printf("Direccion: %s\n",arbolPac->Paciente.Direccion);
        printf("Telefono: %s\n",arbolPac->Paciente.Telefono);
        printf("-------------------------------------------------------------------------\n");
}

void mostrarUnNodoArbol(nodoArbol* arbolPac)
{
        printf("Datos del paciente---------> \n");
        printf("Apellido y nombre: %s\n",arbolPac->Paciente.ApellidoYNombe);
        printf("Edad: %i \n",arbolPac->Paciente.Edad);
        printf("DNI: %i\n",arbolPac->Paciente.Dni);
        printf("Direccion: %s\n",arbolPac->Paciente.Direccion);
        printf("Telefono: %s\n",arbolPac->Paciente.Telefono);
        printf("-------------------------------------------------------------------------\n");
        mostrarListaIngreso(arbolPac->listaIngresos);

}

nodoArbol* buscarNodoArbolPac(nodoArbol * arbolPac,char UnPaciente[]){ //esta funcion busca un nombre segun el critero de ordenamiento haciendo eficiente la busqueda

 nodoArbol* rta = NULL;


    if(arbolPac!=NULL)
    {
        if(strcmp(arbolPac->Paciente.ApellidoYNombe,UnPaciente) == 0 ){
            rta = arbolPac;
        }
        else{
            if(strcmp(UnPaciente,arbolPac->Paciente.ApellidoYNombe)>0)
            {
            rta = buscarNodoArbolPac(arbolPac->der,UnPaciente);
            }
            else{
            rta = buscarNodoArbolPac(arbolPac->izq,UnPaciente);
            }
        }

    }

        return rta;

}

nodoArbol* buscarNodoArbolPacDni(nodoArbol * arbolPac,int Dni,nodoArbol * rta){

    if(arbolPac!=NULL)
    {

       rta = buscarNodoArbolPacDni(arbolPac->izq,Dni,rta);
        if(arbolPac->Paciente.Dni == Dni)
        {
            rta = arbolPac;
            return rta;

        }
       rta = buscarNodoArbolPacDni(arbolPac->der,Dni,rta);

    }
return rta;
}

nodoArbol* cargarUnPacienteAlNodo(nodoArbol* arbolPac)
{
    ingreso UnIngreso;
    paciente UnPaciente;
    pracXIngreso UnaPracIng;
    char seguir = 's';

    while(seguir == 's')
    {
        UnPaciente = crearUnPaciente(UnPaciente);
        UnIngreso.DniPaciente = UnPaciente.Dni;
        UnIngreso = crearIngreso(UnIngreso);
        fflush(stdin);
        UnaPracIng.NroIngreso = UnIngreso.NroIngreso;
        UnaPracIng = crearUnaPracXingreso(UnaPracIng);
        fflush(stdin);

        arbolPac = AltaDePacienteIngresar(arbolPac,UnPaciente,UnIngreso,UnaPracIng);

        printf("Desea seguir agregando datos ?\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }

    return arbolPac;
}


paciente crearUnPaciente(paciente UnPaciente){


        printf("Ingrese los datos del paciente:\n");
        printf("Nombre y apellido: ");
        fflush(stdin);
        gets(&UnPaciente.ApellidoYNombe);
        printf("\n");
        printf("Edad : ");
        scanf("%i",&UnPaciente.Edad);
        printf("\n");
        printf("DNI : ");
        fflush(stdin);
        scanf("%i",&UnPaciente.Dni);
        printf("\n");
        printf("Direccion: ");
        fflush(stdin);
        gets(&UnPaciente.Direccion);
        printf("\n");
        printf("Telefono: ");
        fflush(stdin);
        gets(&UnPaciente.Telefono);
        printf("\n");
        UnPaciente.Eliminado = 0;


    return UnPaciente;
}


nodoArbol* AltaDePacienteIngresar(nodoArbol* arbolPac,paciente UnPaciente,ingreso UnIngreso,pracXIngreso UnaPracIng){
    nodoArbol* rta = inicArbol();

    rta = buscarNodoArbolPacDni(arbolPac,UnPaciente.Dni,rta);

    if(rta ==NULL){
     nodoArbol* nuevoNodo = crearNodoArbol(UnPaciente);
     nuevoNodo->listaIngresos = altaDeIngreso(nuevoNodo->listaIngresos,UnIngreso,UnaPracIng);
     arbolPac = insertarNodoArbol(arbolPac,nuevoNodo);

    }else{
       rta->listaIngresos =  altaDeIngreso(rta->listaIngresos,UnIngreso,UnaPracIng);
    }


    return arbolPac;

}

void arbolAArchivo(nodoArbol* arbol)
{
    FILE* archArbol = fopen("arbol.bin","w+b");

    if(archArbol !=NULL)
    {
        fwrite(arbol,sizeof(nodoArbol*),1,archArbol);

    }

    fclose(archArbol);
}


nodoArbol * ArchToArbol(){

    nodoArbol* aux = inicArbol();

    FILE* archArbol = fopen("arbol.bin","r+b");

    if(archArbol!=NULL)
    {
        fread(aux,sizeof(nodoArbol*),1,archArbol);
    }

    return aux;
}

void menuOpcModArbol()
{
        printf("Que valor desea Modificar ? \n");
        printf("1->Edad\n");
        printf("2->Dni\n");
        printf("3->Direccion\n");
        printf("4->Telefono\n");
        printf("5->Salir\n");
        printf("Ingrese la opcion: ");
}





nodoArbol* modArbolCatch(nodoArbol* buscadoModif){
        int op = 99;

        while(op !=5)
        {
            menuOpcModArbol();
            scanf("%i",&op);
            printf("\n");
            switch(op){
          case 1: printf("Inserte La nueva edad: ");
                  scanf("%i",&buscadoModif->Paciente.Edad);
                  printf("\n");
            break;
          case 2:printf("Inserte el nuevo dni: ");
                 scanf("%i",&buscadoModif->Paciente.Dni);
                 printf("\n");
            break;
          case 3:printf("Inserte la nueva direccion: ");
                 fflush(stdin);
                 gets(&buscadoModif->Paciente.Direccion);
                 printf("\n");
            break;
          case 4:printf("Ingrese el nuevo telefono: ");
                 fflush(stdin);
                 gets(&buscadoModif->Paciente.Telefono);
                 printf("\n");
            break;
          case 5: op = 5;
             break;
            default: printf("No ingresaste un opcion valida \n");

            }
                 if(op != 5){
                    printf("Modificar otro valor ---------------------->\n");
                }

        }

    printf("Estos son los valores de paciente modificado--------->\n");
    mostrarSoloNodoArbol(buscadoModif);
    return buscadoModif;
}

nodoArbol* modificarSoloNodoArbol(nodoArbol* arbolPac)
{
    char UnPaciente[40];
    nodoArbol* buscadoModif = inicArbol();

    printf("Ingrese Nombre y Apellido de paciente a modificar: ");
    fflush(stdin);
    gets(&UnPaciente);

    buscadoModif = buscarNodoArbolPac(arbolPac,UnPaciente);
    if(buscadoModif !=NULL)
    {
        mostrarSoloNodoArbol(buscadoModif);
       buscadoModif= modArbolCatch(buscadoModif);
    }else{
     printf("No se encontro ningun paciente con ese nombre\n");
    }

 return buscadoModif;
}


nodoArbol* darDeBajaUnPaciente(nodoArbol* arbolPac)
{
    char UnPaciente[40];
    nodoArbol* buscadoDarBaja = inicArbol();
    printf("Ingrese nombre y apellido del apciente a dar de baja: ");
    fflush(stdin);
    gets(&UnPaciente);
    printf("\n");
    buscadoDarBaja = buscarNodoArbolPac(arbolPac,UnPaciente);
    if(buscadoDarBaja !=NULL)
    {
     buscadoDarBaja->Paciente.Eliminado = 1;

    }else{
        printf("No se pudo encontrar el paciente a dar de baja\n");
    }


    return buscadoDarBaja;
}


void menuOpcListaIngreso(){

        printf("Que valor desea Modificar ? \n");
        printf("1->Fecha de ingreso\n");
        printf("2->Fecha de retiro\n");
        printf("3->Matricula del profesional\n");
        printf("4->Salir\n");
        printf("Ingrese la opcion: ");


}



nodoIngreso* modIngresoCatch(nodoIngreso* listaIngreso)
{
    int op = 99;

    while(op!=4)
    {
        menuOpcListaIngreso();
        scanf("%i",&op);
        printf("\n");

        switch(op){
     case 1: printf("Ingrese nueva fecha de ingreso: ");
             fflush(stdin);
             gets(&listaIngreso->Ingreso.FechaIngreso);
             printf("\n");
        break;
     case 2:printf("Ingrese nueva fecha de retiro: ");
            fflush(stdin);
            gets(&listaIngreso->Ingreso.FechaRetiro);
        break;
     case 3:printf("Ingrese nueva Matricula del solicitante: ");
            fflush(stdin);
            scanf("%i",&listaIngreso->Ingreso.MatriculaProfesional);
        break;
        case 4: op = 4;
        break;
        default: printf("No elijio una opcion correcta \n");

        }
         if(op != 4)
          {
              printf("Modificar otro valor ---------------------->\n");
          }

    }
    printf("Estos son los valores del  Ingreso modificado ---------->\n");
    mostrarSoloUnNodoIngreso(listaIngreso);
    return listaIngreso;
}







nodoArbol* modificarSoloNodoIngreso(nodoIngreso* arbolPac)
{
    int UnDni;
    int UnIngreso;
    nodoArbol* buscarModArbolIngreso = inicArbol();
    nodoIngreso* buscarModListaIngreso = inicListaDIngreso();
    printf("Ingrese un Dni a buscar para modificar un ingreso y luego el numero de Ingreso: ");
    scanf("%i",&UnDni);
    printf("\n");
    fflush(stdin);
    printf("Ingreso: ");
    scanf("%i",&UnIngreso);

    buscarModArbolIngreso = buscarNodoArbolPacDni(arbolPac,UnDni,buscarModArbolIngreso);

    if(buscarModArbolIngreso!=NULL)
    {
        buscarModListaIngreso = buscarIngreso(buscarModArbolIngreso->listaIngresos,UnIngreso);
        if(buscarModListaIngreso != NULL )
        {
            mostrarSoloUnNodoIngreso(buscarModListaIngreso);
            buscarModListaIngreso= modIngresoCatch(buscarModListaIngreso);

        }else{
            printf("No se encontro el ingreso buscado\n");
        }

    }else{

         printf("No se encontro un paciente con ese dni ");
    }

    return buscarModArbolIngreso;
}


nodoPracXIngreso* buscarUnNodoPrac(nodoPracXIngreso* listaPrac,int dato)
{
    nodoPracXIngreso* seg = listaPrac;
    nodoIngreso* encontrado = inicListaPracXIngreso();
    while(seg!=NULL)
    {
        if(seg->practicaXIngreso.NroPractica == dato)
        {
            encontrado = seg;
        }
        seg = seg->siguiente;
    }


    return encontrado;
}



void menuOpcionListaPrac()
{
    printf("Que valor desea Modificar ? \n");
        printf("1->Numero de practica\n");
        printf("2->Resultado\n");
        printf("3->Salir\n");
        printf("Ingrese la opcion: ");

}

nodoPracXIngreso * modCatchPractica(nodoPracXIngreso* buscadoModPracLista)
{
    int op = 99;

    while(op != 3)
    {

        menuOpcionListaPrac();
        scanf("%i",&op);
        switch(op){
     case 1:  printf("Ingrese el nuevo numero de practica: ");
              scanf("%",buscadoModPracLista->practicaXIngreso.NroPractica);
        break;
     case 2: printf("Ingrese el nuevo resultado: ");
             fflush(stdin);
             gets(&buscadoModPracLista->practicaXIngreso.resultado);
        break;
     case 3: op = 3;
        break;
     default: printf("No ha ingresado una opcion valida\n");

        }
        if(op !=3)
        {
            printf("Modificar otro valor --------------->\n");
        }
    }
    printf("Este es la nueva practica ingresada -------->\n");
    mostrarUnNodoPrac(buscadoModPracLista);

    return buscadoModPracLista;

}



nodoArbol* modificarSoloNodoPractica(nodoArbol* arbolPac)
{
    int UnDni;
    int UnIngreso;
    int UnaPrac;
    nodoArbol* buscadoModPracArbol = inicArbol();
    nodoIngreso* buscadoModPracListaIng = inicListaDIngreso();
    nodoPracXIngreso* buscadoModPracLista = inicListaPracXIngreso();
    printf("Ingrese Dni del paciente ingreso y practica que desea modificar\n");
    printf("Dni: ");
    scanf("%i",&UnDni);
    printf("Nro ingreso: ");
    scanf("%i",&UnIngreso);
    printf("Nro de practica: ");
    scanf("%i",&UnaPrac);
    buscadoModPracArbol = buscarNodoArbolPacDni(arbolPac,UnDni,buscadoModPracArbol);
    if(buscadoModPracArbol !=NULL)
    {
        buscadoModPracListaIng = buscarIngreso(buscadoModPracArbol->listaIngresos,UnIngreso);
        if(buscadoModPracListaIng !=NULL)
        {
            buscadoModPracLista = buscarUnNodoPrac(buscadoModPracListaIng->listaPracXingreso,UnaPrac);
            if(buscadoModPracLista !=NULL)
            {
                mostrarUnNodoPrac(buscadoModPracLista);
                buscadoModPracLista = modCatchPractica(buscadoModPracLista);


            }else{printf("No se ha encontrado esa practica en el ingreso");}

        }else{printf("No se ha encontrado el Nro de ingreso\n");}

    }else{printf("No se ha encontrad un paciente con ese dni \n");}


    return buscadoModPracArbol;



}
