//
// Created by aleixmt on 21/4/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "colas.h"

Cola* crearCola()
{
    Cola* C = malloc(sizeof(Cola));
    (*C).front = -1;
    (*C).tail = -1;
    (*C).capacidad = 1000;
    (*C).num_elems = 0;
    (*C).vector = malloc(sizeof(int) * (*C).capacidad);
    return C;
}


void encolar(int elem, Cola* C)
{
    if ((*C).num_elems == 0)  // Mirar si esta vacia
    {
        (*C).tail = 0;
        (*C).front = 0;

        (*C).vector[(*C).tail] = elem;
    }
    else if ((*C).num_elems == (*C).capacidad)  // cola llena
    {
        printf("COLA LLENA!!\n");
        exit(1);
    }
    else  // Cola a medio llenar, apilar normal
    {
        (*C).tail = (*C).tail + 1;
        (*C).vector[(*C).tail] = elem;
    }
    (*C).num_elems = (*C).num_elems + 1;
    return;
}


void imprimirCola(Cola* C)
{
    for (int i = (*C).front; i <= (*C).tail; i++)
    {
        printf("%i, ", (*C).vector[i]);
    }
    printf("\n");
}

int sumaMenores(Cola* C, int X)
{
    int suma = 0;
    while ((*C).num_elems != 0)
    {
        int element = desencolar(C);
        if (element < X)
        {
            suma = suma + element;
        }
    }
    return suma;
}

int desencolar(Cola* C)
{
    if ((*C).num_elems == 0)
    {
        printf("COLA VACIA!!\n");
        exit(1);
    }
    else
    {
        int elem = (*C).vector[(*C).front];
        for (int i = 0; i < (*C).num_elems - 1; i++)
        {
            (*C).vector[i] = (*C).vector[i + 1];
        }
        (*C).tail--;
        (*C).num_elems--;
        return elem;
    }
}


void borrarCola(Cola *C)
{
    free((*C).vector);
    free(C);
}
