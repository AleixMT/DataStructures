
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // To use booleans

#include "colas.h"
#include "pilas.h"

/**
  * Nota!! Se deberán usar las funciones de los TAD siempre que sea necesario.
**/

/** EJERCICIO
  * Crear una funcion que reciba una cola C y que devuelva la suma de los
  * elementos menores que el parametro X.
  *
  *   Ejemplo. Si tenemos la cola: 3 -> 11 -> 10 -> 4 -> 18
  *            y X vale 10, esta funcion debe devolver 7 (3+4)
  *
  *   OJO. La cola C debe quedar con los mismos elementos tras hacer el recorrido
  *
  * Entrada:
  *    P: Cola C a recorrer
  *    X: valor del umbral
  *
  * Salida:
  *    Devuelve la suma de los elementos menores que X en la cola C
  *
    int sumaMenores(Cola *C, int X)
    {

        int suma = 0;
        PNodo temp = C->principio;

        while(temp != NULL)
        {

            if(temp->dato < X)
            {
                suma += temp->dato;

            }
            temp = temp->siguiente;

        }

        return suma;

    } */

/** EJERCICIO
  * Copia los valores de la pila en otra y la devuelve. La pila original debe
  * quedar intacta!!
  *
  * Entrada:
  *     P: Pila P a recorrer
  *
  * Salida:
  *     Devuelve una nueva pila con los mismos valores
  *     que la pila P en orden inverso!!
  *
 **
    Pila copiarValoresPila(Pila P)
    {

        Pila P = crearPila();
        PNodo temp;

        temp = P->siguiente;

        while (temp)
        {
            apilar(temp->dato, P);

            temp=temp->siguiente;
        }

        return P;
    } */
/**
  *   Main de prueba
  */
    int main(int argc, char *argv[])
    {
        Pila *P1, *P2;
        Cola* C;
        int i, X;

        P1 = crearPila();
        printf("hello world!\n");
        C = crearCola();



        for (i = 0; i < 20; i++) {
            apilar(i, P1);
            encolar(i, C);
        }
        printf("-----------------------------------------------------------------\n");
        printf("[ANTES] Estado de cola:\n");
        imprimirCola(C);


        X = 10;
        printf("La suma de los datos menores de %d es %d\n", X, sumaMenores(C,X));
        printf("[DESPUES] Estado de cola:\n");
        imprimirCola(C);

        printf("-----------------------------------------------------------------\n");
        printf("[ANTES] Estado de la pila original:\n");
        imprimirPila(*P1);

        P2 = copiarValoresPila(P1);
        printf("La pila copiada es:\n");
        imprimirPila(*P2);
        printf("[DESPUES] Estado de la pila original:\n");
        imprimirPila(*P1);

        // todo bien hasta aqui
        borrarPila(P1);
        borrarPila(P2);
        borrarCola(C);
    }


