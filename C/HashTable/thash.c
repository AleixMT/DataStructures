//
// Created by aleixmt on 19/5/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct hash_table {
    int* vector;
    int capacidad;
    int (*hash_fn)(int, int);
} hash_table;

/**
 * Función para crear la Tabla Hash. Siempre que sea necesario, considerar que
 * la inicialización de los valores debe ser 0 o NULL
 *
 * Entrada: Número de casillas de la tabla hash
 *
 * Salida:
 *    Una estructura hash_table inicializada o NULL en caso de error
 */
hash_table * new_hashtable (int size, int (*hash_fn)(int, int))
{
    hash_table *table = malloc(sizeof(hash_table));

    (*table).capacidad = size;
    (*table).vector = malloc(sizeof(int) * size);

    (*table).hash_fn = hash_fn;

    return table;
}

/**
 * Funcion para liberar la memoria reservada de la estructura hash_table
 *
 * Entrada:
 *    Estructura hash_table a liberar
 */
void destroy_hashtable(hash_table *ht)
{
    free((*ht).vector);
    free(ht);
}

/**
 * Funcion para insertar un nuevo elemento en la tabla junto con su clave. Para
 * la resolución de colisiones, podéis implementar una lista enlazada
 *
 * Entrada:
 *    Estructura del TAD hash_table, la clave y el valor
 *
 * Salida:
 */
void insert_hashtable(hash_table *ht, int clave, int valor)
{
    (*ht).vector[(*ht).hash_fn(clave, (*ht).capacidad)] = valor;
}


/**
 * Estructura del TAD hash_table y clave del elemento a buscar.
 *
 * Entrada:
 *    Estructura hash_table y el elemento a buscar.
 *
 * Salida: Elemento encontrado. NULL en otro caso.
 */
int find_hashtable(hash_table *ht, int clave)
{
    return (*ht).vector[(*ht).hash_fn(clave, (*ht).capacidad)];
}

