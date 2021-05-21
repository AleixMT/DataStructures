//
// Created by aleixmt on 21/4/21.
//


typedef struct Cola {
    int* vector;
    int capacidad;
    int num_elems;
    int front;
    int tail;
} Cola;

Cola* crearCola();
void encolar(int elem, Cola* C);
void imprimirCola(Cola* C);
int sumaMenores(Cola* C, int X);
int desencolar(Cola* C);
void borrarCola(Cola *C);