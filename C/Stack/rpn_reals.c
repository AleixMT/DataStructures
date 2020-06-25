//
// Created by Sergi Vives on 12/4/20.
//

#include "pila_reals.h"

// He borrat algunes de les funcions que feien operacions matematiques ja que he decidit fer servir
// la llibreria math.h per a invocar les operacions, ja que hi han moltes que no se com implementar-les
// Per exemple sinus, cosinus, tangent, logaritmes, exponencials amb decimals etc.

int factorial(int nombre)
{
    int num = 1;
    for (int i = 2; i <= nombre; i++)
    {
        num *= i;
    }
    return num;
}

// Reconstrueix un nombre a partir de la pila que el conté
int reconstruir_nombre(Pila pila)
{
    int num = 0;  // Acumulador on tindrem el nombre
    int pos_digit = 0;  // Indica la posicio del digit sent 0 per les unitats
    while (!EsBuida(pila))
    {
        // Obtenim el digit actual i el multipliquem per la potencia de 10 que correspon
        num += Cim(pila) * pow(10, pos_digit);
        Desapilar(&pila);  // Desapilem un element
        pos_digit++;  // Augmentem en 1 la posicio i potencia de 10 corresponent
    }
    return num;
}

double reconstrueix_nombre_decimal(Pila pila)
{
    double num = 0;  // Acumulador on hi tindrem el nombre
    double pos_digit = pila.num_elems;  // Indica l'exponent
    while (!EsBuida(pila))
    {
        // Obtenim el digit actual i el multipliquem per la potencia de 10 que correspon
        num += Cim(pila) * pow(10, -pos_digit);
        Desapilar(&pila);  // Desapilem un element
        pos_digit--;  // Augmentem en 1 la posicio i potencia de 10 corresponent
    }
    return num;
}

int main(int nargs, char* args[])
{
    Pila* pila = Crear(10);
    Pila* pila_auxiliar_enters = Crear(10);
    Pila* pila_auxiliar_decimals = Crear(10);

    FILE *fp;
    char ch;
    bool flag_lectura_nombre_enter = false;
    bool flag_lectura_nombre_decimals = false;  // utilitzat per a controlar l'estat quan llegim un decimal
    bool flag_negatiu = false;
    int flag_canvisigne = 0;
    double num1, num2, num3;  // Auxiliars
    double part_entera = 0, resultat;

    fp = fopen("input_reals.txt", "r");

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
                if (!flag_lectura_nombre_enter && !flag_lectura_nombre_decimals)  // Activem l'estat per a estar llegint un enter si no estavem llegint un nombre decimal ni enter
                {
                    flag_lectura_nombre_enter = true;  // Entrem a mode de lectura de nombre enter si no ho estavem
                    Apilar(pila_auxiliar_enters, ch - 48);  // Apilem caracter
                }
                else if (flag_lectura_nombre_decimals)  // Hem llegit un nombre pero estavem en mode decimal
                {
                    Apilar(pila_auxiliar_decimals, ch - 48);  // Apilem caracter
                }
                else if (flag_lectura_nombre_enter)  // Hem llegit un nombre pero estavem en mode enter
                {
                    Apilar(pila_auxiliar_enters, ch - 48);  // Apilem caracter
                }
            }
            else if (ch == '.')  // Fi de lectura d'un enter
            {
                // Al entrar en aquest if el flag de lectura de enter ha d'estar si o si aixecat
                flag_lectura_nombre_enter = false;  // Baixem el flag
                flag_lectura_nombre_decimals = true;  // pugem el flag de decimal perque esperem si o si un decimal

                part_entera = (double) reconstruir_nombre(*pila_auxiliar_enters);  // Guardem la part entera del nombre reconstruït

                pila_auxiliar_enters = Crear(10);  // Regenerem la pila de la part entera
            }
            else if (ch == ',')  // Assenyala final d'operador
            {
                if (flag_lectura_nombre_enter)  // Si estavem llegint un nombre que no te part decimal
                {
                    flag_lectura_nombre_enter = false;  // Baixem el flag
                    part_entera = reconstruir_nombre(*pila_auxiliar_enters);
                    if (flag_negatiu) part_entera *= -1;
                    Apilar(pila, part_entera);  // Apilem el numero reconstruit perque ja hem acabat de processar

                    flag_negatiu = false;  // baixem el flag
                    pila_auxiliar_enters = Crear(10);  // Regenerem la pila

                }
                else if (flag_lectura_nombre_decimals)  // Si estavem llegint un nombre decimal
                {
                    flag_lectura_nombre_decimals = false;  // Baixem el flag de llegir un decimal
                    resultat = reconstrueix_nombre_decimal(*pila_auxiliar_decimals) + part_entera;
                    if (flag_negatiu) resultat *= -1;
                    Apilar(pila, resultat);  // Apilem el nombre reconstruit

                    flag_negatiu = false;  // baixem el flag de negatiu
                    pila_auxiliar_decimals = Crear(10);  // Regenerem la pila de la part decimal

                }
                else if (!flag_lectura_nombre_enter && !flag_lectura_nombre_decimals && flag_negatiu)  // Es tracta d'una operacio de resta, no d'un negatiu posat a un nombre
                {
                    if (pila->num_elems < 2)
                    {
                        fprintf(stderr, "Error a la restaaa: Insuficients operands\n");
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
            else if (ch == 'e')  // e nombre
            {
                Apilar(pila, M_E);
            }
            else if (ch == 'm')  // pi nombre
            {
                Apilar(pila, M_PI);
            }
            else if (ch == 'u')  // sinUs
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error al sinus: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, sin(num1));
            }
            else if (ch == 'o')  // cOsinus
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error al cosinus: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, cos(num1));
            }
            else if (ch == 'n')  // taNgent
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error a la tangent: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, tan(num1));
            }
            else if (ch == 'U')  // arcsinUs
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error al arcsinus: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                if (num1 > 1 || num1 < -1)
                {
                    fprintf(stderr, "Error al arcsinus: S'ha intentat operar amb un valor fora de rang \n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }

                Apilar(pila, asin(num1));
            }
            else if (ch == 'O')  // arccOsinus
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error al arccosinus: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                if (num1 > 1 || num1 < -1)
                {
                    fprintf(stderr, "Error al arccossinus: S'ha intentat operar amb un valor fora de rang \n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }

                Apilar(pila, acos(num1));
            }
            else if (ch == 'N')  // arctaNgent
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error a la arctangent: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);

                if (num1 == 0)
                {
                    fprintf(stderr, "Error al arctangent: S'ha intentat operar amb un valor que es 0 \n");
                    exit(ERROR_OPERACIO_NO_PERMESA);  // Abortem el programa
                }
                Apilar(pila, atan(num1));
            }
            else if (ch == 'l')  // Logaritme neperia
            {
                if (EsBuida(*pila))
                {
                    fprintf(stderr, "Error al cosinus: Insuficients operands (pila buida)\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, log(num1));
            }
            else if (ch == 'L')  // Logaritme amb base escollida
            {
                if (pila->num_elems < 2)
                {
                    fprintf(stderr, "Error al logaritme de base escollida: Insuficients operands\n");
                    exit(ERROR_INSUFICIENTS_OPERANDS);  // Abortem el programa
                }
                num1 = Cim(*pila);  // Primer traiem la base
                Desapilar(pila);
                num2 = Cim(*pila);  // Despres el nombre del que volem fer el log
                Desapilar(pila);
                Apilar(pila, log(num2) / log(num1));
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
                Desapilar(pila);
                num2 = Cim(*pila);
                Desapilar(pila);
                Apilar(pila, pow(num2, num1));
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
                Apilar(pila,(double) ((int) num2 % (int) num1));
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
        if (flag_lectura_nombre_enter)  // Si estavem llegint un nombre que no te part decimal
        {
            flag_lectura_nombre_enter = false;  // Baixem el flag
            part_entera = reconstruir_nombre(*pila_auxiliar_enters);
            if (flag_negatiu) part_entera *= -1;
            Apilar(pila, part_entera);  // Apilem el numero reconstruit perque ja hem acabat de processar

            flag_negatiu = false;  // baixem el flag
            pila_auxiliar_enters = Crear(10);  // Regenerem la pila

        }
        else if (flag_lectura_nombre_decimals)  // Si estavem llegint un nombre decimal
        {
            flag_lectura_nombre_decimals = false;  // Baixem el flag de llegir un decimal
            resultat = reconstrueix_nombre_decimal(*pila_auxiliar_decimals) + part_entera;
            if (flag_negatiu) resultat *= -1;
            Apilar(pila, resultat);  // Apilem el nombre reconstruit

            pila_auxiliar_decimals = Crear(10);  // Regenerem la pila de la part decimal

        }
        else if (!flag_lectura_nombre_enter && !flag_lectura_nombre_decimals && flag_negatiu)  // Es tracta d'una operacio de resta, no d'un negatiu posat a un nombre
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

        if (pila->num_elems != 1)
        {
            fprintf(stderr, "Error al retorn, hi ha mes d'un operand a la pila\n");
            exit(ERROR_RESULTAT_INCONSISTENT);  // Abortem el programa
        }

        printf("Resultat final de la pila es: %f\n", Cim(*pila));
        Destruir(pila_auxiliar_decimals);
        Destruir(pila_auxiliar_enters);
        Destruir(pila);
        exit(EXIT);
    }
}

