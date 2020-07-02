#ifndef C_STUDENTMANAGER_H
#define C_STUDENTMANAGER_H

#include "DoubleLinkedList.h"

typedef struct Date{
    unsigned int day;
    unsigned int month;
    unsigned int year;
}Date;

typedef struct Student{
    char name[100];
    char correu[100];
    char DNI_letter;
    unsigned int DNI;
    DoubleLinkedList notes;
    Date date;
    bool sex;  // 1 for males, 0 for females
}Student;

#endif //C_STUDENTMANAGER_H
