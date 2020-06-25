//
// Created by Sergi Vives on 15/4/20.
//

#ifndef LINEALDATASTRUCTURES_LLISTA_H
#define LINEALDATASTRUCTURES_LLISTA_H

// Includes
#include <stdbool.h>  // per a tractar booleans
#include <stdlib.h>  // Per a fer servir malloc
#include <stdio.h>  // per a fer servir la funcio printf en els jocs de proves

// Type defs
typedef struct Node {
    int v;
    struct Node* next;
    struct Node* previous;
} Node;

// Type defs
typedef struct Llista_encadenada {
    struct Node* PDI;
    int num_elems;
    struct Node* head;
    struct Node* tail;
} Llista_encadenada;

// Defines
// Errorcodes de la llista
#define EXIT 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define ERROR_LLISTA_INEXISTENT 3
#define ERROR_LLISTA_BUIDA 4
#define ERROR_LLISTA_PLENA 5
#define ERROR_FINAL_DE_LLISTA 6
#define ERROR_PRINCIPI_DE_LLISTA 7


// Capçaleres
int Crear(Llista_encadenada **ll);
int Destruir(Llista_encadenada *ll);
int Principi(Llista_encadenada *ll);
int Final(Llista_encadenada *ll);
int Avancar(Llista_encadenada *ll);
int Retrocedir(Llista_encadenada *ll);
int Es_Final(Llista_encadenada ll, bool *esfinal);
int Actual(Llista_encadenada ll, int *elem);
int Inserir(Llista_encadenada *ll, int elem);
int Esborrar(Llista_encadenada *ll);
int Longitud(Llista_encadenada ll, int *lon);
int Buscar(Llista_encadenada ll, int elem, bool *trobat);
int Cost_Buscar(Llista_encadenada ll, int elem, int *cost);
int Recorrer(Llista_encadenada ll);

#endif //LINEALDATASTRUCTURES_LLISTA_H
