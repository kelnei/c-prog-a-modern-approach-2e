/* Prints a table of compound interest */

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.0

int main(void) {

    int i, low_rate, num_years, year;
    double value[5];

    printf("Enter interest rate: ");
    if (!scanf("%d", &low_rate)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter number of years: ");
    if (!scanf("%d", &num_years)) {
        printf("Invalid input\n");
        return 1;
    }
    
    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {
            value[i] += (low_rate + i) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}


