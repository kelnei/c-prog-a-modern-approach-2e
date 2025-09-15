#include <stdio.h>

float taxes_due(float income);

int main(void) {
    float income;

    printf("Enter your taxable income: ");
    if (!scanf("%f", &income)) {
        printf("Invalid input\n");
        return 1;
    }


    printf("Taxes Due: $%.2f\n", taxes_due(income));

    return 0;
}

float taxes_due(float income) {
    if (income <= 750.0f) {
        return income * 0.01;
    } else if (income <= 2250.0f) {
        return 7.50f + (income - 750.0) * 0.02;
    } else if (income <= 3750.0f) {
        return 37.50f + (income - 2250.0) * 0.03;
    } else if (income <= 5250.0f) {
        return 82.50f + (income - 3750.0) * 0.04;
    } else if (income <= 7000) {
        return 142.50f + (income - 5250.0) * 0.05;
    } else {
        return 230.00f + (income - 7000.0) * 0.06;
    }
}
