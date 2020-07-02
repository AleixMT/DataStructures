#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED

typedef struct Alumne{
    char nom[50];
    char dni[50];
    char correu[50];
    char nota[50];
    char data[50];
    char sexe[50];
}Alumne;

typedef struct Nodo{
    Alumne alumne;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista{
    Nodo* cabeza;
    int longitud;
}Lista;



#endif // REGISTROS_H_INCLUDED
