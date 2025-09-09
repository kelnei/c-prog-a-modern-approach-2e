#include <stdio.h>

int main(void) {
    float income, taxes;

    printf("Enter your taxable income: ");
    if (!scanf("%f", &income)) {
        printf("Invalid input\n");
        return 1;
    }

    if (income <= 750.0f) {
        taxes = income * 0.01;
    } else if (income <= 2250.0f) {
        taxes = 7.50f + (income - 750.0) * 0.02;
    } else if (income <= 3750.0f) {
        taxes = 37.50f + (income - 2250.0) * 0.03;
    } else if (income <= 5250.0f) {
        taxes = 82.50f + (income - 3750.0) * 0.04;
    } else if (income <= 7000) {
        taxes = 142.50f + (income - 5250.0) * 0.05;
    } else {
        taxes = 230.00f + (income - 7000.0) * 0.06;
    }

    printf("Taxes Due: $%.2f\n", taxes);

    return 0;
}
