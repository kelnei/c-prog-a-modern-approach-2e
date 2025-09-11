#include <stdio.h>

int main(void) {
    int i = 1;
    float t, e = 1.0f, j = 1.0f, k;

    printf("Enter a term to compute to: ");
    if (!scanf("%f", &t)) {
        printf("Invalid input\n");
        return 1;
    }

    do {
        j *= i++;
        k = 1.0f / j;
        e += k;
    } while (k > t);

    printf("Approx value of the constant e: %f\n", e);

    return 0;
}
