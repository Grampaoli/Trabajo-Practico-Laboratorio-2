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

void mostrarSoloUnNodoIngreso(nodoIngreso* nodoAux){

    printf("   Datos del ingreso--------\n");
    printf("   Numero de ingreso: %i\n",nodoAux->Ingreso.NroIngreso);
    printf("   Dni del Paciente %i\n",nodoAux->Ingreso.DniPaciente);
    printf("   Matricula del profesional: %i\n",nodoAux->Ingreso.MatriculaProfesional);
    printf("   Fecha de ingreso: %s\n",nodoAux->Ingreso.FechaIngreso);
    printf("   Fecha de Retiro: %s \n",nodoAux->Ingreso.FechaRetiro);
    printf("   -------------------------------------------------------------------------\n");

}


void mostrarUnNodoIngreso(nodoIngreso * nodoAux)
{

    mostrarSoloUnNodoIngreso(nodoAux);
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

empleadoLab crearEmpleado(){

    empleadoLab aux;

    printf("Ingrese nombre y apellido del empleado: ");
    fflush(stdin);
    gets(&aux.ApellidoYnombreEmpleado);
    printf("Ingrese Dni del empleado: ");
    scanf("%i",&aux.DniEmpleado);
    printf("\n");
    printf("Ingrese Perfil del empleado [Administrador] ,Profesional de laboratorio [Tecnico o Bioquimico] o [Administrativo]: ");
    fflush(stdin);
    gets(&aux.perfil);

    while((strcmp(aux.perfil,ADMINISTRADOR)!= 0)&& (strcmp(aux.perfil,TECNICO)!= 0)&&(strcmp(aux.perfil,ADMINISTRATIVO) != 0)&& strcmp(aux.perfil,BIOQUIMICO)!= 0)
    {
        printf("Usted ingreso un perfil incorrecto ingrese uno de los ya mencionado porfavor\n");
        fflush(stdin);
        gets(&aux.perfil);


    }
    printf("Ingrese Usuario: ");
    fflush(stdin);
    gets(&aux.Usuario);
    printf("Ingrese contraseña: ");
    fflush(stdin);
    gets(&aux.Contrasena);


    return aux;
}


void darAltaAgregarUnEmpleado(empleadoLab Empleados[],int* validosEmpleados)
{
    empleadoLab UnEmpleado;
    char seguir = 's';
    int i;
    int flag;
    while(seguir =='s' && (*validosEmpleados)<CANTMAXEMPLEADOS)
    {

         i = *validosEmpleados;
        UnEmpleado = crearEmpleado();

        flag = buscarUnEmpleado(Empleados,i,UnEmpleado);
        if(flag ==0)
        {
                insertarEmpleado(Empleados,i-1,UnEmpleado);
                (*validosEmpleados)++;

        }else{

            printf("Ya se encontro un empleado con ese nombre\n");
        }

        printf("Desea agregar otro empleado ? \n");
        fflush(stdin);
        scanf("%c",&seguir);

    }


}


void insertarEmpleado(empleadoLab Empleados[],int ultimaPos,empleadoLab UnEmpleado)
{
    int i = ultimaPos;

    while((i>=0) && (strcmp(UnEmpleado.ApellidoYnombreEmpleado,Empleados[i].ApellidoYnombreEmpleado)<0))
    {

        Empleados[i+1] = Empleados[i];
        i--;

    }

    Empleados[i+1] = UnEmpleado;
}

int buscarUnEmpleado(empleadoLab Empleados[],int validos,empleadoLab UnEmpleado)
{
  int i = 0;
  int flag = 0;

    while(i<validos && flag == 0)
    {

        if(strcasecmp(Empleados[i].ApellidoYnombreEmpleado,UnEmpleado.ApellidoYnombreEmpleado)== 0)
        {
            flag = 1;
        }
     i++;
    }
  return flag;
}





void mostrarEmpleados(empleadoLab Empleados[],int* validosEmpleados)
{
    int j = *validosEmpleados;
    for(int i = 0;i<j;i++)
    {
        printf("Datos del empleado ------->\n");
        printf("Nombre y apellido: %s\n",Empleados[i].ApellidoYnombreEmpleado);
        printf("Dni: %i\n",Empleados[i].DniEmpleado);
        printf("Perfil: %s\n",Empleados[i].perfil);
        printf("Usuario: %s\n",Empleados[i].Usuario);
        printf("Contraseña: ******\n");
        printf("_____________________________________\n");
    }


}









