#include "StudentManager.h"

int test(int nargs, char* args[]) {
// test with unsigned ints

    DoubleLinkedList *list = create(sizeof(unsigned int));
    unsigned int *value = malloc(sizeof(unsigned int) * 4);
    value[0] = 2;
    value[1] = 12;
    value[2] = 2;
    value[3] = 3;
    unsigned int num_values;
    for (unsigned int i = 0; i < 4; i++) {
        add(list, &value[i]);
    }
    printf("Contingut inicial: \n");
    toScreen(*list, printInt);

    void **found;  // Array of pointers to void *
    find(*list, compareToUnsignedIntegers, &value[0], &found, &num_values);

    for (unsigned int i = 0; i < num_values; i++) {
        printUnsignedInt(found[i]);
    }
    printf("\n");

    destroy(list);

// test with students

    list = create(sizeof(Student));
    Student *students = malloc(sizeof(Student) * 4);

    strcpy(students[0].name, "Maria Jimenez");
    strcpy(students[0].email, "maria.jimenez@urv.cat");
    students[0].DNI = 25626333;
    students[0].DNI_letter = 'c';
    students[0].sex = false;

    strcpy(students[1].name, "Viki la vikinga");
    strcpy(students[1].email, "viki.romero@urv.cat");
    students[1].DNI = 25456333;
    students[1].DNI_letter = 'd';
    students[1].sex = false;

    strcpy(students[2].name, "Aleix Marine");
    strcpy(students[2].email, "aleix.marine@estudiants.urv.cat");
    students[2].DNI = 34567890;
    students[2].DNI_letter = 'x';
    students[2].sex = true;

    strcpy(students[3].name, "Pedrito Legend");
    strcpy(students[3].email, "fitnessfuerte@ponis.com");
    students[3].DNI = 34467890;
    students[3].DNI_letter = 'k';
    students[3].sex = true;

    for (unsigned int i = 0; i < 4; i++) {
        add(list, &students[i]);
    }
    printf("Contingut inicial: \n");
    toScreen(*list, printStudent);

    find(*list, compareToStudentDNI, &students[0], &found, &num_values);

    printf("\n%u", num_values);
    for (int i = 0; i < num_values; i++) {
        printStudent(found[i]);
    }
    destroy(list);
}