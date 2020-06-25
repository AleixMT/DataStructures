//
// Created by Sergi Vives on 14/4/20.
//

#include "cua.h"
#include "../Stack/pila.h"

// Reserva la memoria per a l'estructura de la cua i inicialitza les dades de control
int Crear(Cua** ac, int size)
{
    *ac = (Cua*) malloc(sizeof(Cua));
    if (*ac == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut reservar memoria per a la ED de la cua\n");
        return ERROR_CREAR;  // Abortem la resta de la funció
    }

    (**ac).vector = malloc(sizeof(int) * size);


    if ((**ac).vector == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut reservar memoria per al vector de la pila\n");
        return ERROR_CREAR;  // Abortem el programa
    }

    (**ac).capacitat = size;
    (**ac).tail = -1;
    (**ac).front = -1;

    return EXIT;
}

int Encuar(Cua *ac, int elem)
{
    if (ac == NULL)
    {
        fprintf(stderr, "ERROR: S\'ha intentat encuar un element d\'una cua inexistent\n");
        return ERROR_CUA_INEXISTENT;  // Abortem el programa
    }

    bool param;
    EsPlena(*ac, &param);

    if (param)
    {
        // case where we have all elements consecutive to each other
        if (ac->front <= ac->tail)
        {
            ac->capacitat = ac->capacitat * 2;
            ac->vector = realloc(ac->vector, sizeof(int) * ac->capacitat);
        }
        // case where we did a "cycle" around the queue, either by queueng or dequeuing
        else
        {
            int *new_vector = (int*) malloc(sizeof(int) * ac->capacitat * 2);

            unsigned int j = 0;
            for (unsigned int i = ac->front; i < ac->capacitat; i++)
            {
                new_vector[j] = ac->vector[i];
                j++;
            }
            for (unsigned int i = 0; i <= ac->tail; i++)
            {
                new_vector[j] = ac->vector[i];
                j++;
            }
            j--;
            ac->front = 0;
            ac->tail = j;
            ac->capacitat = ac->capacitat * 2;
            ac->vector = new_vector;
        }

    }
    if (ac->front == -1) ac->front = 0;
    ac->tail = (ac->tail + 1) % ac->capacitat;
    ac->vector[ac->tail] = elem;
    return EXIT;  // Sempre podrem encuar
}

int Desencuar(Cua *ac)
{
    if (ac == NULL)
    {
        fprintf(stderr, "ERROR: S\'ha intentat desencuar un element d\'una cua inexistent\n");
        return ERROR_CUA_INEXISTENT;  // Abortem el programa
    }

    bool param;
    EsBuida(*ac, &param);
    if (param)
    {
        fprintf(stderr, "ERROR: S\'ha intentat desencuar d\'una cua buida\n");
        return(ERROR_CUA_BUIDA);
    }
    else
    {
        if (ac->front == ac->tail)  // La cua es queda buida per tant la ressetegem a l'estat inicial
        {
            ac->front = -1;
            ac->tail = -1;
        }
        else
        {
            ac->front = (ac->front + 1) % ac->capacitat;  // movem en un un element, per tant el deixem de tenir en compte
        }
        return EXIT;
    }
}

// Mira si la cua esta buida i retorna cert al boolea com a parametre
// Sempre retorna exit ja que en principi aquesta operacio no pot fallar
int EsBuida(Cua c, bool *b)
{
    if (c.front == -1)
    {
        *b = true;
    }
    else
    {
        *b = false;
    }
    return EXIT;
}

// Mira si la cua esta plena i retorna cert al boolea com a parametre
// Sempre retorna exit ja que en principi aquesta operacio no pot fallar
int EsPlena(Cua c, bool *b)
{
    if ((c.front == c.tail + 1) || (c.front == 0 && c.tail == c.capacitat - 1))
    {
        *b = true;
    }
    else
    {
        *b = false;
    }
    return EXIT;
}

int Destruir(Cua *ac)
{
    if (ac == NULL) {
        fprintf(stderr, "ERROR: S\'ha intentat destruir una cua inexistent\n");
        return ERROR_CUA_INEXISTENT;  // Abortem el programa
    }
    free(ac->vector);  // Destruim el vector
    free(ac);  // Alliberem la estructura de dades
    return EXIT;
}

// Inverteix els elements entre dues posicions de la cua
int Invertir(Cua *ac, int pos_inicial, int pos_final, Cua *out)
{
    if (pos_inicial > pos_final || pos_final == pos_inicial)
    {
        fprintf(stderr, "ERROR al invertir: els enters de posicio son incorrectes\n");
        return ERROR_PARAMETRES_INCORRECTES;
    }

    int elements_tractats = 0;
    int valor_actual = 0;  // per evitar warning
    bool param = false;
    Pila *pila = NULL;
    pila = CrearPila(1000);  // pila auxiliar
    // ens en portem una igual que al exemple
    pos_final--;
    pos_inicial--;
    while (!param)
    {
        Cap(*ac, &valor_actual);
        Desencuar(ac);
        if (elements_tractats >= pos_inicial && elements_tractats <= pos_final)  // dins de rang dinversio
        {
            Apilar(pila, valor_actual);
        }
        else  // Fora de rang d'inversio
        {
            Encuar(out, valor_actual);  // Encuem a la llista de sortida
        }
        if (elements_tractats == pos_final)
        {
            // fiquem dins de la llista de sortida en ordre invers
            while (!EsBuidaPila(*pila))
            {
                Encuar(out, Cim(*pila));
                Desapilar(pila);
            }
        }

        elements_tractats++;
        // Actualitzem estat de plenitud
        EsBuida(*ac, &param);
    }
    return EXIT;
}

/*
 * Funció auxiliar per a la rutina Fusionar
 * No segueix lexemple de rutina de les funcions ja que virtualment es una funcio "nested", llavors no cal
 * escriurela de la mateixa manera i a mes els errors que puguin apareixer es checkegen abans a la funcio fusionar
 */
bool ComprovarOrdre(Cua cua)
{
    int valor_anterior = INT_MIN, valor_actual;
    bool param;
    EsBuida(cua, &param);

    while (!param)
    {
        Cap(cua, &valor_actual);
        Desencuar(&cua);
        EsBuida(cua, &param);

        if (valor_anterior < valor_actual)
        {

            valor_anterior = valor_actual;

        }
        else
        {
            return false;
        }
    }
    return true;

}

int Fusionar(Cua cua_in1, Cua cua_in2, Cua *cua_out)
{
    bool llistaBuida1 = false, llistaBuida2 = false;
    int cap1 = 0, cap2 = 0;  // inicialitzo per eliminar warning
    /*if (ComprovarOrdre(cua_in1) && ComprovarOrdre(cua_in2))
    {*/
        EsBuida(cua_in1, &llistaBuida1);
        EsBuida(cua_in2, &llistaBuida2);

        while (!llistaBuida1 || !llistaBuida2)
        {
            // Actualitzem valors
            if (!llistaBuida1)
            Cap(cua_in1, &cap1);
            if (!llistaBuida2)
            Cap(cua_in2, &cap2);

            if (llistaBuida1)
            {
                Desencuar(&cua_in2);
                Encuar(cua_out, cap2);
            }
            else if (llistaBuida2)
            {
                Desencuar(&cua_in1);
                Encuar(cua_out, cap1);
            }
            else if (cap1 < cap2)
            {
                Desencuar(&cua_in1);
                Encuar(cua_out, cap1);
            }
            else
            {
                Desencuar(&cua_in2);
                Encuar(cua_out, cap2);
            }

            EsBuida(cua_in1, &llistaBuida1);
            EsBuida(cua_in2, &llistaBuida2);
        }
        return EXIT;
    /*}
    else
    {
        fprintf(stderr, "ERROR: Les cues a fusionar no estan ordenades\n");
        return ERROR_CUA_BUIDA;
    }*/
}


// Retorna el primer element de la cua sense desencuarlo. Si la cua esta buida retorna error
int Cap(Cua c, int *elem)
{
    bool param;
    EsBuida(c, &param);
    if (param)
    {
        *elem = -1;
        fprintf(stderr, "ERROR: S\'ha intentat veure el cap d\'una cua buida\n");
        return ERROR_CUA_BUIDA;
    }
    else
    {
        *elem = c.vector[c.front];
        return EXIT;
    }
}

