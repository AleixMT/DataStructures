#include "StudentManager.h"

/**
* Clears stdin.
* Precondition: True.
* Postcondition: True
* Errors: Not defined.
*/
void clean_stdin()
{
    while (getchar() != '\n');
}


char charToUpperCase(char character)
{
    if (character >= 97  && character <= 122)
    {
        character -= 32;
    }
    return character;
}

char * toUpperCase(char * string, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        string[i] = charToUpperCase(string[i]);
    }
    return string;

}

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
    printf("\n");
    Student student = *((Student *)(n));
    printf("Nom: %s DNI: %u-%c email: %s ", student.name, student.DNI, student.DNI_letter, student.email);
    if (student.sex) printf("sexe: Home");
    else printf("sexe: Dona");
}

int compareToStudentDNI(void *student1, void *student2)
{
    if (((Student *)(student1))->DNI > ((Student *)(student2))->DNI)
    {
        return -1;
    }
    else if (((Student *)(student1))->DNI < ((Student *)(student2))->DNI)
    {
        return 1;
    }
    return 0;
}

int compareToStudentName(void *student1, void *student2)
{
    return strncmp(toUpperCase(((Student *)(student1))->name, strlen(((Student *)(student1))->name)), toUpperCase(((Student *)(student2))->name, strlen(((Student *)(student2))->name)), strlen(((Student *)(student1))->name));
}

int compareToIntegers(void *int1, void *int2)
{
    if (*((int *)(int1)) > *((int *)(int2)))
    {
        return -1;
    }
    else if (*((int *)(int1)) < *((int *)(int2)))
    {
        return 1;
    }
    return 0;
}

int compareToDoubles(void *double1, void *double2)
{
    if (*((double *)(double1)) > *((double *)(double2)))
    {
        return -1;
    }
    else if (*((double *)(double1)) < *((double *)(double2)))
    {
        return 1;
    }
    return 0;
}

int compareToUnsignedIntegers(void *int1, void *int2)
{
    if (*((unsigned int *)(int1)) > *((unsigned int *)(int2)))
    {
        return -1;
    }
    else if (*((unsigned int *)(int1)) < *((unsigned int *)(int2)))
    {
        return 1;
    }
    return 0;
}


bool addStudent(DoubleLinkedList *list, char *name, char *email, char DNI_letter, unsigned int DNI, DoubleLinkedList marks, bool sex)
{
    Student *student = malloc(sizeof(Student));

    if (student == NULL)
    {
        printf("ERROR: No s'ha pogut afegir lalumne amb DNI %u perque no s'ha pogut reservar memoria. ", DNI);
        return false;
    }

    strcpy(student->name, name);
    strcpy(student->email, email);
    student->DNI = DNI;
    student->DNI_letter = DNI_letter;
    student->sex = sex;
    student->marks = marks;

    return sortedAdd(list, student, compareToStudentDNI);

}


bool isDNICorrect(unsigned int DNI, char letter)
{
    letter = charToUpperCase(letter);
    return DNI_letters[DNI % 23] == letter;
}

int main(int nargs, char* args[])
{
    /*
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
     */
    Manager manager;
    manager.list = create(sizeof(Student));
    Student temp_student;
    temp_student.marks = *create(sizeof(double));

    char endline;  // Temporary storage of endline character to validate user input

    // Guardar fitxer i sortir
    FILE *file_pointer;
    file_pointer = fopen(".student_manager.dat", "r");
    if (file_pointer == NULL)
    {
        printf("\nADVERTENCIA: No s'ha pogut obrir el fitxer");
    }
    else
    {
        int sex;
        char trash;
        while (fscanf(file_pointer, "%u%c%c%s%s%d", &temp_student.DNI, &trash, &temp_student.DNI_letter, temp_student.name, temp_student.email, &sex) != EOF)
        {
            double mark;
            fscanf(file_pointer, "%c", &endline);
            if (endline == '\n')
                break;
            while (fscanf(file_pointer, "%lf", &mark) == 1)
            {
                fscanf(file_pointer, "%c", &endline);
                if (endline == '\n')  // End of line
                    break;

                sortedAdd(&temp_student.marks, &mark, compareToDoubles);
            }
            addStudent(manager.list, temp_student.name, temp_student.email, temp_student.DNI_letter, temp_student.DNI, temp_student.marks, sex != 0);
        }
        fclose(file_pointer);

    }


    unsigned int option;  // Temporary storage of the option selected by user
    do {
        printf("\n\n");
        printf("****************************\n");
        printf("*** STUDENT MANAGER 1.0. ***\n");
        printf("****************************\n\n");
        printf("Escull quina operació vols fer escribint el nombre de la opció i prement Intro:\n");
        printf("1.- Afegir alumne\n");
        printf("2.- Buscar per DNI\n");
        printf("3.- Buscar per Nom\n");
        printf("4.- Veure últim alumne buscat\n");
        printf("5.- Eliminar últim alumne buscat\n");
        printf("6.- Veure tots els alumnes\n");
        printf("0.- Sortir\n");

        printf("Introdueix nombre d'opció: ");
        if (scanf("%u%c", &option, &endline) == 2 && endline == '\n')  // Checks that the user did not input trash
        {
            switch (option) {
                case 1:
                {
                    // check user input for name
                    printf("\n\nIntrodueix el nom de l'estudiant: ");
                    char name[100];
                    while (scanf("%s", name) != 1) {}

                    // check user input for email
                    printf("\n\nIntrodueix el email de l'estudiant: ");
                    char email[100];
                    while (scanf("%s", email) != 1) {}

                    // check user input for the DNI
                    bool correct_input_DNI = false;
                    unsigned int value_DNI;
                    while (!correct_input_DNI)
                    {
                        printf("\n\nIntrodueix el DNI de l'estudiant a afegir: ");
                        correct_input_DNI = scanf("%u%c", &value_DNI, &endline) == 2 && endline == '\n';  // Checks that the user did not input trash
                        if (!correct_input_DNI)
                        {
                            clean_stdin();
                            printf("\nERROR: No has introduït un DNI adequat. Torna-ho a intentar...");
                        }
                    }

                    // check user input for the DNI letter
                    bool correct_input_DNI_letter = false;
                    char value_letter;
                    while (!correct_input_DNI_letter)
                    {
                        printf("\n\nIntrodueix el la lletra del DNI l'estudiant a afegir: ");
                        correct_input_DNI_letter = scanf("%c%c", &value_letter, &endline) == 2 && endline == '\n';  // Checks that the user did not input trash
                        if (!correct_input_DNI)
                        {
                            clean_stdin();
                            printf("\nERROR: No has introduït un caracter adequat. Torna-ho a intentar...");
                        }
                    }

                    if (!isDNICorrect(value_DNI, value_letter))
                    {
                        printf("ADVERTENCIA: La lletra del DNI es incorrecta. Es corregira a la correcta\n");
                    }

                    // check user input for the sex
                    bool correct_input_sex = false;
                    unsigned int value_sex;
                    while (!correct_input_sex)
                    {
                        printf("\n\nIntrodueix el sexe de l'estudiant (1 per a noi, 0 per noia): ");
                        correct_input_sex = scanf("%u%c", &value_sex, &endline) == 2 && endline == '\n' && (value_sex == 1 || value_sex == 0);  // Checks that the user did not input trash
                        if (!correct_input_sex)
                        {
                            clean_stdin();
                            printf("\nERROR: No has introduït la dada adequadament. Torna-ho a intentar...");
                        }
                    }

                    // check user input for the marks
                    bool correct_input_marks = false;
                    double value_mark;
                    DoubleLinkedList *list_marks = create(sizeof(double));
                    while (true)
                    {
                        while (!correct_input_marks)
                        {
                            printf("\n\nIntrodueix una nota, prem intro i introdueix -1 per a acabar: ");
                            correct_input_marks = scanf("%lf%c", &value_mark, &endline) == 2 && endline == '\n';  // Checks that the user did not input trash
                            if (!correct_input_marks)
                            {
                                clean_stdin();
                                printf("\nERROR: No has introduït la dada adequadament. Torna-ho a intentar...");
                            }
                        }
                        if (-1 == value_mark)
                        {
                            break;
                        }
                        correct_input_marks = false;
                        sortedAdd(list_marks, &value_mark, compareToDoubles);
                    }

                    bool result = addStudent(manager.list, name, email, value_letter, value_DNI, *list_marks, value_sex);
                    if (!result)
                    {
                        printf("\n L'estudiant amb DNI %u no sha pogut afegir perque ja esta registrat", value_DNI);
                    }

                    break;
                }
                case 2:
                {
                    // check user input for the DNI
                    bool correct_input_DNI = false;
                    unsigned int value_DNI;
                    while (!correct_input_DNI)
                    {
                        printf("\n\nIntrodueix el DNI de l'estudiant a afegir: ");
                        correct_input_DNI = scanf("%u%c", &value_DNI, &endline) == 2 && endline == '\n';  // Checks that the user did not input trash
                        if (!correct_input_DNI)
                        {
                            clean_stdin();
                            printf("\nERROR: No has introduït un DNI adequat. Torna-ho a intentar...");
                        }
                    }
                    void ** found_DNI;
                    unsigned int num_values_DNI;
                    temp_student.DNI = value_DNI;
                    bool result_find_DNI = find(*(manager.list), compareToStudentDNI, &temp_student, &found_DNI, &num_values_DNI);

                    if (result_find_DNI)
                    {
                        printf("\nSha trobat a l'alumne %s amb el nom introduit. \n", ((Student *)(*found_DNI))->name);
                        manager.lastStudent = *((Student *)(*found_DNI));
                    }
                    else
                    {
                        printf("\nNo sha trobat a cap alumne amb el nom introduit");
                    }

                    break;
                }
                case 3:
                {
                    // check user input for name
                    printf("\n\nIntrodueix el nom de l'estudiant: ");
                    char name[100];
                    while (scanf("%s", name) != 1) {}


                    void ** found_name;
                    unsigned int num_values_name;
                    strcpy(temp_student.name, name);


                    bool result_find_name = find(*(manager.list), compareToStudentName, &temp_student, &found_name, &num_values_name);

                    if (result_find_name)
                    {
                        if (num_values_name == 1)
                        {
                            printf("\nSha trobat a l'alumne %s amb el DNI introduit. \n", ((Student *)(*found_name))->name);
                        }
                        else
                        {
                            printf("\nShan trobat %u alumnes. \n", num_values_name);
                        }
                        manager.lastStudent = *((Student *)(*found_name));
                    }
                    else
                    {
                        printf("\nNo sha trobat a cap alumne amb el nom introduit");
                    }

                    break;
                }
                case 4:
                {
                    printStudent(&(manager.lastStudent));
                    break;
                }
                case 5:
                {
                    delete(manager.list, compareToStudentDNI, &manager.lastStudent);
                    break;
                }
                case 6:
                {
                    bool correct_input_print = false;
                    unsigned int value_print;
                    while (!correct_input_print)
                    {
                        printf("\n\nIntrodueix 0 per veure la llista ascendentment i 1 o una altra cosa per veure la llista descendentment: ");
                        correct_input_print = scanf("%u%c", &value_print, &endline) == 2 && endline == '\n';  // Checks that the user did not input trash
                        if (!correct_input_print)
                        {
                            clean_stdin();
                            printf("\nERROR: No has introduït la dada adequadament. Torna-ho a intentar...");
                        }
                    }
                    toScreenBackwards(*(manager.list), printStudent, value_print != 0);

                    break;
                }
                case 0:
                {
                    // Guardar fitxer i sortir
                    FILE *file_pointer;
                    file_pointer = fopen(".student_manager.dat", "w+");
                    if (file_pointer == NULL)
                    {
                        printf("\nERROR: No s'ha pogut obrir el fitxer");
                        break;
                    }

                    // Fill the array with elements until MAX_ELEMENTS is reached or EOF is reached
                    Node * ptr = manager.list->head;
                    while (ptr != NULL)
                    {
                        fprintf(file_pointer, "%u %c %s %s %d", ((Student *)(ptr->data))->DNI, ((Student *)(ptr->data))->DNI_letter, ((Student *)(ptr->data))->name, ((Student *)(ptr->data))->email, ((Student *)(ptr->data))->sex);
                        Node * ptr2 = ((Student *)(ptr->data))->marks.head;
                        while (ptr2 != NULL)
                        {
                            fprintf(file_pointer, " %lf", *((double *)ptr2->data));
                            ptr2 = ptr2->next;
                        }
                        fprintf(file_pointer, "\n");
                        ptr = ptr->next;
                    }
                    fclose(file_pointer);
                    //fprintf(file_pointer, "\n");
                    exit(0);

                    break;
                }
                default:
                {
                    printf("\nERROR: Aquesta opció no existeix... \n");
                    break;
                }
            }
        }
        else
        {
            printf("\nERROR: No has introduït un nombre vàlid per a la selecció de la opció. Torna-ho a intentar...");
            clean_stdin();
        }

    } while (true);

    return 0;
}
