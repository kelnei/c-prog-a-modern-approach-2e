#include <stdio.h>

int main(void) {
    int n, i;
    float e = 1.0f, j = 1.0f;

    printf("Enter a number: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        j *= i;
        e += 1.0f / j;
    }

    printf("Approx value of the constant e after %d iterations: %f\n", n, e);

    return 0;
}
