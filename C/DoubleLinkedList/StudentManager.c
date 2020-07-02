#include "StudentManager.h"

// Function to print an integer
void printInt(void *n)
{
    printf("%d", *(int *)n);
    printf("\n");
}

// Function to print a float
void printFloat(void *f)
{
    printf("%f", *(float *)f);
    printf("\n");
}

// Function to print an unsigned integer
void printUnsignedInt(void *n)
{
    printf("%u", *(unsigned int *)n);
    printf("\n");
}

// Function to print a student
void printStudent(void *n)
{
    printf("\n");
}

int main(int nargs, char* args[])
{
    DoubleLinkedList *list = create(sizeof(unsigned int));
    unsigned int value[] = {2, 3, 4, 5};
    for (unsigned int i = 0; i < 4; i++)
    {
        add(list, &value[i]);
    }
    toScreen(*list, printInt);
    destroy(list);
}
