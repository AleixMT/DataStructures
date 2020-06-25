//
// Created by Sergi Vives on 4/11/2020.
//

#ifndef LINEALDATASTRUCTURES_PILA_H
#define LINEALDATASTRUCTURES_PILA_H

// Includes
#include <stdbool.h>  // per a tractar booleans
#include <stdlib.h>  // Per a fer servir malloc
#include <assert.h>  // Per a fer explotar el programa en cas d'error
#include <stdio.h>  // per a fer servir la funcio printf en els jocs de proves

// Type defs
typedef struct Pila {
    int* vector;
    int num_elems;
    int capacitat;
} Pila;

// Defines
// Errorcodes de la pila
#define EXIT 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define ERROR_PILA_INEXISTENT 3
#define ERROR_PILA_BUIDA 4
#define ERROR_PILA_PLENA 5

// Errorcodes de la calculadora
#define ERROR_OPERAND_DESCONEGUT 6
#define ERROR_OPERACIO_NO_PERMESA 7
#define ERROR_APERTURA_FITXER 8
#define ERROR_INSUFICIENTS_OPERANDS 9
#define ERROR_RESULTAT_INCONSISTENT 10



// Headers
extern Pila* Crear(int size);
extern int Cim(Pila p);
extern void Apilar(Pila *ap, int elem);
extern void Desapilar(Pila *ap);
extern bool EsBuida(Pila p);
extern bool EsPlena(Pila p);
extern void Destruir(Pila *ap);

#endif //LINEALDATASTRUCTURES_PILA_H
