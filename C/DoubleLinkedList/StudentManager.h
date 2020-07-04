#ifndef C_STUDENTMANAGER_H
#define C_STUDENTMANAGER_H

#include "DoubleLinkedList.h"
#include <string.h>


typedef struct Student{
    char name[100];
    char email[100];
    char DNI_letter;
    unsigned int DNI;
    DoubleLinkedList marks;
    bool sex;  // 1 for males, 0 for females
}Student;

typedef struct Manager{
    DoubleLinkedList *list;
    Student lastStudent;
}Manager;

const char DNI_letters[] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};


#endif //C_STUDENTMANAGER_H
