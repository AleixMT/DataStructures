//
// Created by Sergi Vives on 12/4/20.
//

#include "pila_reals.h"

int main(int nargs, char* args[])
{
    Pila* pila = Crear(10);

    printf("La pila hauria destar buida. Ho esta? %i \n", EsBuida(*pila));
    EsBuida(*pila);
    for (int i = 0; i < 10; i++)
    {
        Apilar(pila, (double) i);
        printf("El cim es %f \n", Cim(*pila));
    }
    printf("La pila hauria destar plena. Ho esta? %i \n", EsPlena(*pila));
    printf("El cim es %f \n", Cim(*pila));
    for (int i = 0; i < 9; i++)
    {
        Desapilar(pila);
        printf("El cim es %f \n", Cim(*pila));
    }
    Desapilar(pila);

    printf("La pila hauria destar buida. Ho esta? %i \n", EsBuida(*pila));

    Destruir(pila);
}
