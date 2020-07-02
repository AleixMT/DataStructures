#include "DoubleLinkedList.h"


/** AUXILIAR PRIVATE FUNCTIONS **/

/**
 * Copies size_t Bytes from origin to destination (assuming char = 1 Byte)
 * @param origin
 * @param destination
 * @param data_size
 */
void raw_copy(char *origin, char *destination, size_t data_size)
{
    for (int i = 0; i < data_size; i++)
        *(char *)(destination + i) = *(char *)(origin + i);
}


/**
 * Prints the content of the list using a function received by parameter.
 * @param list
 * @param f
 */
void toScreen(DoubleLinkedList list, void (*f)(void *))
{
    Node *node = list.head;
    while (node != NULL)
    {
        (*f)(node->data);
        node = node->next;
    }
}


/** MAIN PUBLIC FUNCTIONS **/

/**
 * Allocates the space required for the data structure and defines the datatype that each node
 * will hold.
 *
 * Aborts program if the memory allocation fails.
 * @param data_size data size of each element
 * @return
 */
DoubleLinkedList* create(size_t data_size)
{
    DoubleLinkedList* list = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not allocate memory for the double linked list. Aborting... \n");
        exit(ERROR_CREATE);
    }

    // Initialize fields
    (*list).tail = NULL;
    (*list).head = NULL;
    (*list).interest_point = NULL;
    (*list).size = 0;
    (*list).data_size = data_size;

    return list;
}


/**
 * Go through all the list destroying each element and finally destroys the list itself.
 *
 * Aborts program if the list does not exist.
 * @param list
 */
void destroy(DoubleLinkedList* list)
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not destroy the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_DESTROY);
    }

    Node* pointer = list->head;
    while (pointer != NULL)
    {
        free(pointer);
        pointer = pointer->next;
    }
    free(list);
}


/**
 * Adds an element behind the element pointed by the interest point. Due to that, elements can
 * not be inserted in the first position of the list. As such, if the interest point points to NULL,
 * the new element will be added on the first position.
 *
 * Aborts program if the list does not exist.
 * @param list
 * @param element
 * @return
 */
void add(DoubleLinkedList *list, void *element)
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not insert into the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);
    }
    else
    {
        if (list->interest_point == NULL)  // Interest point is pointing to the head of the list
        {
            if (list->size != 0)  // If pointing to the head of the list and list not empty
            {
                // Insert a node as the head of the list
                Node* node = (Node*) malloc(sizeof(Node));
                list->head->previous = node;
                node->next = list->head;
                node->previous = NULL;
                list->head = node;

                node->data = malloc(list->data_size);
                raw_copy((char *)(element), (char *)(node->data), list->data_size);
            }
            else  // If interest point pointing to NULL but no elements present --> list is empty, we add first (and last) element
            {
                // Insert the only node in the list
                Node* node = (Node*) malloc(sizeof(Node));
                node->next = NULL;
                node->previous = NULL;
                list->head = node;
                list->tail = node;

                node->data = malloc(list->data_size);
                raw_copy((char *)(element), (char *)(node->data), list->data_size);
            }
        }
        else  // Interest_point is pointing to an element
        {
            if (list->interest_point->next == NULL)  // The last element of the list
            {
                // Insert at the end
                Node* node = (Node*) malloc(sizeof(Node));
                node->next = NULL;
                node->previous = list->tail;
                list->tail->next = node;
                list->tail = node;

                node->data = malloc(list->data_size);
                raw_copy((char *)(element), (char *)(node->data), list->data_size);
            }
            else  // interest_point is pointing to a node between two nodes
            {
                // Insert the new element in between the interest point and its next element
                Node* node = (Node*) malloc(sizeof(Node));
                node->next = list->interest_point->next;
                node->previous = list->interest_point;
                list->interest_point->next->previous = node;
                list->interest_point->next = node;

                node->data = malloc(list->data_size);
                raw_copy((char *)(element), (char *)(node->data), list->data_size);
            }
        }
        list->size = list->size + 1;
    }

}


/**
 * Gets the data of the node currently pointed by the interest point.
 *
 * Aborts the program if the interest point is outside of the list.
 * @param list
 * @return
 */
void* get(DoubleLinkedList list)
{
    if (list.interest_point != NULL)  // return only if we are pointing to an element
    {
        return list.interest_point;
    }
    else if (list.size != 0)
    {
        fprintf(stderr, "ERROR: Could not get the current node of the double linked list because the interest point is pointing outside of the list. Aborting... \n");
        exit(ERROR_OUT_OF_BOUNDS);
    }
    else
    {
        fprintf(stderr, "ERROR: Could not get the current node of the double linked list because the list is empty. Aborting... \n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);
    }
}


/**
 * Returns the number of elements in the list
 * @param list
 * @return
 */
unsigned int size(DoubleLinkedList list)
{
    return list.size;
}


/**
 * Makes the interest point point to the first element of the list.
 *
 * Aborts program if the list is empty or does not exist.
 * @param list
 */
void pointHead(DoubleLinkedList *list)
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not point to the head of the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);
    }
    if (list->head == NULL)  // && list->tail == NULL)
    {
        fprintf(stderr, "ERROR: Could not point to the head of the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);
    }
    else
    {
        list->interest_point = list->head;
    }
}


/**
 * Makes the interest point point to the last element of the list.
 *
 * Aborts program if the list is empty or does not exist.
 * @param list
 */
void pointTail(DoubleLinkedList *list)
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not point to the tail of the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);
    }
    if (list->head == NULL)  // && list->tail == NULL)
    {
        fprintf(stderr, "ERROR: Could not point to the tail of the double linked list because the list is empty. Aborting... \n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);
    }
    else
    {
        list->interest_point = list->tail;
    }
}


/**
 * Advances point of interest to the next of the list.
 * @param list
 */
void pointNext(DoubleLinkedList *list)
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not point to the next element of the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);
    }
    if (list->interest_point != NULL)  // Advance to the next element pointed by PDI
    {
        // We do not advance because we reserve the special meaning of interest point being NULL for the head of the list
        if (list->interest_point->next != NULL)
        {
            list->interest_point = list->interest_point->next;
            return;
        }
        else
        {
            fprintf(stderr, "ERROR: Could not point to the next element of the double linked list because is the last element. Aborting... \n");
            exit(ERROR_OUT_OF_BOUNDS);
        }
    }
    else if (list->size != 0)
    {
        /*
         * If interest point points to NULL but there are elements, we point to the "ghost" element at the head
         * of the list, so we set the interest point to the head of the list.
         */
        list->interest_point = list->head;
        return;
    }
    else  // Point of interest points NULL and there are 0 elements
    {
        fprintf(stderr, "ERROR: Could not point to the next element of the list because the double linked list is empty. Aborting... \n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);
    }
}


/**
 * Moves the point of interest to the previous element of the list.
 * If the currently pointed element is the first element, the point of interest
 * will point "outside" of the list. In this state, insertion will be done at
 * the head of the list.
 * @param list
 */
void pointPrevious(DoubleLinkedList *list)
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not point to the previous element of the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);
    }
    if (list->interest_point != NULL)  // We only move backwards if we point to an element
    {
        // Interest point can be set to point NULL if interest point is currently pointing the first element!
        list->interest_point = list->interest_point->previous;
        return;
    }
    else if (list->size != 0)
    {
        fprintf(stderr, "ERROR: Could not point to the previous element of the list because the PDI is already pointing outside of the list. Aborting... \n");
        exit(ERROR_OUT_OF_BOUNDS);
    }
    else
    {
        fprintf(stderr, "ERROR: Could not point to the previous element of the list because the double linked list is empty. Aborting... \n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);
    }
}


/**
 * Returns true if the interest point is pointing to the last, false otherwise.
 * @param list
 * @return
 */
bool isEnd(DoubleLinkedList list)
{
    if (list.interest_point != NULL)
    {
        if (list.interest_point->next != NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        // We are outside of the list and technically at the very beginning
        return false;
    }
}

void** find(DoubleLinkedList list, void (*f)(void *), void *element, unsigned int *num_elements_found)
{
    Node * ptr = NULL;
    ptr = list.head;
   // void* found_elements[];
    while (ptr != NULL)
    {
        ptr = ptr->next;
    }
    return NULL;
}


/*
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
*/





