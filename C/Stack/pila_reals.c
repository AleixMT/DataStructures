//
// Created by Sergi Vives on 4/11/2020.
//

#include "pila_reals.h"

// Inicialitzem la pila amb 10 elements
Pila* Crear(int size)
{
    Pila *pila = malloc(sizeof(Pila));
    if (pila == NULL)
    {
        fprintf(stderr, "No s'ha pogut reservar memoria per a la ED de la pila\n");
        exit(ERROR_CREAR);  // Abortem el programa
    }

    pila->num_elems = 0;
    pila->capacitat = 10;
    pila->vector = (double*) malloc(sizeof(double) * size);

    if (pila->vector == NULL)
    {
        fprintf(stderr, "No s'ha pogut reservar memoria per al vector de la pila\n");
        exit(ERROR_CREAR);  // Abortem el programa
    }
    return pila;
}

// Obtenim l'element del cim amb la formula element = ref inicial + numElements * mideDeCadaElement
double Cim(Pila p)
{
    if (EsBuida(p))
    {
        fprintf(stderr, "La pila está buida i se li ha demanat el cim\n");
        exit(ERROR_PILA_BUIDA);  // Abortem el programa
    }
    return p.vector[p.num_elems - 1];
}

// Apilem un nou element a la pila. Cal modificar els valors de la pila per aixo fem servir un punter (referencia)
void Apilar(Pila *ap, double elem)
{
    if (ap == NULL)
    {
        fprintf(stderr, "S\'ha intentat apilar un element a una pila inexistent\n");
        exit(ERROR_PILA_INEXISTENT);  // Abortem el programa
    }
    if (EsPlena(*ap))
    {
        fprintf(stderr, "La pila está plena\n");
        exit(ERROR_PILA_PLENA);  // Abortem el programa
    }
    ap->vector[ap->num_elems] = elem;
    ap->num_elems++;
}

// Desapilem un element de la pila. Simplement pel tipus d'implementacio cal restar un element
void Desapilar(Pila *ap)
{
    if (ap == NULL)
    {
        fprintf(stderr, "S\'ha intentat desapilar un element d\'una pila inexistent\n");
        exit(ERROR_PILA_INEXISTENT);  // Abortem el programa
    }
    if (EsBuida(*ap))
    {
        fprintf(stderr, "La pila está buida\n");
        exit(ERROR_PILA_BUIDA);  // Abortem el programa
    }
    ap->num_elems--;
}

// Comprovem si la pila esta buida i retornem cert si es aixi
bool EsBuida(Pila p)
{
    return (p.num_elems == 0);
}

// Comprovem que la pila esta plena i retornem cert si es aixi
bool EsPlena(Pila p)
{
    return (p.num_elems == p.capacitat);
}

// Alliberem la memoria ocupada per la pila
void Destruir(Pila *ap)
{
    if (ap == NULL)
    {
        fprintf(stderr, "S\'ha intentat desapilar un element d\'una pila inexistent\n");
        exit(ERROR_PILA_INEXISTENT);  // Abortem el programa
    }
    free(ap->vector);  // Destruim el vector
    free(ap);  // Alliberem la estructura de dades
    // O bé l'estructura s'allibera o bé no ho fa i el programa falla invocant Undefined Behaviour
    // per tant no hi ha moment ni comprovació que ens permetin llançar el codi d'error
}
