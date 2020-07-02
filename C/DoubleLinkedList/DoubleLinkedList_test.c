//
// Created by Sergi Vives on 15/4/20.
//

#include "DoubleLinkedList.h"
#include "../includes/random.h"

int main(int nargs, char* args[])
{
    // coses del random
    const long LARGEST = 1000000;
    long r, seed1, seed2;
    bool randomStep;

    /* Establiment de les llavors del generador */
    phrtsd("inicialitzem aleatoriament amb cadena de caracters", &seed1, &seed2);
    setall(seed1, seed2);

    Llista_encadenada* llista = NULL;
    bool param;
    int num, retorn;

    Crear(&llista);

    // Tot aquest bloc ha de petar o dir que esta buida la llista
    printf("\n\nPROVES ERRORS\n");
    Es_Final(*llista, &param);
    Actual(*llista, &num);
    Retrocedir(llista);
    Avancar(llista);
    Principi(llista);
    Final(llista);

    // Prova d'insercio al cim
    printf("\n\nPROVES INSERCIO PRINCIPI\n");
    for (int i = 0; i < 10; i++)
    {
        Inserir(llista, i);
    }
    Recorrer(*llista);
    Destruir(llista);


    // prova d'insercio per llocs random
    printf("\n\nPROVES INSERCIO SALTEJADA RANDOM\n");
    Crear(&llista);
    for (int i = 0; i < 10; i++)
    {
        Actual(*llista, &num);  // El primer cop ha de tornar error
        printf("Afegim %i amb PDI apunta a %i\n", i , num);

        Inserir(llista, i);  // Afegim un element

        r = ignuin(1, LARGEST);
        randomStep = (r % 2) == 0;
        if (randomStep)  // Avancem de forma random
        {
            printf("Avancem\n");
            Avancar(llista);
        }
    }
    Recorrer(*llista);
    Destruir(llista);

    // prova d'insercio al final
    printf("\n\nPROVES INSERCIO AL FINAL\n");
    Crear(&llista);
    for (int i = 0; i < 10; i++)
    {
        Inserir(llista, i);  // Afegim un element
        Avancar(llista);
    }
    Recorrer(*llista);
    Destruir(llista);

    // prova d'insercio saltejada pero sense ser aleatori
    printf("\n\nPROVES INSERCIO SALTEJADA FIXA\n");
    Crear(&llista);
    for (int i = 0; i < 10; i++)
    {
        Inserir(llista, i * 2);  // Afegim un element
        Avancar(llista);
    }
    printf("Taula del 2\n");
    Recorrer(*llista);
    Principi(llista);  // Situem la cosa al principi
    for (int i = 0; i < 10; i++)
    {
        Inserir(llista, i * 2 + 1);
        Avancar(llista);
        Avancar(llista);
    }
    printf("seq ordenada fins al 20\n");
    Recorrer(*llista);
    Destruir(llista);

    // prova d'insercio saltejada pero sense ser aleatori
    printf("\n\nPROVES INSERCIO SALTEJADA DES DEL FINAL\n");
    Crear(&llista);
    for (int i = 0; i < 10; i++)
    {
        Inserir(llista, i * 2);  // Afegim un element
        Avancar(llista);
    }
    printf("Taula del 2\n");
    Recorrer(*llista);
    Final(llista);  // Situem la cosa al final
    Es_Final(*llista, &param);
    printf("La ED confirma que estem al final? %i\n", param);
    for (int i = 9; i >= 0; i--)
    {
        Inserir(llista, i * 2 + 1);
        Retrocedir(llista);
    }
    Es_Final(*llista, &param);
    printf("La ED confirma que NO estem al final? %i\n", param);
    printf("seq ordenada fins al 20\n");
    Recorrer(*llista);
    Destruir(llista);

    // prova de destrucció
    printf("\n\nPROVES ESBORRAR L\n");
    Crear(&llista);
    for (int i = 0; i < 10; i++)
    {
        Inserir(llista, i);  // Afegim un element
        Avancar(llista);
    }
    printf("Seq fins al 10\n");
    Recorrer(*llista);
    Final(llista);  // Situem la cosa al final
    Es_Final(*llista, &param);
    printf("La ED confirma que estem al final? %i\n", param);
    for (int i = 0; i < 10; i++)
    {
        Esborrar(llista);
        Recorrer(*llista);
        Actual(*llista, &num);
        printf("PDI apunta a: %i\n", num);
    }
    Es_Final(*llista, &param);
    printf("La ED confirma que NO estem al final? %i\n", param);
    Recorrer(*llista);
    // Tornem a inserir coses sense crear ni destruir. S'ha de mantenir consistent
    for (int i = 0; i < 10; i++)
    {
        Inserir(llista, i);  // Afegim un element al principi
    }
    for (int i = 0; i < 5; i++)
    {
        Avancar(llista);  // Avancem 5 cops per posarnos al mig
    }
    Recorrer(*llista);
    Es_Final(*llista, &param);
    printf("La ED confirma que NO estem al final? %i\n", param);
    // I ara comencem a borrar
    for (int i = 0; i < 10; i++)
    {
        Esborrar(llista);
        Recorrer(*llista);
        Actual(*llista, &num);
        printf("PDI apunta a: %i\n", num);
    }
    Recorrer(*llista);

    // proves de cerca
    printf("\n\nPROVES DE CERCA\n");
    for (int i = 0; i < 100; i++)
    {
        Inserir(llista, i);  // Afegim un element
        Avancar(llista);
    }
    printf("Seq fins al 100\n");
    Recorrer(*llista);

    num = 56;
    Buscar(*llista, num, &param);
    printf("Hem trobat el %i (hauria de ser si): %i\n", num, param);
    Cost_Buscar(*llista, num, &retorn);
    printf("Cost de trobar el %i (hauria de ser %i + 1): %i\n", num, num, retorn);

    num = 99;
    Buscar(*llista, num, &param);
    printf("Hem trobat el %i (hauria de ser si): %i\n", num, param);
    Cost_Buscar(*llista, num, &retorn);
    printf("Cost de trobar el %i (hauria de ser %i + 1): %i\n", num, num, retorn);

    num = 0;
    Buscar(*llista, num, &param);
    printf("Hem trobat el %i (hauria de ser si): %i\n", num, param);
    Cost_Buscar(*llista, num, &retorn);
    printf("Cost de trobar el %i (hauria de ser %i + 1): %i\n", num, num, retorn);

    num = -1;
    Buscar(*llista, num, &param);
    printf("Hem trobat el %i (hauria de ser no): %i\n", num, param);
    Cost_Buscar(*llista, num, &retorn);
    printf("Cost de trobar el %i (hauria de ser igual a num elems, que es 100): %i\n", num, retorn);

    num = 101;
    Buscar(*llista, num, &param);
    printf("Hem trobat el %i (hauria de ser no): %i\n", num, param);
    Cost_Buscar(*llista, num, &retorn);
    printf("Cost de trobar el %i (hauria de ser igual a num elems, que es 100): %i\n", num, retorn);

    num = 1015467;
    Buscar(*llista, num, &param);
    printf("Hem trobat el %i (hauria de ser no): %i\n", num, param);
    Cost_Buscar(*llista, num, &retorn);
    printf("Cost de trobar el %i (hauria de ser igual a num elems, que es 100): %i\n", num, retorn);

    printf("\n\nTEST DE COST\n");

    // Programa final de cost de test
    printf("MIDA, COSTMITJA, DESVEEST\n");
    int* cost_cerques_individuals = malloc(sizeof(int) * 1000);
    for (int i = 1000; i <= 50000; i += 1000)
    {
        Crear(&llista);
        for (int j = 0; j < i; j++)
        {
            Inserir(llista, ignuin(1, i * 2));
        }
        for (int j = 0; j < 1000; j++)
        {
            Cost_Buscar(*llista, ignuin(1, i * 2), &retorn);
            cost_cerques_individuals[j] = retorn;
        }
        int sum = 0;
        for (int j = 0; j < 1000; j++)
        {
            sum += cost_cerques_individuals[j];
        }
        double mitjana = (double)sum / (double)1000;
        double desvest = 0;
        sum = 0;
        for (int j = 0; j < 1000; j++)
        {
            int desviacio = cost_cerques_individuals[j] - mitjana;
            if (desviacio < 0) desviacio = desviacio * (-1);  // Valor absolut
            sum += desviacio;
        }
        desvest = (double) sum / (double) 1000;

        printf("%i, %f, %f\n", i, mitjana, desvest);

        Destruir(llista);  // perque sino petarem la mem


    }






}
