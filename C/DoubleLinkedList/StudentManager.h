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

// Const and defines
const char DNI_letters[] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
#define MAX_CHAR_IN_FIELDS 100

bool isDNICorrect(unsigned int DNI, char letter);
bool addStudent(DoubleLinkedList *list, char *name, char *email, char DNI_letter, unsigned int DNI, DoubleLinkedList marks, bool sex);
int compareToUnsignedIntegers(void *int1, void *int2);
int compareToDoubles(void *double1, void *double2);
int compareToIntegers(void *int1, void *int2);
int compareToStudentName(void *student1, void *student2);
int compareToStudentDNI(void *student1, void *student2);
void printStudent(void *n);
char * replaceUnderscores(char * string, unsigned int num_chars);
char * replaceSpaces(char * string, unsigned int num_chars);
void printUnsignedInt(void *n);
void printFloat(void *f);
void printInt(void *n);
char * toUpperCase(char * string, unsigned int size);
char charToUpperCase(char character);
void copy(char *origin, char *destination, size_t data_size);
void clean_stdin();


#endif //C_STUDENTMANAGER_H
