// Includes
#include <stdio.h>
#include <stdbool.h>  // To use booleans
#include <stdlib.h>
#include "../includes/ErrorCodes.h"  // Symbolic definition of error codes

// Type definition for a generic element of the list
typedef struct Node {
    void *data;
    struct Node* next;
    struct Node* previous;
} Node;

// Type definition for the list itself
typedef struct DoubleLinkedList {
    struct Node* interest_point;
    unsigned int size;
    struct Node* head;
    struct Node* tail;
    size_t data_size;
} DoubleLinkedList;

// Functions Headers
DoubleLinkedList* create(size_t data_size);
void destroy(DoubleLinkedList *doubleLinkedList);
void add(DoubleLinkedList *doubleLinkedList, void *element);
void* get(DoubleLinkedList doubleLinkedList);
unsigned int size(DoubleLinkedList doubleLinkedList);
void pointHead(DoubleLinkedList *doubleLinkedList);
void pointTail(DoubleLinkedList *doubleLinkedList);
void pointNext(DoubleLinkedList *doubleLinkedList);
void pointPrevious(DoubleLinkedList *doubleLinkedList);
void toScreen(DoubleLinkedList doubleLinkedList, void (*pointer_to_printer_function)(void *));
bool isEnd(DoubleLinkedList doubleLinkedList);
bool find(DoubleLinkedList doubleLinkedList, int (*pointer_to_comparator_function)(void *, void *), void *element, void ***found, unsigned int *num_elements_found);

/*
int Esborrar(Llista_encadenada *ll);
*/