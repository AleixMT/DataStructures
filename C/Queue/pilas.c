//
// Created by aleixmt on 21/4/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "pilas.h"

Pila* crearPila()
{
  Pila* P = malloc(sizeof(Pila));
  (*P).num_elems = 0;
  (*P).capacidad = 1000;
  (*P).vector = malloc(sizeof(int) * 1000);
  return P;
}


void apilar(int elem, Pila* P)
{
    if ((*P).num_elems < (*P).capacidad)
    {
        (*P).vector[(*P).num_elems] = elem;
        (*P).num_elems = (*P).num_elems + 1;
    }
    else
    {
        printf("PILAS LLENAS!!\n");
        exit(1);
    }
}

int desapilar(Pila* pila)
{
    if ((*pila).num_elems > 0)
    {
        (*pila).num_elems--;
        return (*pila).vector[(*pila).num_elems];
    }
    else
    {
        printf("pila vacia\n");
        exit(1);
    }
}


void imprimirPila(Pila pila)
{
    printf("\n");
    for (int i = 0; i < pila.num_elems; i++)
    {
        int elem = pila.vector[i];
        printf("%i, ", elem);
    }
    printf("\n");
}


Pila* copiarValoresPila(Pila* pila)
{
    Pila* pilatemp = crearPila();
    while ((*pila).num_elems != 0)
    {
        int elem = desapilar(pila);
        apilar(elem, pilatemp);
    }
    return pilatemp;
}

void borrarPila(Pila *pila)
{

    free((*pila).vector);
    free(pila);
}

