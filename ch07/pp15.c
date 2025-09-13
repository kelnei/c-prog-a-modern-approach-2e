#include <stdio.h>

/*
 * (a) short max n = 7
 * (b) int max n = 13
 * (c) long max n = 20
 * (d) long long max n = 20
 * (e) float max n = 34 (accurate to 13)
 * (f) double max n = 170 (accurate to 22) 
 * (g) long double max n = 1754 (accurate to 25) 
 */

int main(void) {
    int n, i;
    long double j = 1.0;

    printf("Enter a positive integer: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        j *= (long double)i;
    }

    printf("Factorial of %d: %.0Lf\n", n, j);
}
