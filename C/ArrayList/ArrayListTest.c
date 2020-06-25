//
// Created by Sergi Vives on 21/5/2020.
//
#include "ArrayList.h"

const unsigned int sizes[] = {10, 50, 100, 1000, 2000, 5000, 10000};
const unsigned int number_sizes = 7, number_samples = 10, number_tests = 3, number_parameters = 3;

double sum(unsigned int array[], unsigned int num_elements)
{
    int sum = 0;
    for (int i = 0; i < num_elements; i++)
    {
        sum += array[i];
    }
    return sum;
}

void calculateMetrix(unsigned int array[number_sizes][number_samples], double result[number_sizes][number_parameters])
{
    for (int i = 0; i < number_sizes; i++)
    {
        result[i][0] = sizes[i];
    }
    for (int i = 0; i < number_sizes; i++)
    {
        result[i][1] = sum(array[i], number_samples) / (double) number_samples;
    }
    for (int i = 0; i < number_sizes; i++)
    {
        result[i][2] = 0;
        for (int j = 0; j < number_samples; j++)
        {
            result[i][2] += (array[i][j] - result[i][1]) * (array[i][j] - result[i][1]);
        }
        result[i][2] = sqrt(result[i][2] / (double) number_samples);
    }
}

void printResults(double results[number_sizes][number_parameters])
{
    printf("\nMida\tMitjana\tDesviació\n");
    for (int i = 0; i < number_sizes; i++)
    {
        for (int j = 0; j < number_parameters; j++)
        {
            printf("%f\t", results[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    // Populate
    printf("Proves populate\n");
    ArrayList *arrayList;
	create(&arrayList);
    populate(arrayList, 100);
    //printf("%s", toString(*arrayList));
    destroy(arrayList);

    // Bubble Sort
    printf("Proves bubblesort\n");
    ArrayList *arrayListBubble;
    create(&arrayListBubble);
    populate(arrayListBubble, 100);
    sortBubble(arrayListBubble);
    //printf("%s", toString(*arrayListBubble));
    destroy(arrayListBubble);

    // Binary search
    int counter;
    printf("Proves cerca dicotómica\n");
    create(&arrayList);
    populate(arrayList, 1000);
    int random;
    int pos = searchBinary(*arrayList, get(*arrayList, random = rand() % 1000), &counter);
    if (pos != -1)
    {
        printf("superada");
    }
    sortBubble(arrayList);
    searchBinary(*arrayList, get(*arrayList, rand() % arrayList->num_elements), &counter);
    destroy(arrayList);

    // Results
    printf("Resultats pràctica: (pot tardar uns quants segons)\n");
    unsigned int results_present_element[number_sizes][number_samples];
    unsigned int results_random_element[number_sizes][number_samples];
    unsigned int results_not_present_element[number_sizes][number_samples];
    double parameters_present_element[number_sizes][number_parameters];
    double parameters_random_element[number_sizes][number_parameters];
    double parameters_not_present_element[number_sizes][number_parameters];

    for (int i = 0; i < number_sizes; i++)
    {
        for (int num_testing = 0; num_testing < number_tests; num_testing++)
        {
            for (int j = 0; j < number_samples; j++)
            {
                create(&arrayList);
                populate(arrayList, sizes[i]);
                sortBubble(arrayList);
                int counter;
                switch (num_testing)
                {
                    case 0:
                    {
                        searchBinary(*arrayList, get(*arrayList, rand() % arrayList->num_elements), &counter);
                        results_present_element[i][j] = counter;
                        break;
                    }
                    case 1:
                    {
                        searchBinary(*arrayList, (rand() % (sizes[i] * 2)), &counter);
                        results_random_element[i][j] = counter;
                        break;
                    }
                    case 2:
                    {
                        unsigned int random_not_present;
                        while (searchBinary(*arrayList, random_not_present = (rand() % (sizes[i] * 2)), &counter) != -1) {}

                        results_not_present_element[i][j] = counter;
                        break;
                    }
                    default:
                    {
                        exit(ERROR_BAD_PARAMETERS);
                        break;
                    }
                }
                destroy(arrayList);
            }
        }
    }
    printf("wat\n");
    calculateMetrix(results_present_element, parameters_present_element);
    calculateMetrix(results_random_element, parameters_random_element);
    calculateMetrix(results_not_present_element, parameters_not_present_element);

    printf("\n\nElement present:\n");
    printResults(parameters_present_element);
    printf("\n\nElement aleatori:\n");
    printResults(parameters_random_element);
    printf("\n\nElement no present:\n");
    printResults(parameters_not_present_element);

}