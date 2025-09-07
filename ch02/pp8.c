#include <stdio.h>

int main(void) {
    float principal, interest_rate, monthly_payment;
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
    principal = (principal * (1 + (interest_rate / 100.0f / 12.0f))) - monthly_payment;
    printf("Balance remaining after first payment: $%.2f\n", principal);
    principal = (principal * (1 + (interest_rate / 100.0f / 12.0f))) - monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", principal);
    principal = (principal * (1 + (interest_rate / 100.0f / 12.0f))) - monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", principal);
    return 0;
}
