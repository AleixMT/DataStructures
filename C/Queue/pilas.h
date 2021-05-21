//
// Created by aleixmt on 21/4/21.
//

typedef struct Pila {
    int* vector;
    int num_elems;
    int capacidad;
} Pila;

Pila* crearPila();
void apilar(int elem, Pila* pila);

void imprimirPila(Pila pila);  // No necesita puntero porque no modifica la pila
Pila* copiarValoresPila(Pila* pila);
int desapilar(Pila* pila);
void borrarPila(Pila *pila);
