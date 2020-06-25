//
// Created by Sergi Vives on 15/4/20.
//

#ifndef LINEALDATASTRUCTURES_SKIPLIST_H
#define LINEALDATASTRUCTURES_SKIPLIST_H

// Includes
#include <stdbool.h>  // per a tractar booleans
#include <stdlib.h>  // Per a fer servir malloc
#include <stdio.h>  // per a fer servir la funcio printf en els jocs de proves
#include "../includes/random.h"  // Per a fer servir els random
#include <limits.h>  // Per invocar els simbols de INT_MIN
#include <time.h>  // per invocar la funció de temps i generar llavors per a aleatoris


// Type defs
typedef struct Node {
    int v;
    struct Node* right;
    struct Node* left;
    struct Node* top;
    struct Node* down;
} Node;

// Type defs
typedef struct Skip_list {
    double p;
    unsigned int height;
    struct Node * top_left_node;
} Skip_list;

// Defines
// Errorcodes de la llista
#define EXIT 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define ERROR_LLISTA_INEXISTENT 3
#define ERROR_LLISTA_BUIDA 4
#define ERROR_LLISTA_PLENA 5

int Crear(Skip_list **sl);
int Destruir(Skip_list *sl);
int Inserir(Skip_list *sl, int elem);
int Esborrar (Skip_list *sl, int elem);
int Longitud(Skip_list sl, unsigned int *lon);
int Buscar(Skip_list sl, int elem, bool *trobat);
int Cost_Buscar(Skip_list sl, int elem, int *cost);
Node * CercaAfegiment(Skip_list sl, int elem);
void Recorrer(Skip_list sl);
Node * Cercar(Skip_list sl, int elem);
void toString(Skip_list sl);
unsigned int height(Skip_list sl);
void toMatrix(Skip_list sl);


#endif //LINEALDATASTRUCTURES_SKIPLIST_H
