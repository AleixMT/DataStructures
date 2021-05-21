#include <stdio.h>
#include <stdlib.h>

#include "thash.h"

#define TAM 10
#define R 0.6180334

/**
  * Imprime por pantalla un array de enteros de tamaño 'tam'
  */
void imprimirArray(int *array, int tam)
{
  int i;
  
  for (i = 0; i < tam; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

}
/**
  * Crea un array de enteros de tamaño 'tam' y lo inicializa con números 
  *  aleatorios
  */
int *crearArray(int tam) 
{
  int *lista, i;
  
  if (tam<=0) return NULL;
  
  lista = (int*)malloc(sizeof(int)*tam);
  if (!lista) return NULL;
  
  for (i = 0; i < tam; i++) {
    lista[i] = rand() % TAM;
  }
  
  return lista;
}


/** 
  * Crear una función que busque en un array no ordenado el primer multiplo
  * común encontrado de los valores valor1 y valor2 pasados como parámetro y
  * devuelva su índice. Por ejemplo, si se pasa los valores 11 y 5 en el
  * siguiente array de tamaño 10:
  *      _____________________________
  *     |56|23|11|89|55|99|34|23|22|12|
  *      -----------------------------
  *
  * debe devolver 4 que es el índice de 55 que es múltiplo de 5 y 11
  *
  * ENTRADA:
  *   valor1: valor 1 para buscar en la lista sus multiplo común
  *   valor2: valor 2 para buscar en la lista sus multiplo común
  *   array: array con los valores
  *   tamArray: tamaño del array 'array'
  *
  * SALIDA:
  *   Índice de la posición del primer común múltiplo encontrado si existe.
  *   -1 si no se encuentra
  */
int busquedaComunMultiplo(int valor1, int valor2, int *array, int tamArray)
{ 
  return 0;
}

/** 
  * Crear una tabla hash de función multiplicación y añadir los pares claves-valor
  * leidos desde un archivo. El tamaño de la tabla deberá también obtenerse desde
  * el archivo. El tamaño de tabla no tiene por qué coincidir con el número de pares.
  *
  * El formato del archivo es el siguiente:
  * 
  * tamanio_tabla
  * clave_0 valor_0
  *     ...
  * clave_n valor_n
  * 
  * Ejemplo:
  * 10
  * 8346 1
  * 1783 3
  * 1231 0
  * 4328 2
  * 7793 4

  *
  * La función deberá leer el archivo recibido como parámetro y devolver una 
  * tabla hash con los valores insertados con sus claves.
  * 
  * ejemplo crear tabla: new_hashtable(tam,hash_modulo);
  * ejemplo insertar: insert_hashtable(t,clave,valor);
  * 
  * NOTA: Antes de crear la tabla se necesita saber el tamaño, usa fscanf o fgets+atoi
  *       para guardar el tamaño y crear la tabla llamando a new_hashtable.
  *       Después se podrá continuar leyendo linea por linea e insertando en la tabla. 
  *
  * ENTRADA:
  *   
  *   nombre_archivo: nombre del archivo a leer. 
  *   tamanio_tabla: puntero a int donde guardar el tamaño leído de la tabla. 
  *
  * SALIDA:
  *   Tabla hash.
  */
int hash_multiplicacion(int tamanio_tabla, int clave)
{
    int D = clave * R;
    return (clave * R - D) * tamanio_tabla;
}

hash_table * leer_hash(const char * nombre_archivo)
{

    FILE * fp = fopen(nombre_archivo, "r");
    int *len, *read;
    printf("AAAAAAAAAAAAA");
    char * line = malloc(sizeof(char) * 1000);

    getline(&line, &len, fp);
    int size = atoi(line);

    hash_table * table = new_hashtable(size, hash_multiplicacion);
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("cosita");
        int key = atoi(strtok(line, " "));
        int value = atoi(strtok(line, " "));
        printf("key is: %i, value is: %i. \n", key, value);
        insert_hashtable(table, key, value);
    }

    fclose(fp);
    return table;
}

/**
  * Main
  */
int main(int argc, char *argv[])
{
    hash_table * table = new_hashtable(10, hash_multiplicacion);

    insert_hashtable(table, 34, 1000);
    insert_hashtable(table, 824, 736);
    insert_hashtable(table, 23, 1000);
    insert_hashtable(table, 1000, 1000);
    insert_hashtable(table, 3933, 1000);
    insert_hashtable(table, 67, 1000);
    insert_hashtable(table, 0, 1000);

    //printf("%i \n", find_hashtable(table, 824));
    find_hashtable(table, 824);
    find_hashtable(table, 23);

    destroy_hashtable(table);

  int *array, i, iloc, clave1, clave2,clave_x,valor_x;
  hash_table *t;
/*
  // Test primer ejercicio
  array = crearArray(TAM);
  imprimirArray(array, TAM);
  for(i = 0; i < TAM-1; i++) {
    iloc = busquedaComunMultiplo(array[i], array[i+1], array, TAM);
    printf("El común múltiplo de %d y %d ", array[i], array[i+1]);
    if (iloc<0) printf("no existe en el array.\n");
    else printf("está en el índice %d.\n", iloc);
  }
  free(array);
  */
 // Test segundo ejercicio

 clave1 = 1231;
 clave2 = 8346;
 clave_x = 9201; //Se puede usar este par para otras comprobaciones
 valor_x = -1;

  t = leer_hash("datos_hash.txt"); //Cambiar aqui archivo para otras pruebas

  if(t==NULL)
  {
    printf("La tabla no se ha leído correctamente\n");
    return -1;
  }

  printf("El valor para la clave %d es %d debería ser %d\n", clave1, find_hashtable(t, clave1),0);
  printf("El valor para la clave %d es %d debería ser %d\n", clave2, find_hashtable(t, clave2),1);
  printf("El valor para la clave %d es %d debería ser %d\n", clave_x, find_hashtable(t, clave_x),valor_x);
  
  destroy_hashtable(t);

  return 1;

}


