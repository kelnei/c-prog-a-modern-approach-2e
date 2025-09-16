#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void) {
    int i, j; 

    printf("Enter a fraction: ");
    if (scanf("%d /%d", &i, &j) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    if (i == 0) {
        printf("In lowest terms: 0\n");
        return 0;
    } else if (j == 0) {
        printf("In lowest terms: undefined\n");
        return 0;
    }

    reduce(i, j, &i, &j);

    printf("In lowest terms: %d/%d\n", i, j);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int r, m, n;

    if (numerator > denominator) {
        m = numerator;
        n = denominator;
    } else {
        n = numerator;
        m = denominator;
    }

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}
