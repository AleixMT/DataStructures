/**
 * Fichero : thash.h      Fecha:03/04/2017
 * Autores:                                   
 *                                            
 *  fichero con la cabecera del TAD hash
 *                                            
 */


#ifndef __THASH_H_
#define __THASH_H_


typedef struct _hash_table hash_table;


/**
 * Función para crear la Tabla Hash. Siempre que sea necesario, considerar que
 * la inicialización de los valores debe ser 0 o NULL 
 *
 * Entrada: Número de casillas de la tabla hash
 *
 * Salida:
 *    Una estructura hash_table inicializada o NULL en caso de error
 */
hash_table *new_hashtable (int size, int (*hash_fn)(int,int));

/**
 * Funcion para liberar la memoria reservada de la estructura hash_table
 *
 * Entrada:
 *    Estructura hash_table a liberar
 */
void destroy_hashtable(hash_table *ht);

/**
 * Funcion para insertar un nuevo elemento en la tabla junto con su clave. Para
 * la resolución de colisiones, podéis implementar una lista enlazada
 *
 * Entrada:
 *    Estructura del TAD hash_table, la clave y el valor
 *
 * Salida: 
 */
void insert_hashtable(hash_table *ht, int clave, int valor);


/**
 * Estructura del TAD hash_table y clave del elemento a buscar.
 *
 * Entrada:
 *    Estructura hash_table y el elemento a buscar.
 *
 * Salida: Elemento encontrado. NULL en otro caso.
 */
int find_hashtable(hash_table *ht, int clave);



#endif



