#ifndef C_STUDENTMANAGER_H
#define C_STUDENTMANAGER_H

#include "DoubleLinkedList.h"
#include <string.h>

typedef struct Date{
    unsigned int day;
    unsigned int month;
    unsigned int year;
}Date;

typedef struct Student{
    char name[100];
    char email[100];
    char DNI_letter;
    unsigned int DNI;
    DoubleLinkedList marks;
    Date date;
    bool sex;  // 1 for males, 0 for females
}Student;

typedef struct Manager{
    DoubleLinkedList list;
    Student lastStudent;
}Manager;

#endif //C_STUDENTMANAGER_H
