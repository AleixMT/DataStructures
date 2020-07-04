//
// Created by aleixmt on 4/7/20.
//

#ifndef DATASTRUCTURES_COMMONLIB_H
#define DATASTRUCTURES_COMMONLIB_H

// String manipulation
char * replaceUnderscores(char * string, unsigned int num_chars);
char * replaceSpaces(char * string, unsigned int num_chars);
char * toUpperCase(char * string, unsigned int size);
char charToUpperCase(char character);
unsigned int strLength (char *string);
unsigned char unsignedIntToString (unsigned int number, char string[11]);

// Parametrizable functions
void printUnsignedInt(void *n);
void printFloat(void *f);
void printInt(void *n);
int compareToUnsignedIntegers(void *int1, void *int2);
int compareToDoubles(void *double1, void *double2);
int compareToIntegers(void *int1, void *int2);
void printUnsignedIntArray(unsigned int v[], unsigned int int midaVector);  //RF make functions parametrizable

// General data manipulation
void copy(char *origin, char *destination, size_t data_size);
void mem_set(unsigned int *start, unsigned int value, unsigned int count);

// I/O functions
void clean_stdin();

// Utilities
long long unsigned int power(long long unsigned int base, long long unsigned int exponent);
long long unsigned int powerTen(long long unsigned int num_zeros);
long long unsigned int public_factorial(unsigned int value);
double sumUnsignedIntArray(unsigned int array[], unsigned int num_elements);




#endif //DATASTRUCTURES_COMMONLIB_H
