//
// Created by Sergi Vives on 14/4/20.
//
#include "cua.h"

int main(int nargs, char* args[])
{
    Cua* cua_in = NULL;
    Cua* cua_out = NULL;
    Cua* cua_tmp = NULL;
    bool resultat_EsBuida;
    int pisos, nombre_actual, nombre_anterior;

    Crear(&cua_in, 10);
    Crear(&cua_out, 10);

    if (nargs == 1)
    {
        pisos = 10;
    }
    else
    {
        pisos = atoi(args[1]);
    }

    // Hardcodegem el primer pis
    Encuar(cua_in, 0);
    Encuar(cua_in, 1);
    Encuar(cua_in, 0);
    // Consruim el triangle per pantalla
    printf("0 1 0\n");

    for (int i = 0; i < pisos; i++)
    {
        resultat_EsBuida = false;
        nombre_anterior = 0;  // important inicialitzar el nombre anterior a 0!

        // No estara mai buida el primer cop
        while (!resultat_EsBuida)
        {
            // treiem l'element actual
            Cap(*cua_in, &nombre_actual);
            Desencuar(cua_in);

            // Encuem a l'altra cua fent la suma pertinent
            Encuar(cua_out, nombre_actual + nombre_anterior);
            // Construim triangle per pantalla
            printf("%i ", nombre_actual + nombre_anterior);

            // Preparem dades per seguent iteracio:
            // Guardem el nombre actual a la variable de l'anterior nombre
            nombre_anterior = nombre_actual;

            // Actualitzem boolea de buidesa
            EsBuida(*cua_in, &resultat_EsBuida);
        }
        // Acabem iteracio afegint un 0 per augmentar en un digit la linia actual
        Encuar(cua_out, 0);

        // Construim triangle per pantalla
        printf("%i\n", 0);

        // Intercambiem punters
        cua_tmp = cua_in;
        cua_in = cua_out;
        cua_out = cua_tmp;
    }
}