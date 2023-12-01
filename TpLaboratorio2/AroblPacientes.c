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


void inOrderArbolPac(nodoArbol* arbolPac,empleadoLab UnEmpleado)
{

    if(arbolPac !=NULL)
    {

        inOrderArbolPac(arbolPac->izq,UnEmpleado);
        mostrarUnNodoArbol(arbolPac,UnEmpleado);
        inOrderArbolPac(arbolPac->der,UnEmpleado);

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

void mostrarUnNodoArbol(nodoArbol* arbolPac,empleadoLab UnEmpleado)
{
    if((arbolPac->Paciente.Eliminado == 0) || (strcmp(UnEmpleado.perfil,ADMINISTRADOR)== 0))
    {
        printf("Datos del paciente---------> \n");
        printf("Apellido y nombre: %s\n",arbolPac->Paciente.ApellidoYNombe);
        printf("Edad: %i \n",arbolPac->Paciente.Edad);
        printf("DNI: %i\n",arbolPac->Paciente.Dni);
        printf("Direccion: %s\n",arbolPac->Paciente.Direccion);
        printf("Telefono: %s\n",arbolPac->Paciente.Telefono);
        printf("-------------------------------------------------------------------------\n");
        mostrarListaIngreso(arbolPac->listaIngresos,UnEmpleado);
    }
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
                 buscadoModif->listaIngresos->Ingreso.DniPaciente = buscadoModif->Paciente.Dni;
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
    if(buscadoDarBaja !=NULL && buscadoDarBaja->listaIngresos !=NULL)
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

nodoArbol* darBajaIngresoYPrac(nodoArbol* arbolPac)
{

     int UnDni;
    int UnIngreso;
    nodoArbol* buscadoModPracArbol = inicArbol();
    nodoIngreso* buscadoModPracListaIng = inicListaDIngreso();

    printf("Ingrese Dni del paciente a buscar, ingreso ");
    printf("Dni: ");
    scanf("%i",&UnDni);
    printf("Nro ingreso: ");
    scanf("%i",&UnIngreso);

    buscadoModPracArbol = buscarNodoArbolPacDni(arbolPac,UnDni,buscadoModPracArbol);
    if(buscadoModPracArbol !=NULL)
    {
        buscadoModPracListaIng = buscarIngreso(buscadoModPracArbol->listaIngresos,UnIngreso);
        if(buscadoModPracListaIng !=NULL)
        {

                buscadoModPracListaIng->Ingreso.Eliminado = 1;



        }else{printf("No se ha encontrado el Nro de ingreso\n");}

    }else{printf("No se ha encontrad un paciente con ese dni \n");}



    return buscadoModPracArbol;



}

void recorrerListaPrac(nodoPracXIngreso* listaPrac,int UnaPrac,int* flag)
{
    nodoPracXIngreso* seg = listaPrac;


    while(seg !=NULL && (*flag) == 0)
    {
        if(seg->practicaXIngreso.NroPractica == UnaPrac)
        {
            (*flag)= 1;

        }
        seg = seg->siguiente;
    }


}




void recorrerListaIngresoYbuscarPrac(nodoIngreso* listaIngreso,int UnaPrac,int* flag)
{
    nodoIngreso* seg = listaIngreso;


    while(seg !=NULL && (*flag) == 0 )
    {
        recorrerListaPrac(seg->listaPracXingreso,UnaPrac,flag);
        seg = seg->siguiente;

    }


}




void recorrerArbolYbuscarPrac(nodoArbol* arbolPac,int UnaPrac,int* flag)
{


    if(arbolPac !=NULL && (*flag) == 0)
    {

        recorrerListaIngresoYbuscarPrac(arbolPac->listaIngresos,UnaPrac,flag);
        recorrerArbolYbuscarPrac(arbolPac->izq,UnaPrac,flag);
        recorrerArbolYbuscarPrac(arbolPac->der,UnaPrac,flag);

    }

}



void darDeBajaUnaPractica(nodoArbol* arbolPac,practicaLab Practicas[],int validosPracticas)
{
    int i = 0; int UnaPractica;
    printf("Ingrese Numero de practica a dar de baja: \n");
    fflush(stdin);
    scanf("%i",&UnaPractica);
    int flag = 0;
    int flagE = 0;

    recorrerArbolYbuscarPrac(arbolPac,UnaPractica,&flag);

    while(i<validosPracticas && flagE == 0)
    {

        if((Practicas[i].NroPract == UnaPractica && (flag == 1)))
        {
            printf("Se ha eliminado la practica correctamente\n");
            Practicas[i].Eliminado = 1;
            flagE = 1;
        }

        i++;
    }
    if(flagE !=1)
    {
        printf("No se ha encontrado una practica con ese valor\n");
    }
}





void guardarArbolEnArch(nodoArbol* arbolPac,FILE* archA)
{
    pacienteDatos UnPacienteDato;
    // datos del paciente
    strcpy(&UnPacienteDato.UnPaciente.ApellidoYNombe,arbolPac->Paciente.ApellidoYNombe);
    UnPacienteDato.UnPaciente.Dni = arbolPac->Paciente.Dni;
    strcpy(&UnPacienteDato.UnPaciente.Direccion,arbolPac->Paciente.Direccion);
    UnPacienteDato.UnPaciente.Edad = arbolPac->Paciente.Edad;
    UnPacienteDato.UnPaciente.Eliminado = arbolPac->Paciente.Eliminado;
    strcpy(&UnPacienteDato.UnPaciente.Telefono,arbolPac->Paciente.Telefono);
    //datos del ingreso
    UnPacienteDato.UnIngreso.DniPaciente = arbolPac->listaIngresos->Ingreso.DniPaciente;
    UnPacienteDato.UnIngreso.Eliminado = arbolPac->listaIngresos->Ingreso.Eliminado;
    strcpy(&UnPacienteDato.UnIngreso.FechaIngreso,arbolPac->listaIngresos->Ingreso.FechaIngreso);
    strcpy(&UnPacienteDato.UnIngreso.FechaRetiro,arbolPac->listaIngresos->Ingreso.FechaRetiro);
    UnPacienteDato.UnIngreso.MatriculaProfesional = arbolPac->listaIngresos->Ingreso.MatriculaProfesional;
    UnPacienteDato.UnIngreso.NroIngreso = arbolPac->listaIngresos->Ingreso.NroIngreso;

    //datos de las prac
    UnPacienteDato.UnaPractica.NroIngreso = arbolPac->listaIngresos->listaPracXingreso->practicaXIngreso.NroIngreso;
    UnPacienteDato.UnaPractica.NroPractica = arbolPac->listaIngresos->listaPracXingreso->practicaXIngreso.NroPractica;
    strcpy(&UnPacienteDato.UnaPractica.resultado,arbolPac->listaIngresos->listaPracXingreso->practicaXIngreso.resultado);

    fwrite(&UnPacienteDato,sizeof(pacienteDatos),1,archA);
}


void recorrerYescribirEnArbol(nodoArbol* arbolPac,FILE* archA)
{
    if(arbolPac !=NULL)
    {
        guardarArbolEnArch(arbolPac,archA);
        recorrerYescribirEnArbol(arbolPac->izq,archA);
        recorrerYescribirEnArbol(arbolPac->der,archA);

    }

}


void persistirDatosDelArbol(nodoArbol* arbolPac)
{

    FILE* archA = fopen("arbolPacientes","wb");

    if(archA!=NULL)
    {
        recorrerYescribirEnArbol(arbolPac,archA);

    }

    fclose(archA);


}

nodoArbol* guardarDatosArchiEnArbol(nodoArbol* arbolPac)
{

    pacienteDatos UnPacienteDato;
    FILE* archA = fopen("arbolPacientes","rb");

    if(archA !=NULL)
    {
        while(fread(&UnPacienteDato,sizeof(UnPacienteDato),1,archA)>0)
        {
           arbolPac = AltaDePacienteIngresar(arbolPac,UnPacienteDato.UnPaciente,UnPacienteDato.UnIngreso,UnPacienteDato.UnaPractica);
        }

    }
    fclose(archA);

   return arbolPac;
}



void menuDeSistemaAdministrativo()
{
    printf("1->Mostrar todos los pacientes con sus ingresos y practicas\n");
    printf("2->Buscar un paciente y mostrarlo\n");
    printf("3->Mostrar Ingresos de un paciente\n");
    printf("4->Mostrar Practicas de un ingreso\n");
    printf("5->Mostrar todas las practicas\n");
    printf("6->Mostrar Empleados\n");
    printf("7->Salir\n");

}




void sistemaModoAdministrativo(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosP,empleadoLab Empleados[],int* validosE)
{


    int validosPracticas = (*validosP);
      int validosEmpleados = (*validosE);
    int op = 99;
    nodoArbol* auxiliar = inicArbol();
    nodoIngreso* auxiliarLista = inicListaDIngreso();
    char UnPaciente[30];
    int NroIngreso;
    while(op != 7)
    {
        menuDeSistemaAdministrativo();
        printf("Ingrese un numero para acceder a la funcion que quiera: ");
        fflush(stdin);
        scanf("%i",&op);
        system("cls");
        switch(op)
        {
        case 1: inOrderArbolPac(arbolPac,UnEmpleado);
                system("pause");
                system("cls");
            break;
        case 2: printf("Ingrese nombre del paciente a buscar: ");
                fflush(stdin);
                gets(&UnPaciente);
                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                mostrarUnNodoArbol(auxiliar,UnEmpleado);
                system("pause");
                system("cls");
            break;
        case 3: printf("Ingrese Nombre del paciente para mostrar solo sus ingresos: ");
                fflush(stdin);
                gets(&UnPaciente);
                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                mostrarListaIngreso(auxiliar->listaIngresos,UnEmpleado);

                    system("pause");
                    system("cls");
            break;
        case 4: printf("Ingrese nombre del paciente y numero del ingreso para mostrar solo sus practicas \n");
                printf("Nombre y Apellido: ");
                fflush(stdin);
                gets(&UnPaciente);
                printf("Nro Ingreo: ");
                scanf("%i",&NroIngreso);

                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                if(auxiliar!=NULL)
                {
                    auxiliarLista = buscarIngreso(auxiliar->listaIngresos,NroIngreso);
                    mostrarListaPracXingreso(auxiliarLista->listaPracXingreso);
                }else{
                    while(auxiliar == NULL)
                    {
                        printf("El valor ingresado no es valido porfavor ingrese otro");
                        printf("Nombre y Apellido: ");
                        fflush(stdin);
                        gets(&UnPaciente);
                        printf("Nro Ingreo: ");
                        scanf("%i",&NroIngreso);
                        auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                        if(auxiliar !=NULL)
                        {
                            auxiliarLista = buscarIngreso(auxiliar->listaIngresos,NroIngreso);
                            mostrarListaPracXingreso(auxiliarLista->listaPracXingreso);
                        }
                    }

                }
                    system("pause");
                    system("cls");
            break;
        case 5: mostrarPractica(Practicas,validosPracticas,UnEmpleado);
                    system("pause");
                    system("cls");
            break;

            case 6: mostrarEmpleados(Empleados,validosEmpleados,UnEmpleado);
                    system("pause");
                    system("cls");
            break;
            case 7: op = 7;
            break;
       default: printf("Por favor ingrese una opcion valida\n");

        }
    }
 persistirDatosDelArbol(arbolPac);
 empleadosToArch(Empleados,validosEmpleados);
 persistirPracticas(Practicas,validosPracticas);
}







void menuDeSistemaTecnico()
{
    printf("1->Mostrar todos los pacientes con sus ingresos y practicas\n");
    printf("2->Dar de alta un paciente con ingreso y practica\n");
    printf("3->Modificar un paciente\n");
    printf("4->Buscar un paciente y mostrarlo\n");
    printf("5->Mostrar Ingresos de un paciente\n");
    printf("6->Mostrar Practicas de un ingreso\n");
    printf("7->Modificar un ingreso\n");
    printf("8->Modificar una practica\n");
    printf("9->Dar de baja un paciente\n");
    printf("10->Dar de baja un ingreso\n");
    printf("11->Mostrar todas las practicas\n");
    printf("12->Salir\n");

}


void sistemaModoTecnico(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosP,empleadoLab Empleados[],int* validosE)
{


    int validosPracticas = (*validosP);
      int validosEmpleados = (*validosE);
    int op = 99;
    nodoArbol* auxiliar = inicArbol();
    nodoIngreso* auxiliarLista = inicListaDIngreso();
    char UnPaciente[30];
    int NroIngreso;
    while(op != 12)
    {
        menuDeSistemaTecnico();
        printf("Ingrese un numero para acceder a la funcion que quiera: ");
        fflush(stdin);
        scanf("%i",&op);
        system("cls");
        switch(op)
        {
        case 1: inOrderArbolPac(arbolPac,UnEmpleado);
                system("pause");
                system("cls");
            break;
        case 2: arbolPac = cargarUnPacienteAlNodo(arbolPac);

                system("pause");
                system("cls");
            break;
        case 3: arbolPac = modificarSoloNodoArbol(arbolPac);

                system("pause");
                system("cls");
            break;

        case 4: printf("Ingrese nombre del paciente a buscar: ");
                fflush(stdin);
                gets(&UnPaciente);
                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                mostrarUnNodoArbol(auxiliar,UnEmpleado);
                system("pause");
                system("cls");
            break;
        case 5: printf("Ingrese Nombre del paciente para mostrar solo sus ingresos: ");
                fflush(stdin);
                gets(&UnPaciente);
                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                mostrarListaIngreso(auxiliar->listaIngresos,UnEmpleado);

                    system("pause");
                    system("cls");
            break;
        case 6: printf("Ingrese nombre del paciente y numero del ingreso para mostrar solo sus practicas \n");
                printf("Nombre y Apellido: ");
                fflush(stdin);
                gets(&UnPaciente);
                printf("Nro Ingreo: ");
                scanf("%i",&NroIngreso);

                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                if(auxiliar!=NULL)
                {
                    auxiliarLista = buscarIngreso(auxiliar->listaIngresos,NroIngreso);
                    mostrarListaPracXingreso(auxiliarLista->listaPracXingreso);
                }else{
                    while(auxiliar == NULL)
                    {
                        printf("El valor ingresado no es valido porfavor ingrese otro");
                        printf("Nombre y Apellido: ");
                        fflush(stdin);
                        gets(&UnPaciente);
                        printf("Nro Ingreo: ");
                        scanf("%i",&NroIngreso);
                        auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                        if(auxiliar !=NULL)
                        {
                            auxiliarLista = buscarIngreso(auxiliar->listaIngresos,NroIngreso);
                            mostrarListaPracXingreso(auxiliarLista->listaPracXingreso);
                        }
                    }

                }
                    system("pause");
                    system("cls");
            break;
        case 7:  auxiliar = modificarSoloNodoIngreso(arbolPac);
                 if(auxiliar !=NULL)
                 {
                     arbolPac = auxiliar;
                 }
                    system("pause");
                    system("cls");
            break;
        case 8: auxiliar = modificarSoloNodoPractica(arbolPac);
                 if(auxiliar !=NULL)
                 {
                     arbolPac = auxiliar;
                 }
                    system("pause");
                    system("cls");
            break;
        case 9: auxiliar = darDeBajaUnPaciente(arbolPac);
                if(auxiliar !=NULL)
                {
                    arbolPac = auxiliar;
                }
            break;
        case 10:    auxiliar = darBajaIngresoYPrac(arbolPac);
                    if(auxiliar !=NULL)
                    {
                        arbolPac = auxiliar;
                    }
                    system("pause");
                    system("cls");
            break;

        case 11: mostrarPractica(Practicas,validosPracticas,UnEmpleado);
                    system("pause");
                    system("cls");
            break;

        case 12: op = 12;
            break;
       default: printf("Por favor ingrese una opcion valida\n");

        }
    }
 persistirDatosDelArbol(arbolPac);
 empleadosToArch(Empleados,validosEmpleados);
 persistirPracticas(Practicas,validosPracticas);
}










void menuDeSistemaAdministrador()
{
    printf("1->Mostrar todos los pacientes con sus ingresos y practicas\n");
    printf("2->Dar de alta un paciente con ingreso y practica\n");
    printf("3->Modificar un paciente\n");
    printf("4->Buscar un paciente y mostrarlo\n");
    printf("5->Mostrar Ingresos de un paciente\n");
    printf("6->Mostrar Practicas de un ingreso\n");
    printf("7->Modificar un ingreso\n");
    printf("8->Modificar una practica\n");
    printf("9->Dar de baja un paciente\n");
    printf("10->Dar de baja un ingreso\n");
    printf("11->Mostrar todos los empleados\n");
    printf("12->Mostrar todas las practicas\n");
    printf("13->Dar de Baja una practica\n");
    printf("14->Agregar una practica\n");
    printf("15->Agregar un empleado\n");
    printf("16->Modificar un empleado\n");
    printf("17->Salir\n");

}





void sistemaModoAdministrador(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosP,empleadoLab Empleados[],int* validosE)
{



      int validosPracticas = (*validosP);
      int validosEmpleados = (*validosE);
    int op = 99;
    nodoArbol* auxiliar = inicArbol();
    nodoIngreso* auxiliarLista = inicListaDIngreso();
    char UnPaciente[30];
    int NroIngreso;
    while(op != 17)
    {
        menuDeSistemaAdministrador();
        printf("Ingrese un numero para acceder a la funcion que quiera: ");
        fflush(stdin);
        scanf("%i",&op);
        system("cls");
        switch(op)
        {
        case 1: inOrderArbolPac(arbolPac,UnEmpleado);
                system("pause");
                system("cls");
            break;
        case 2: arbolPac = cargarUnPacienteAlNodo(arbolPac);

                system("pause");
                system("cls");
            break;
        case 3: arbolPac = modificarSoloNodoArbol(arbolPac);

                system("pause");
                system("cls");
            break;

        case 4: printf("Ingrese nombre del paciente a buscar: ");
                fflush(stdin);
                gets(&UnPaciente);
                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                mostrarUnNodoArbol(auxiliar,UnEmpleado);
                system("pause");
                system("cls");
            break;
        case 5: printf("Ingrese Nombre del paciente para mostrar solo sus ingresos: ");
                fflush(stdin);
                gets(&UnPaciente);
                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                mostrarListaIngreso(auxiliar->listaIngresos,UnEmpleado);

                    system("pause");
                    system("cls");
            break;
        case 6: printf("Ingrese nombre del paciente y numero del ingreso para mostrar solo sus practicas \n");
                printf("Nombre y Apellido: ");
                fflush(stdin);
                gets(&UnPaciente);
                printf("Nro Ingreo: ");
                scanf("%i",&NroIngreso);

                auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                if(auxiliar!=NULL)
                {
                    auxiliarLista = buscarIngreso(auxiliar->listaIngresos,NroIngreso);
                    mostrarListaPracXingreso(auxiliarLista->listaPracXingreso);
                }else{
                    while(auxiliar == NULL)
                    {
                        printf("El valor ingresado no es valido porfavor ingrese otro");
                        printf("Nombre y Apellido: ");
                        fflush(stdin);
                        gets(&UnPaciente);
                        printf("Nro Ingreo: ");
                        scanf("%i",&NroIngreso);
                        auxiliar = buscarNodoArbolPac(arbolPac,UnPaciente);
                        if(auxiliar !=NULL)
                        {
                            auxiliarLista = buscarIngreso(auxiliar->listaIngresos,NroIngreso);
                            mostrarListaPracXingreso(auxiliarLista->listaPracXingreso);
                        }
                    }

                }
                    system("pause");
                    system("cls");
            break;
        case 7:  auxiliar = modificarSoloNodoIngreso(arbolPac);
                 if(auxiliar !=NULL)
                 {
                     arbolPac = auxiliar;
                 }
                    system("pause");
                    system("cls");
            break;
        case 8: auxiliar = modificarSoloNodoPractica(arbolPac);
                 if(auxiliar !=NULL)
                 {
                     arbolPac = auxiliar;
                 }
                    system("pause");
                    system("cls");
            break;
        case 9: auxiliar = darDeBajaUnPaciente(arbolPac);
                if(auxiliar !=NULL)
                {
                    arbolPac = auxiliar;
                }
            break;
        case 10:    auxiliar = darBajaIngresoYPrac(arbolPac);
                    if(auxiliar !=NULL)
                    {
                        arbolPac = auxiliar;
                    }
                    system("pause");
                    system("cls");
            break;
        case 11: mostrarEmpleados(Empleados,validosEmpleados,UnEmpleado);
                    system("pause");
                    system("cls");
            break;
        case 12: mostrarPractica(Practicas,validosPracticas,UnEmpleado);
                    system("pause");
                    system("cls");
            break;
        case 13: darDeBajaUnaPractica(arbolPac,Practicas,validosPracticas);
                (*validosP) = validosPracticas;
                  system("pause");
                  system("cls");
            break;
        case 14: darAltaAgregarUnaPractica(Practicas,&validosPracticas);
                 system("pause");
                  system("cls");
            break;
        case 15: darAltaAgregarUnEmpleado(Empleados,&validosEmpleados);
                (*validosE) = validosEmpleados;
                 system("pause");
                  system("cls");
            break;
        case 16: modificarUnEmpleado(Empleados,validosEmpleados);
                 system("pause");
                 system("cls");
            break;
        case 17: op = 17;
            break;
       default: printf("Por favor ingrese una opcion valida\n");

        }
    }
 persistirDatosDelArbol(arbolPac);
 empleadosToArch(Empleados,validosEmpleados);
 persistirPracticas(Practicas,validosPracticas);
}



void ingresarSistema(nodoArbol* arbolPac,empleadoLab UnEmpleado,practicaLab Practicas[],int* validosPracticas,empleadoLab Empleados[],int* validosEmpleados)
{

    system("cls");

    if( strcmp(UnEmpleado.perfil,ADMINISTRADOR)== 0)
    {
        printf("Bienvenido %s , usted se encuentra en modo %s\n",UnEmpleado.ApellidoYnombreEmpleado,UnEmpleado.perfil);
        sistemaModoAdministrador(arbolPac,UnEmpleado,Practicas,validosPracticas,Empleados,validosEmpleados);

    }else if((strcmp(UnEmpleado.perfil,TECNICO)==0)||(strcmp(UnEmpleado.perfil,BIOQUIMICO)==0))
             {

                 printf("Bienvenido %s, usted se encuentra en modo %s\n",UnEmpleado.ApellidoYnombreEmpleado,UnEmpleado.perfil);
                         sistemaModoTecnico(arbolPac,UnEmpleado,Practicas,validosPracticas,Empleados,validosEmpleados);
             }else if((strcmp(UnEmpleado.perfil,ADMINISTRATIVO)== 0))
             {

                 printf("Bienvenido %s , usted se encuentra en modo %s\n",UnEmpleado.ApellidoYnombreEmpleado,UnEmpleado.perfil);
                 sistemaModoAdministrativo(arbolPac,UnEmpleado,Practicas,validosPracticas,Empleados,validosEmpleados);
             }


}


void checkearUsuario(nodoArbol* arbolPac,empleadoLab Empleados[],int* validosEmpleados,practicaLab Practicas[],int* validosPracticas)
{





    empleadoLab UnEmpleado;int * flag = 0;
    printf("Ingrese Usuario: ");
    fflush(stdin);
    gets(&UnEmpleado.Usuario);
    printf("Ingrese contraseña: ");
    fflush(stdin);
    gets(&UnEmpleado.Contrasena);


    UnEmpleado = buscarUnEmpleadoYConstrasena(Empleados,validosEmpleados,UnEmpleado,&flag);

    while( flag == 0)
    {
        printf("Usuario o contraseña no es valido \n");
        printf("Ingrese Usuario: ");
        fflush(stdin);
        gets(&UnEmpleado.Usuario);
        printf("Ingrese contraseña: ");
        fflush(stdin);
        gets(&UnEmpleado.Contrasena);


        UnEmpleado = buscarUnEmpleadoYConstrasena(Empleados,validosEmpleados,UnEmpleado,&flag);


    }

        if(flag==1)
        {
            ingresarSistema(arbolPac,UnEmpleado,Practicas,&validosPracticas,Empleados,&validosEmpleados);
        }


}

