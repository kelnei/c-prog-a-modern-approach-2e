#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double a, b, c, n, x1, x2;

    printf("Solves the equation ax²+bx+c=0 for x.\n");
    printf("Enter a: ");
    if (!scanf("%lf", &a)) {
        fprintf(stderr, "invalid input for a\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter b: ");
    if (!scanf("%lf", &b)) {
        fprintf(stderr, "invalid input for b\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter c: ");
    if (!scanf("%lf", &c)) {
        fprintf(stderr, "invalid input for c\n");
        exit(EXIT_FAILURE);
    }

    n = (b * b) - (4 * a * c);

    if (n < 0) {
        printf("The roots are complex.\n");
    } else {
        x1 = (-b + sqrt(n)) / (2 * a);
        x2 = (-b - sqrt(n)) / (2 * a);
        printf("The values of x are %g and %g\n", x1, x2);
    }

    return 0;
}
