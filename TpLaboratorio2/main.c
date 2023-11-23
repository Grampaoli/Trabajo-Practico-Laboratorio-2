#include <stdio.h>
#include <stdlib.h>
#include "ArbolPacientes.h"
#include "listaPracXIngreso.h"
#include "listaPracXIngreso.h"

int main()
{

    nodoArbol * arbolPac;
    arbolPac = inicArbol();

    arbolPac = AltaDePaciente(arbolPac);

    mostrarUnNodoArbol(arbolPac);
    return 0;
}
