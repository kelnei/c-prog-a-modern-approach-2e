#include <stdio.h>

int main(void) {
    float principal, interest_rate, monthly_payment;
    int i, payments;
    printf("Enter amount of loan: ");
    if (!scanf("%f", &principal)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("Enter interest rate: ");
    if (!scanf("%f", &interest_rate)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("Enter monthly payment: ");
    if (!scanf("%f", &monthly_payment)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("Enter number of payments: ");
    if (!scanf("%d", &payments)) {
        printf("Invalid input\n");
        return -1;
    }

    for (i = 1; i <= payments; i++) {
        principal = (principal * (1 + (interest_rate / 100.0f / 12.0f))) - monthly_payment;
        printf("Balance remaining after %d payment(s): $%.2f\n", i, principal);
    }

    return 0;
}
