#include <stdio.h>

int main(void) {
    float n, max = 0.0f;

    while (1) {
        printf("Enter a number: ");
        if (!scanf("%f", &n)) {
            printf("Invalid input\n");
            return 1;
        }

        if (n <= 0.0f) break;

        if (n > max) max = n;
    }

    printf("The largest number entered was: %g\n", max);

    return 0;
}
