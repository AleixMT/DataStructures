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

/**
 * Prints the content of the list backwards if true is specified using a function received by parameter
 * @param list
 * @param f
 */
void toScreenBackwards(DoubleLinkedList list, void (*f)(void *), bool backwards)
{
    if (backwards)
    {
        Node *node = list.tail;
        while (node != NULL)
        {
            (*f)(node->data);
            node = node->previous;
        }
    }
    else
    {
        toScreen(list, f);
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
 * Even though a pointer to the data is received, no aliasing is produced since we raw_copy the data received.
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
 * Adds an element using an order determined by the function parameter and returns true only if element is not present.
 * It does not add anything to the list and returns false otherwise.
 *
 * Even though a pointer to the data is received, no aliasing is produced since we raw_copy the data received.
 *
 * Aborts program if the list does not exist.
 * @param list
 * @param element
 * @param f
 * @return
 */
bool sortedAdd(DoubleLinkedList *list, void *element, int (*f)(void *, void *))
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not insert into the double linked list because it does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);
        return false;
    }
    else
    {
        if (list->size != 0)  // if list not empty
        {
            Node *ptr = list->head;
            int comparationResult = f(ptr->data, element);
            if (comparationResult == 0)  // If student present abort
            {
                return false;
            }
            else if (comparationResult > 0)  // Element bigger than the current. Keep iterating
            {
                ptr = ptr->next;
            }
            else  // Element smaller. Insert before
            {
                // Insert a node as the head of the list
                Node* node = (Node*) malloc(sizeof(Node));
                list->head->previous = node;
                node->next = list->head;
                node->previous = NULL;
                list->head = node;

                node->data = malloc(list->data_size);
                raw_copy((char *)(element), (char *)(node->data), list->data_size);

                list->size = list->size + 1;
                return true;
            }
            // Iterate over all elements - 1 in the double linked list
            for (unsigned int i = 0; i < list->size - 1; i++)
            {
                int comparationResult = f(ptr->data, element);
                if (comparationResult == 0)  // If student present abort
                {
                    return false;
                }
                else if (comparationResult > 0)  // Element bigger than the current. Keep iterating
                {
                    ptr = ptr->next;
                }
                else  // Insert between elements
                {
                    // Insert the new element in between the interest point and its next element
                    Node* node = (Node*) malloc(sizeof(Node));
                    node->next = ptr;
                    node->previous = ptr->previous;
                    ptr->previous->next = node;
                    ptr->previous = node;

                    node->data = malloc(list->data_size);
                    raw_copy((char *)(element), (char *)(node->data), list->data_size);

                    list->size = list->size + 1;
                    return true;
                }
            }
            // If we reach this part of the code element is biggest that all elements in the list and goes to the tail
            Node* node = (Node*) malloc(sizeof(Node));
            node->next = NULL;
            node->previous = list->tail;
            list->tail->next = node;
            list->tail = node;

            node->data = malloc(list->data_size);
            raw_copy((char *)(element), (char *)(node->data), list->data_size);

            list->size = list->size + 1;
            return true;
        }
        else  // List is empty, we add first (and last) element
        {
            // Insert the only node in the list
            Node* node = (Node*) malloc(sizeof(Node));
            node->next = NULL;
            node->previous = NULL;
            list->head = node;
            list->tail = node;

            node->data = malloc(list->data_size);
            raw_copy((char *)(element), (char *)(node->data), list->data_size);

            list->size = list->size + 1;
            return true;
        }
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
 * Returns by value the element pointed by the interest point. The interest point will always point to the next element after
 * popping an element except when the interest point is the last element, then the interest point will point to the new tail.
 * @param list
 * @return
 */
void* pop(DoubleLinkedList *list)
{
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: Could not pop the current element because the double linked list does not exist\n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);
    }
    else
    {
        if (list->interest_point == NULL)  // Interest point points to the ghost element outside of the list
        {
            fprintf(stderr, "ERROR: Could not pop the current element because the interest point is pointing outside of the list\n");
            exit(ERROR_OUT_OF_BOUNDS);
        }
        else  // Interest point points an element
        {
            void * result = malloc(list->data_size);
            raw_copy(list->interest_point->data, result, list->data_size);

            if (list->interest_point->next == NULL && list->interest_point->previous == NULL)  // Last element of the list
            {
                free(list->interest_point);
                list->interest_point = NULL;
                list->tail = NULL;
                list->head = NULL;
            }
            else if (list->interest_point->next == NULL)  // End of the list
            {
                list->interest_point->previous->next = NULL;
                list->tail = list->interest_point->previous;
                free(list->interest_point);
                list->interest_point = list->tail;
            }
            else if (list->interest_point->previous == NULL)  // Start of the list
            {
                list->interest_point->next->previous = NULL;
                list->head = list->interest_point->next;
                free(list->interest_point);
                list->interest_point = list->head;
            }
            else  // In between the list
            {
                list->interest_point->previous->next = list->interest_point->next;
                list->interest_point->next->previous = list->interest_point->previous;
                Node * n = list->interest_point->next;
                free(list->interest_point);
                list->interest_point = n;
            }
            list->size = list->size - 1;
            return result;
        }
    }
}


/**
 * Deletes all matching elements using pointer to function f as a comparator between generic types. Returns de number
 * of deleted elements.
 * @param list
 * @param f
 * @param element
 * @return
 */
unsigned int delete(DoubleLinkedList *list, int (*f)(void *, void *), void *element)
{
    Node *ptr = list->head, *tmp;
    unsigned int num_elements_found = 0;

    // Count all matching elements in the list
    while (ptr != NULL)
    {
        if (f(element, ptr->data) == 0)
        {
            tmp = list->interest_point;
            list->interest_point = ptr;
            pop(list);  // Reuse pop function
            list->interest_point = tmp;
            num_elements_found++;
        }
        ptr = ptr->next;
    }
    return num_elements_found;
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


/**
 * Finds all matching elements in the double linked list using the comparison function parameter with the generic parameter
 * void *element and returns it using the array void ***found parameter. Also fills the variable num_elements_found with
 * the number of matching elements.
 *
 * Returns true if any match occurs, false otherwise.
 * Also note that ***found points to NULL if no elements are found.
 * @param list
 * @param f
 * @param element
 * @param found
 * @param num_elements_found
 * @return
 */
bool find(DoubleLinkedList list, int (*f)(void *, void *), void *element, void ***found, unsigned int *num_elements_found)
{
    Node *ptr = list.head;
    *num_elements_found = 0;
    bool result = false;

    // Count all matching elements in the list
    while (ptr != NULL)
    {
        if (f(element, ptr->data) == 0)
        {
            result = true;
            (*num_elements_found)++;
        }
        ptr = ptr->next;
    }

    // Allocate an array of pointers to the generic type void *
    (*found) = malloc(sizeof(void *) * (*num_elements_found));

    // Loop another time to append matching elements (two identical loops to optimize memory)
    unsigned int i = 0;
    ptr = list.head;
    while (ptr != NULL)
    {
        if (f(element, ptr->data) == 0)
        {
            (*found)[i] = malloc(list.data_size);  // Allocate a generic element
            raw_copy((char *) ptr->data, (char *) (*found)[i], list.data_size);  // Copy to the found list
            i++;
        }
        ptr = ptr->next;
    }
    return result;
}






