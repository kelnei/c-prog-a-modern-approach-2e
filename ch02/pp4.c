#include <stdio.h>

int main(void) {
    float amount;
    printf("Enter an amount: ");
    if (!scanf("%f", &amount)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("With tax added: $%.2f\n", amount * 1.05f);
    return 0;
}
