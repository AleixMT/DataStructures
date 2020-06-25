//
// Created by Sergi Vives on 21/5/2020.
//

#ifndef ORDENACIOCERCACOST_ARRAYLIST_H
#define ORDENACIOCERCACOST_ARRAYLIST_H

// Library includes
#include <stdbool.h>  // To use boolean types
#include <stdlib.h>  // To use malloc, realloc and free
#include <stdio.h>  // To use printf and file manipulation functions
#include <limits.h>  // To use datatype sumbols such as INT_MIN
#include <string.h>  // To use the String library
#include <math.h>  // To use square root
#include <time.h>  // To choose a random seed in combination with srand


// Project includes
#include "../_includes/ErrorCodes.h"

// Class defines
#define N 100000  // Max number of elements 10 ^ 5

// Type defs
typedef struct ArrayList {
    unsigned int* array;
    unsigned int max_elements;
    unsigned int num_elements;
} ArrayList;

// Function headers
// Basic functions
void create(ArrayList **arrayList);
bool destroy(ArrayList *arrayList);
bool isEmpty(ArrayList arrayList);
bool isFull(ArrayList arrayList);
void add(ArrayList *arrayList, unsigned int element);
unsigned int get(ArrayList arrayList, unsigned int position);
unsigned int removeAt(ArrayList *arrayList, unsigned int position);

// Decorators
unsigned int pop(ArrayList *arrayList);
unsigned int tail(ArrayList arrayList);
void addValues(ArrayList *arrayList, unsigned int elements[], unsigned int num_elements);

// Specific project functions
void toString(ArrayList arrayList);
void populate(ArrayList *arrayList, int num_elements);
void sortBubble(ArrayList *arrayList);
unsigned int searchBinary(ArrayList arrayList, unsigned int value, int *counter);

#endif //ORDENACIOCERCACOST_ARRAYLIST_H
