#include "StudentManager.h"

// Function to print an integer
void printInt(void *n)
{
    printf("%d ", *(int *)n);
    printf("\n");
}

// Function to print a float
void printFloat(void *f)
{
    printf("%f ", *(float *)f);
    printf("\n");
}

// Function to print an unsigned integer
void printUnsignedInt(void *n)
{
    printf("%u ", *(unsigned int *)n);
}

// Function to print a student
void printStudent(void *n)
{
    Student student = *((Student *)(n));
    printf("%u-%c %s %s ", student.DNI, student.DNI_letter, student.name, student.email);
    if (student.sex) printf("male");
    else printf("female");
    printf(" Registered in: %u/%u/%u\n", student.date.day, student.date.month, student.date.year);
}

int compareToStudentDNI(void *student1, void *student2)
{
    if (((Student *)(student1))->DNI > ((Student *)(student2))->DNI)
    {
        return 1;
    }
    else if (((Student *)(student1))->DNI < ((Student *)(student2))->DNI)
    {
        return -1;
    }
    return 0;
}

int compareToStudentName(void *student1, void *student2)
{
    return strncmp(((Student *)(student1))->name, ((Student *)(student2))->name, strlen(((Student *)(student1))->name));
}

int compareToIntegers(void *int1, void *int2)
{
    if (*((int *)(int1)) > *((int *)(int2)))
    {
        return 1;
    }
    else if (*((int *)(int1)) < *((int *)(int2)))
    {
        return -1;
    }
    return 0;
}

int compareToUnsignedIntegers(void *int1, void *int2)
{
    if (*((unsigned int *)(int1)) > *((unsigned int *)(int2)))
    {
        return 1;
    }
    else if (*((unsigned int *)(int1)) < *((unsigned int *)(int2)))
    {
        return -1;
    }
    return 0;
}


int main(int nargs, char* args[])
{
    // test with unsigned ints

    DoubleLinkedList *list = create(sizeof(unsigned int));
    unsigned int *value = malloc(sizeof(unsigned int) * 4);
    value[0] = 2;
    value[1] = 12;
    value[2] = 2;
    value[3] = 3;
    unsigned int num_values;
    for (unsigned int i = 0; i < 4; i++)
    {
        add(list, &value[i]);
    }
    printf("Contingut inicial: \n");
    toScreen(*list, printInt);

    void **found;  // Array of pointers to void *
    find(*list, compareToUnsignedIntegers, &value[0], &found, &num_values);

    for (unsigned int i = 0; i < num_values; i++)
    {
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
    students[0].date.day = 2;
    students[0].date.month = 2;
    students[0].date.year = 2;

    strcpy(students[1].name, "Viki la vikinga");
    strcpy(students[1].email, "viki.romero@urv.cat");
    students[1].DNI = 25456333;
    students[1].DNI_letter = 'd';
    students[1].sex = false;
    students[1].date.day = 5;
    students[1].date.month = 10;
    students[1].date.year = 3;

    strcpy(students[2].name, "Aleix Marine");
    strcpy(students[2].email, "aleix.marine@estudiants.urv.cat");
    students[2].DNI = 34567890;
    students[2].DNI_letter = 'x';
    students[2].sex = true;
    students[2].date.day = 2;
    students[2].date.month = 6;
    students[2].date.year = 12;

    strcpy(students[3].name, "Pedrito Legend");
    strcpy(students[3].email, "fitnessfuerte@ponis.com");
    students[3].DNI = 34467890;
    students[3].DNI_letter = 'k';
    students[3].sex = true;
    students[3].date.day = 5;
    students[3].date.month = 10;
    students[3].date.year = 12;

    for (unsigned int i = 0; i < 4; i++)
    {
        add(list, &students[i]);
    }
    printf("Contingut inicial: \n");
    toScreen(*list, printStudent);

    find(*list, compareToStudentDNI, &students[0], &found, &num_values);

    printf("\n%u", num_values);
    for (int i = 0; i < num_values; i++)
    {
        printStudent(found[i]);
    }
    destroy(list);
}
