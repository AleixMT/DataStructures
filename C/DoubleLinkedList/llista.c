//
// Created by Sergi Vives on 15/4/20.
//

#include "llista.h"

//
int Crear(Llista_encadenada **ll)
{
    *ll = (Llista_encadenada*) malloc(sizeof(Llista_encadenada));
    if (*ll == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut reservar memoria per a la ED de la llista\n");
        return ERROR_CREAR;  // Abortem la resta de la funció
    }

    // Inicialitzem dades
    (**ll).tail = NULL;
    (**ll).head = NULL;
    (**ll).PDI = NULL;
    (**ll).num_elems = 0;

    return EXIT;
}

// Recorre la llista destruint tots els nodes i finalment destrueix la ED de la llista
int Destruir(Llista_encadenada *ll)
{
    if (ll == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut destruir perque la llista no existeix\n");
        return ERROR_DESTRUIR;  // Abortem la resta de la funció
    }

    Node* pointer = ll->head;
    while (pointer != NULL)
    {
        free(pointer);
        pointer = pointer->next;
    }
    free(ll);
    return EXIT;
}

// Fa apuntar el PDI al primer element
int Principi(Llista_encadenada *ll)
{
    if (ll->head == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut fer apuntar al principi de la llista ja que head apunta a NULL, per tant la llista esta buida\n");
        return ERROR_LLISTA_BUIDA;
    }
    else
    {
        ll->PDI = ll->head;
        return EXIT;
    }
}

// Fa apuntar el PDI a l'últim element
int Final(Llista_encadenada *ll)
{
    if (ll->head == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut fer apuntar al final de la llista ja que tail apunta a NULL, per tant la llista esta buida\n");
        return ERROR_LLISTA_BUIDA;
    }
    else
    {
        ll->PDI = ll->tail;
        return EXIT;
    }
}

int Longitud(Llista_encadenada ll, int *lon)
{
    *lon = ll.num_elems;
    return EXIT;
}


// Fa avançar el PDI (cap al final)
int Avancar(Llista_encadenada *ll)
{
    if (ll->PDI != NULL)  // Només podem avançar si no apuntem a un element
    {
        if (ll->PDI->next != NULL)  // No avancem fora de la llista, ja que sino tornariem al principi, i volem que PDI == NULL sigui per afegir al principi de la llista
        {
            ll->PDI = ll->PDI->next;
            return EXIT;
        }
        else
        {
            fprintf(stderr, "ERROR: No s'ha pogut avançar, final de la llista\n");
            return ERROR_FINAL_DE_LLISTA;
        }
    }
    else if (ll->num_elems != 0)  // Si apuntem a NULL pero hi han elements vol dir que apuntem al primer element real
    {
        ll->PDI = ll->head;
        return ERROR_FINAL_DE_LLISTA;
    }
    else   // PDI apunta a NULL i hi ha 0 elements, per tant esta buida si o si
    {
        fprintf(stderr, "ERROR: No s'ha pogut avançar la llista esta buida\n");
        return ERROR_LLISTA_BUIDA;
    }
}

// Fa retrocedir el PDI  (cap al principi)
int Retrocedir(Llista_encadenada *ll)
{
    if (ll->PDI != NULL)  // Només podem avançar si apuntem a un element
    {
        // permetem avançar fora de la llista des del principi, permetent insercions al principi de tot
        ll->PDI = ll->PDI->previous;  // compte pot ser que PDI apunti a NULL
        return EXIT;
    }
    else if (ll->num_elems != 0)
    {
        fprintf(stderr, "ERROR: No s'ha pogut retrocedir, estem al principi de la llista\n");
        return ERROR_PRINCIPI_DE_LLISTA;
    }
    else
    {
        fprintf(stderr, "ERROR: No s'ha pogut retrocedir, la lllista esta buida\n");
        return ERROR_LLISTA_BUIDA;
    }
}

// Comprova si es el PDI apunta al final de la llista. Si la llista esta buida retorna error.
int Es_Final(Llista_encadenada ll, bool *esfinal)
{
    if (ll.PDI != NULL)  // Només podem avançar si apuntem a un element
    {
        // Apuntem a un element. Si es l'últim el seu next apunta a null
        if (ll.PDI->next != NULL)  // No avancem fora de la llista
        {
            // Apunta a un altre element per tant fals
            *esfinal = false;
        }
        else
        {
            // El punter next del PDI apunta a un element que apunta a null, per tant es l'últim
            *esfinal = true;
        }
        return EXIT;
    }
    else if (ll.num_elems != 0)  // estem al principi, retornem fals
    {
        *esfinal = false;
        return EXIT;
    }
    else  // apuntem a NULL i no hi ha elements
    {
        *esfinal = false;
        fprintf(stderr, "ERROR: No s'ha pogut comprovar si era el final, llista buida\n");
        return ERROR_LLISTA_BUIDA;
    }
}

// Retornem l'element al que apunta l'element per pantalla
int Actual(Llista_encadenada ll, int *elem)
{
    if (ll.PDI != NULL)  // Només podem retronar alguna cosa si apuntem a un element
    {
        *elem = ll.PDI->v;
        return EXIT;
    }
    else if (ll.num_elems != 0)
    {
        fprintf(stderr, "ERROR: No s'ha pogut tornar element actual, estem al principi (fora) de la llista\n");
        return ERROR_PRINCIPI_DE_LLISTA;
    }
    else
    {
        fprintf(stderr, "ERROR: No s'ha pogut tornar element actual, la llista esta buida\n");
        return ERROR_LLISTA_BUIDA;
    }
}

/*
 * Insereix just darrer de l'element al que apunta el PDI. Degut a aixo en
 * principi no podriem afegir al davant de tot de la llista. Per tant, he decidit que si el PDI
 * apunta a null pero hi han elements, aquests s'afegeixen al cim
 */

int Inserir(Llista_encadenada *ll, int elem)
{
    if (ll == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut inserir perque la llista no existeix\n");
        return ERROR_LLISTA_INEXISTENT;  // Abortem la resta de la funció
    }
    else
    {
        if (ll->PDI == NULL)  // aqui el PDI apunta al "cim" de la llista
        {
            if (ll->num_elems != 0)  // Si apuntem a null, i hi han elements, estem al "cim" de la llista, per tant
            {
                // Creem un node
                Node* node = (Node*) malloc(sizeof(Node));

                // i el fiquem al principi
                ll->head->previous = node;  // el primer node apunta ara al nou node
                node->next = ll->head;  // el nou node apunta a l'antic seguent com a primer
                node->previous = NULL;  // el al que apunta el nou node es NULL
                node->v = elem;  // Afegim el valor

                // Actualitzem primer element
                ll->head = node;
            }
            else  // Si apuntem a null i no hi ha elements
            {
                // Si apuntem a NULL i noo hi ha elements a la llista, passem a tenir un sol element
                // Creem un node
                Node* node = (Node*) malloc(sizeof(Node));

                // inicialitzem
                node->next = NULL;  // el nou node apunta a cap lloc
                node->previous = NULL;  // el nou node no apunta a cap lloc
                node->v = elem;  // Afegim el valor

                // i el fiquem al principi i al final
                ll->head = node;  // el primer node apunta ara al nou node que sera el primer i ultim
                ll->tail = node;  // a lultim tambe!


            }
        }
        else  // El PDI apunta a algun element
        {
            if (ll->PDI->next == NULL)  // Estem al final de la llista
            {
                // Creem un node
                Node* node = (Node*) malloc(sizeof(Node));

                // inicialitzem
                node->next = NULL;  // el nou node apunta a cap lloc perque es l'últim
                node->previous = ll->tail;  // el nou node no apunta al l'anterior final
                node->v = elem;  // Afegim el valor


                ll->tail->next = node;  // Fem que l'anterior ultim apunti al nou ultim
                ll->tail = node;  // Fem a aquest que seria l'últim element
            }
            else  // Estem a un node intermig dins de la llista
            {
                // Creem un node
                Node* node = (Node*) malloc(sizeof(Node));

                // inicialitzem ficantlo al mig
                node->next = ll->PDI->next;  // el nou node apunta a al seguent element
                node->previous = ll->PDI;  // el nou node apunta al node del PDI
                node->v = elem;  // Afegim el valor

                // canviem els nodes consecutius
                ll->PDI->next->previous = node;
                ll->PDI->next = node;
            }
        }
        // i apuntem +1 element
        ll->num_elems = ll->num_elems + 1;  // Ho escric aixi per si hi ha trouble amb decrementacio de punters

        return EXIT;  // Si la llistano es inexistent sempre podrem inserir
    }

}

int Recorrer(Llista_encadenada ll)
{
    printf("Contingut de la llista (Si no hi ha res esta buida):\n");
    Node * ptr = NULL;
    ptr = ll.head;
    while (ptr != NULL)
    {
        printf("%i ", ptr->v);
        ptr = ptr->next;
    }
    printf("\n");
    return EXIT;
}

int Esborrar(Llista_encadenada *ll)
{
    if (ll == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut esborrar perque la llista no existeix\n");
        return ERROR_LLISTA_INEXISTENT;  // Abortem la resta de la funció
    }
    else
    {
        if (ll->PDI == NULL)  // aqui el PDI apunta al "cim" de la llista
        {
            // Si apuntem a null no podem borrar res
            fprintf(stderr, "ERROR: No s'ha pogut esborrar element actual, estem al principi (fora) de la llista\n");
            return ERROR_PRINCIPI_DE_LLISTA;
        }
        else  // El PDI apunta a algun element
        {
            // El seguent bloc es tot else if per a que siguin mutuament exclusiu!
            // Ordre important!
            if (ll->PDI->next == NULL && ll->PDI->previous == NULL)  // Ultim element de la llista
            {
                // Alliberem memory
                free(ll->PDI);
                // Ressetegem a estat inicial
                ll->PDI = NULL;
                ll->tail = NULL;
                ll->head = NULL;
                // I els num elems es fa automaticament
            }
            else if (ll->PDI->next == NULL)  // Estem al final de la llista
            {
                // Posem que el nou últim node apunti a null
                ll->PDI->previous->next = NULL;
                // Actualitzem el node contigu com lultim node
                ll->tail = ll->PDI->previous;
                // Alliberem memory
                free(ll->PDI);
                // Fem que el PDI apunti al tail
                ll->PDI = ll->tail;
            }
            else if (ll->PDI->previous == NULL)  // Estem al principi de la llista
            {
                // Posem que el nou primer node apunti a null
                ll->PDI->next->previous = NULL;
                // Actualitzem el node contigu com primer node node
                ll->head = ll->PDI->next;
                // Alliberem memory
                free(ll->PDI);
                // Fem que el PDI es mogui automaticament al primer node
                ll->PDI = ll->head;
            }
            else  // Estem a un node intermig dins de la llista
            {
                // Agafem node seguent del que volem borrar i fem que el punter seguent del node previ al que volem borrar apunti aa aquest
                ll->PDI->previous->next = ll->PDI->next;
                // Agafem node previ al que volem borrar i fem que el punter previ del node seguent al que volem vborrar apunti a aquest
                ll->PDI->next->previous = ll->PDI->previous;
                // Guardem una ref per poder lliberar memory i redcuperar una adreça contigua pel PDI
                // De forma arbitraria escollim els seguent node
                Node * n = ll->PDI->next;
                // Alliberem memory
                free(ll->PDI);
                // recuperem adreça
                ll->PDI = n;
            }
            // i apuntem -1 element
            ll->num_elems = ll->num_elems - 1;  // Ho escric aixi per si hi ha trouble amb decrementacio de punters
            return EXIT;  // Si la llista no es inexistent sempre podrem esborrar
        }
    }
}

int Buscar(Llista_encadenada ll, int elem, bool *trobat)
{
    Node * ptr = NULL;
    ptr = ll.head;
    while (ptr != NULL)
    {
        if (ptr->v == elem)
        {
            *trobat = true;
            return EXIT;
        }
        ptr = ptr->next;
    }
    *trobat = false;
    return EXIT;
}

int Cost_Buscar(Llista_encadenada ll, int elem, int *cost)
{
    Node * ptr = NULL;
    *cost = 0;
    ptr = ll.head;
    while (ptr != NULL)
    {
        *cost = *cost + 1;  // Coses de sortirse fora de la mem

        if (ptr->v == elem)
        {
            return EXIT;
        }
        ptr = ptr->next;
    }
    return EXIT;
}