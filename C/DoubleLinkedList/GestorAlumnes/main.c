#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <string.h>
#include "registros.h"
#include <stdbool.h>

int main()
{
    Nodo *Lista;
    Nodo *ult;
    int option;


    do{

        menu();
        scanf("%d", &option);
        switch (option){

            case 1:
                 //   AgregarAlumno();

            break;
             case 2:
                // BuscarDni();
            break;
             case 3:
               //  BuscarNom();
            break;
             case 4:

            break;
             case 5:
               //  EliminarUltimo();
            break;

         }

    }while(option != 0);

    printf("Sortir del programa");
    return 0;
}

