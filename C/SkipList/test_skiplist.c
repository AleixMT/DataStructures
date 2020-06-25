//
// Created by Sergi Vives on 15/4/20.
//

#include "skiplist.h"

int main(int nargs, char* args[])
{
    srand(time(NULL));

    Skip_list* llista;
    Crear(&llista);

    unsigned int parametre_enter;
    Longitud(*llista, &parametre_enter);
    printf("Longitud de la llista es (ha de ser 0): %i\n", parametre_enter);

    Inserir(llista, 344);
    Inserir(llista, 2);
    Inserir(llista, 144);
    Inserir(llista, 42);
    Inserir(llista, 5);
    Inserir(llista, 24);
    Inserir(llista, 2);
    Inserir(llista, 444);
    Inserir(llista, 54);
    Inserir(llista, 144);

    toMatrix(*llista);

    bool param;
    Buscar(*llista, 3, &param);
    if (param) printf("\nTrobat");
    else printf("\nNo trobat");
    Buscar(*llista, 2, &param);
    if (param) printf("\nTrobat");
    else printf("\nNo trobat");
    Buscar(*llista, 5, &param);
    if (param) printf("\nTrobat");
    else printf("\nNo trobat");
    Buscar(*llista, 144, &param);
    if (param) printf("\nTrobat");
    else printf("\nNo trobat");
    Buscar(*llista, 444, &param);
    if (param) printf("\nTrobat");
    else printf("\nNo trobat");

    Esborrar(llista, 2);
    Esborrar(llista, 2);
    Esborrar(llista, 444);

    toMatrix(*llista);





    Destruir(llista);

    printf("\n");
}