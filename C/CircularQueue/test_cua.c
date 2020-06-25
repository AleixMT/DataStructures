//
// Created by Sergi Vives on 12/4/20.
//

#include "cua.h"

int main(int nargs, char* args[])
{
    Cua* cua = NULL;

    Crear(&cua, 10);

    bool param;
    int num;

    EsBuida(*cua, &param);
    printf("La cua hauria destar buida. Ho esta? %i \n", param);
    for (int i = 0; i < 10; i++)
    {
        Encuar(cua, i);
        Cap(*cua, &num);
        printf("El cap es %i \n", num);
    }
    EsPlena(*cua, &param);
    printf("La cua hauria destar plena. Ho esta? %i \n", param);
    Cap(*cua, &num);
    printf("El cap es %i \n", num);
    for (int i = 0; i < 9; i++)
    {
        Desencuar(cua);
        Cap(*cua, &num);
        printf("El cap es %i \n", num);
    }
    Desencuar(cua);

    EsBuida(*cua, &param);
    printf("La pila hauria destar buida. Ho esta? %i \n", param);

    for (int i = 5; i > 0; i--)
    {
        Encuar(cua, i);
        Cap(*cua, &num);
        printf("El cap es %i \n", num);
    }
    EsPlena(*cua, &param);
    printf("La cua NO hauria destar plena. Ho esta? %i \n", param);

    for (int i = 0; i < 5; i++)
    {
        Desencuar(cua);
        Cap(*cua, &num);
        printf("El cap es %i \n", num);
    }
    EsBuida(*cua, &param);
    printf("La pila hauria destar buida. Ho esta? %i \n", param);
    Desencuar(cua);  // Aixo hauria de donar error

    printf("segona part del test, ara els punters estan al mig de l'array\n");  // Segona part del test
    for (int i = 0; i < 10; i++)
    {
        Encuar(cua, i);
        Cap(*cua, &num);
        printf("El cap es %i \n", num);
    }
    EsPlena(*cua, &param);
    printf("La cua hauria destar plena. Ho esta? %i \n", param);
    Cap(*cua, &num);
    printf("El cap es %i \n", num);
    for (int i = 0; i < 9; i++)
    {
        Cap(*cua, &num);
        Desencuar(cua);

        printf("El cap es %i \n", num);
    }
    Desencuar(cua);

    EsBuida(*cua, &param);
    printf("La pila hauria destar buida. Ho esta? %i \n", param);

    Destruir(cua);

    printf("Proves de la rutina de fusiio\n");
    Cua* cua1 = NULL;
    Cua* cua2 = NULL;
    Cua* cua_out = NULL;

    Crear(&cua1, 10);
    Crear(&cua2, 10);
    Crear(&cua_out, 10);

    for (int i = 0; i < 10; i++)
    {
        Encuar(cua1, (i + 3) * 2);
        Encuar(cua2, i * 2);
    }
    Fusionar(*cua1, *cua2, cua_out);

    param = false;
    int value;
    while (!param)
    {
        Cap(*cua_out, &value);
        printf("%i ", value);
        Desencuar(cua_out);
        EsBuida(*cua_out, &param);
    }
    printf("\n");

    printf("La cua de sortida de la rutina de fusio esta ordenada? %i\n", ComprovarOrdre(*cua_out) );

    printf("Proves de la rutina de inversio\n");
    // Tornem a inicialitzar
    value = 0;
    cua1 = NULL;
    cua2 = NULL;
    cua_out = NULL;
    Crear(&cua1, 10);
    Crear(&cua2, 10);
    for (int i = 1; i < 10; i++)
    {
        Encuar(cua1, i * 10);
    }
    Invertir(cua1, 3, 5, cua2);
    printf("Fi inversio\n");
    param = false;
    while (!param)
    {
        Cap(*cua2, &value);
        printf("%i ", value);
        Desencuar(cua2);
        EsBuida(*cua2, &param);
    }
    printf("\n");

    printf("\nProves de coses que se suposa que no funcionen");
    cua = NULL;
    Crear(&cua, 5);

    printf("\nEncuem del 1 al 5 per ordre");

    for (int i = 1; i <= 5; i++)
    {
        Encuar(cua, i);
    }

    Cap(*cua, &num);
    printf("\nEl cap es abans de desencuar %i ", num);
    Desencuar(cua);
    Cap(*cua, &num);
    printf("\nHem desencuat. El cap es %i ", num);
    Desencuar(cua);
    Cap(*cua, &num);
    printf("\nHem desencuat. El cap es %i ", num);

    for (int i = 6; i <= 10; i++)
    {
        Encuar(cua, i);
        Cap(*cua, &num);
        printf("\nHem encuat un %i. El cap es %i ", i, num);
        printf("\nFront %i", cua->front);
        printf("\nTail %i", cua->tail);

    }
    for (int i = 0; i < 9; i++)
    {
        Desencuar(cua);
        Cap(*cua, &num);
        printf("\nHem desencuat. El cap es %i ", num);
        printf("\nFront %i", cua->front);
        printf("\nTail %i", cua->tail);
    }

    printf("\nFi proves\n");






}
