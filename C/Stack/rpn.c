//
// Created by Sergi Vives on 12/4/20.
//

#include "pila.h"

// Genera una potencia de 10 amb tants 0 com el nombre rebut per argument
int potencia_deu(int num_zeros)
{
    int num = 1;
    for (int i = 0; i < num_zeros; i++)
    {
        num *= 10;
    }
    return num;
}

// Genera una potencia amb exponent natural
int potencia(int base, int exponent)
{
    int num = 1;
    for (int i = 0; i < exponent; i++)
    {
        num *= base;
    }
    return num;
}

int factorial(int nombre)
{
    int num = 1;
    for (int i = 2; i <= nombre; i++)
    {
        num *= i;
    }
    return num;
}

// Reconstrueix un nombre a partir de la pila que el conté i informació sobre el seu signe
int reconstruir_nombre(Pila pila, bool negatiu)
{
    int num = 0;  // Acumulador on tindrem el nombre
    int pos_digit = 0;  // Indica la posicio del digit sent 0 per les unitats
    while (!EsBuida(pila))
    {
        // Obtenim el digit actual i el multipliquem per la potencia de 10 que correspon
        num += Cim(pila) * potencia_deu(pos_digit);
        Desapilar(&pila);  // Desapilem un element
        pos_digit++;  // Augmentem en 1 la posicio i potencia de 10 corresponent
    }
    if (negatiu) num *= -1;
    return num;
}

int main(int nargs, char* args[])
{
    Pila* pila = Crear(10);
    Pila* pila_auxiliar = Crear(10);
    FILE *fp;
    char ch;
    bool flag_lectura_nombre = false;
    bool flag_negatiu = false;
    int flag_canvisigne = 0;
    int num1, num2, num3;  // Auxiliars

    fp = fopen("input3.txt", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error d\'apertura de fitxer\n");
        exit(ERROR_APERTURA_FITXER);  // Abortem el programa
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch >= '0' && ch <= '9')  // Es tracta d'un nombre
            {
                // Per a convertir en nombres en ASCII cal tenir en compte que hi ha 48 posicions de diferencia
                // Apilem els nombres
                if (!flag_lectura_nombre)
                {
                    flag_lectura_nombre = true;  // Entrem a mode de lectura de nombre si no ho estavem
                    Apilar(pila_auxiliar, ch - 48);  // Apilem caracter
                }
                else  // Si ja estavem en mode nombre apilem
                {
                    Apilar(pila_auxiliar, ch - 48);  // Apilem caracter
                }
            }
            else if (ch == ',')  // Fi d'operacio. Comprovem estat
            {
                if (flag_lectura_nombre)
                {
                    flag_lectura_nombre = false;  // Baixem el flag
                    Apilar(pila, reconstruir_nombre(*pila_auxiliar, flag_negatiu));  // Apilem el numero reconstruit

                    flag_negatiu = false;  // baixem el flag
                    pila_auxiliar = Crear(10);  // Regenerem la pila

                }
                else if (!flag_lectura_nombre && flag_negatiu)  // Es tracta d'una operacio de resta, no d'un negatiu
                {
                    if (pila->num_elems < 2)
                    {
                        fprintf(stderr, "Error a la resta: Insuficients operands\n");
                        exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                    }
                    num1 = Cim(*pila);  // El primer que treiem es el substrahend!
                    Desapilar(pila);
                    num2 = Cim(*pila);
                    Desapilar(pila);
                    Apilar(pila, num2 - num1);
                    flag_negatiu = false;  // baixem el flag
                }
            }
            else if (ch == '+')
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error a la suma: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, num1 + num2);
            }
            else if (ch == '*')
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error a la multiplicacio: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, num2 * num1);
            }
            else if (ch == '/')
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error a la divisio: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);  // Seguint la "lógica" de la resta el primer que treiem es el divisor
                if (num1 == 0)
                {
                    fprintf(stderr, "S\'ha dividit per 0\n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, num2 / num1);
            }
            else if (ch == '-')
            {
                flag_negatiu = true;  // No ho podem tractar aqui, hem d'esperar a saber si ens ve una coma o un nombre
            }
            else if (ch == '^')  // potenciacio
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error a la potenciació: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);  // Seguint la "lógica" de la resta el primer que treiem es l'exponent
                if (num1 < 0)
                {
                    fprintf(stderr, "S\'ha intentat fer potencia d'exponent negatiu\n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, potencia(num2, num1));
            }
            else if (ch == 'p')  // permutació
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error a la permutació: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, num1);
                Apilar(pila, num2);
            }
            else if (ch == 't')  // cicle de tres elements
            {
                if (pila->num_elems < 3)
                {
                    fprintf(stderr, "Error al cicle de tres elements: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num3 = Cim(*pila);
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                num1 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, num3);
                Apilar(pila, num1);
                Apilar(pila, num2);
            }
            else if (ch == 'r')  // repeticio
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error a la repeticio: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);  // El primer que treiem es el que indica el nombre de repeticions
                if (num1 < 0)
                {
                    fprintf(stderr, "Error a la repeticio: S'ha intentat repetir un elements un nombre negatiu de cops \n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                Desapilar(pila);
                num2 = Cim(*pila);  // El segon es el que repetirem
                Desapilar(pila);
                for (int i = 0; i < num1; i++)
                {
                    Apilar(pila, num2);
                }
            }
            else if (ch == '!')  // factorial
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error al factorial: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                if (num1 < 0)
                {
                    fprintf(stderr, "Error al factorial: s\'ha intentat calcular factorial d\'un negatiu\n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                Desapilar(pila);
                Apilar(pila, factorial(num1));
            }
            else if (ch == '%')  // modul
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error al modul: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);  // Seguint la lógica de la resta el primer que treiem es el divisor
                if (num1 == 0)
                {
                    fprintf(stderr, "Error al modul: s\'ha intentat dividir per 0\n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, num2 % num1);
            }
            else if (ch == 'b')  // nombre binomial
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error al nombre binomial: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);  // Seguint la lógica de la resta el primer que treiem es nombre inferior de la parella de binomial
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                if (num1 < 0 || num2 < 0)
                {
                    fprintf(stderr, "Error al calcul binomial: s\'ha intentat calcular binomials de nombre negatius\n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                if (num2 < num1)
                {
                    fprintf(stderr, "Error al calcul binomial: s\'ha intentat calcular binomials en que el terme inferior es mes gran que el superior\n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                Apilar(pila, factorial(num2) / (factorial(num1) * factorial(num2 - num1)));
            }
            else if (ch == 'c' || flag_canvisigne > 0)  // Comencem a tractar l'operand de canvi de signe
            {
                if (flag_canvisigne == 0)
                {
                    flag_canvisigne++; //Si trobem una c augmentem en 1 el flag
                }
                // si trobem una h després de la c
                else if (ch == 'h' && flag_canvisigne == 1)
                {
                    flag_canvisigne++;  // Augmentem el nivell de canvi de signe
                }
                else if (ch == 's' && flag_canvisigne == 2)
                {
                    // Si estem aqui vol dir que hem de llegit un operand de canvi de signe
                    if (EsBuida(*pila))
                    {
                        fprintf(stderr, "Error al canvi de signe: Insuficients operands (pila buida)\n");
                        exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                    }
                    flag_canvisigne = 0;  // Baixem el flag
                    num1 = Cim(*pila) * (-1);  // Apliquem el canvi de signe
                    Desapilar(pila);  // Treiem l'element processat
                    Apilar(pila, num1);  // Apilem l'element tractat
                }
                else  // Si no es cap d'aquests casos es tracta d'operand desconegut
                {
                    fprintf(stderr, "Operand desconegut\n");
                    exit(ERROR_OPERAND_DESCONEGUT);  // Abortem el programa
                }
            }
        }
        fclose(fp);  // Hem acabat de processar el fitxer

        // Cal recordar que l'últim nombre no acaba amb coma, i depenem d'aquesta per a saber el nombre
        // Aqui ja no cal perdre temps baixant flags perque es l'últim operand
        if (flag_lectura_nombre)  // Si hem acabat de llegir un nombre
        {
            flag_lectura_nombre = false;  // Baixem el flag
            Apilar(pila, reconstruir_nombre(*pila_auxiliar, flag_negatiu));  // Apilem el numero reconstruit
            flag_negatiu = false;  // baixem el flag
        }
        else if (!flag_lectura_nombre && flag_negatiu)  // Es tracta d'una operacio de resta, no d'un negatiu
        {
            if (pila->num_elems < 2)
            {
                fprintf(stderr, "Error a la resta: Insuficients operands\n");
                exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
            }
            num1 = Cim(*pila);  // El primer que treiem es el substrahend!
            Desapilar(pila);
            num2 = Cim(*pila);
            Desapilar(pila);
            Apilar(pila, num2 - num1);
        }
        if (pila->num_elems != 1)
        {
            fprintf(stderr, "Error al retorn, hi ha mes d'un operand a la pila\n");
            exit(ERROR_RESULTAT_INCONSISTENT);  // Abortem el programa
        }

        printf("Resultat final de la pila es: %d\n", Cim(*pila));
        Destruir(pila_auxiliar);
        Destruir(pila);
        exit(EXIT);
    }
}

