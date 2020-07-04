//
// Created by aleixmt on 4/7/20.
//

#include "commonlib.h"

void mem_set(unsigned int *start, unsigned int value, unsigned int count)
/* Escriu "count" valors "value" a partir de "start" */
{
    while (count > 0)
    {
        count--;
        start[count] = value;
    }
}


unsigned int strLength (char *string)
/* Retorna el número de caràcters de "string" */
{
    unsigned int length = 0;

    while (string[length] != 0) length++;

    return length;
}


unsigned char unsignedIntToString (unsigned int number, char string[11])
/* Converteix "number" a string,
   retorna el número de dígits */
{
    unsigned int quo, mod;
    unsigned char mida = 0, i;
    char digit;

    quo = number;
    do
    {
        div_mod (quo, 10, &quo, &mod);
        string[mida] = mod + '0';
        mida++;
    } while ( quo > 0);
    string[mida] = 0;	/* Sentinella de final de string */

    /* Invertir caràcters */
    for ( i = 0; i < mida/2; i++ ){
        digit = string[i];
        string[i] = string[ mida-i-1 ];
        string[ mida-i-1 ] = digit;
    }

    return mida;
}






// Genera una potencia de 10 amb tants 0 com el nombre rebut per argument
long long unsigned int powerTen(long long unsigned int num_zeros)
{
    long long unsigned int num = 1;
    for (long long unsigned int i = 0; i < num_zeros; i++)
    {
        num *= 10;
    }
    return num;
}

// Genera una potencia amb exponent natural
long long unsigned int power(long long unsigned int base, long long unsigned int exponent)
{
    long long unsigned int num = 1;
    for (long long unsigned int i = 0; i < exponent; i++)
    {
        num *= base;
    }
    return num;
}

/**
* Returns the factorial of a given natural number recursively.
* Precondition: parameter "value" is a natural number.
* Postcondition: return = value * acum; value = value - 1 where value is a natural number.
* Errors: Unsigned long long integer overflow. This happens when result is bigger than ULLONG_MAX 18.446.744.073.709.551.615
* (0xffffffffffffffff). Maximum calculable factorial is 20!. 21! cause overflow:
* 2,432,902,008,176,640,000 = 20! < ULLONG_MAX < 21! = 51,090,942,171,709,440,000
* Params:
* - value: Number to calculate factorial.
* - acum: Acumulator used for the recursive calls to acumulate the computing of the result.
*/
long long unsigned int private_factorial(unsigned int value, long long unsigned int acum)
{
    if (value == 1) return acum;
    else return private_factorial(value - 1, value * acum);
}


/**
* Returns the factorial of natural number "value" calling private_factorial, initializing inner parameters and
* returning direct cases. Uses long long integers since a factorial can be a very large number and overflow is likely,
* even if the value parameter is just an unsigned int. Factorial numbers bigger than 20! return -1 since they can not be
* computed.
* Precondition: parameter "value" is a natural or 0.
* Postcondition: return = value! only if "value" parameter is bigger than 20.
* Errors: Not defined. We control the call to private_factorial to discard possible errors.
* Params:
* - value: number to calculate factorial.
*/
long long unsigned int public_factorial(unsigned int value)
{
    if (value == 0) return 1;
    else if (value > 20) return -1;
    else return private_factorial(value, 1);
}



//Imprimeix el vector per pantalla
void printUnsignedIntArray(unsigned int v[], unsigned int int midaVector)
{
    int i;
    printf ("\n\nVector amb %u elements\n", midaVector);
    for (i = 0; i < midaVector; i++)
    {
        printf("%u, ", v[i]);
    }
}

double sumUnsignedIntArray(unsigned int array[], unsigned int num_elements)
{
    int sum = 0;
    for (int i = 0; i < num_elements; i++)
    {
        sum += array[i];
    }
    return sum;
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

void clean_stdin()
{
    while (getchar() != '\n');
}


void copy(char *origin, char *destination, size_t data_size)
{
    for (int i = 0; i < data_size; i++)
        *(char *)(destination + i) = *(char *)(origin + i);
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


char * replaceSpaces(char * string, unsigned int num_chars)
{
    for (unsigned int i = 0; i < num_chars; i++)
    {
        if (string[i] == 32)
            string[i] = 95;
    }
    return string;
}

char * replaceUnderscores(char * string, unsigned int num_chars)
{
    for (unsigned int i = 0; i < num_chars; i++)
    {
        if (string[i] == 95)
            string[i] = 32;
    }
    return string;
}