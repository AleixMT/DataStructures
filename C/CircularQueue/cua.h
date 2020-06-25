//
// Created by Sergi Vives on 14/4/20.
//

#ifndef LINEALDATASTRUCTURES_CUA_H
#define LINEALDATASTRUCTURES_CUA_H

// Includes
#include <stdbool.h>  // per a tractar booleans
#include <stdlib.h>  // Per a fer servir malloc
#include <stdio.h>  // per a fer servir la funcio printf en els jocs de proves
#include <limits.h>  // Per invoacar els imbols de INT_MIN

// Type defs
typedef struct Cua {
    int* vector;
    int capacitat;
    int front;
    int tail;
} Cua;

// Defines
// Errorcodes de la cua
#define EXIT 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define ERROR_CUA_INEXISTENT 3
#define ERROR_CUA_BUIDA 4
#define ERROR_CUA_PLENA 5
#define ERROR_PARAMETRES_INCORRECTES 6

// Headers
int Crear(Cua **ac, int size);
int Encuar(Cua *ac, int elem);
int Desencuar(Cua *ac);
int Cap(Cua c, int *elem);
int EsBuida(Cua c, bool *b);
int EsPlena(Cua c, bool *b);
int Destruir(Cua *ac);
int Invertir(Cua *ac, int pos_inicial, int pos_final, Cua *out);
int Fusionar(Cua cua_in1, Cua cua_in2, Cua *cua_out);
bool ComprovarOrdre(Cua cua);


#endif //LINEALDATASTRUCTURES_CUA_H
