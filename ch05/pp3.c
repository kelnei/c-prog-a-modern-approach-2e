#include <stdio.h>

int main(void) {
    float commission, shares, price_per_share, value;

    printf("Enter the number of shares: ");
    if (!scanf("%f", &shares)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the price per share: $");
    if (!scanf("%f", &price_per_share)) {
        printf("Invalid input\n");
        return 1;
    }

    value = shares * price_per_share;

    if (value < 2500.00f) {
        commission = 30.00f + .017f * value;
    } else if (value < 6250.00f) {
        commission = 56.00f + .0066f * value;
    } else if (value < 20000.00f) {
        commission = 76.00f + .0034f * value;
    } else if (value < 50000.00f) {
        commission = 100.00f + .0022f * value;
    } else if (value < 500000.00f) {
        commission = 155.00f + .0011f * value;
    } else {
        commission = 255.00f + .0009f * value;
    }

    if (commission < 39.00f) {
        commission = 30.00f;
    }

    printf("Commission: $%.2f\n", commission);
    printf("Rival Commission: $%.2f\n", 33.00f + shares * (shares < 2000.0f ? 0.03 : 0.02));

    return 0;
}
