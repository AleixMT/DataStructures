//
// Created by Sergi Vives on 12/4/20.
//

#include "pila.h"

int main(int nargs, char* args[])
{
    Pila* pila = CrearPila(10);

    printf("La pila hauria destar buida. Ho esta? %i \n", EsBuidaPila(*pila));
    EsBuidaPila(*pila);
    for (int i = 0; i < 10; i++)
    {
        Apilar(pila, i);
        printf("El cim es %i \n", Cim(*pila));
    }
    printf("La pila hauria destar plena. Ho esta? %i \n", EsPlenaPila(*pila));
    printf("El cim es %i \n", Cim(*pila));
    for (int i = 0; i < 9; i++)
    {
        Desapilar(pila);
        printf("El cim es %i \n", Cim(*pila));
    }
    Desapilar(pila);

    printf("La pila hauria destar buida. Ho esta? %i \n", EsBuidaPila(*pila));

    DestruirPila(pila);
}
