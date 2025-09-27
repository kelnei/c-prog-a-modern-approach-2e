#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    double a, b, r, theta;
    printf("Converts cartesian coords of a complex `a + bi` to polar.\n");

    printf("Enter a: ");
    if (!scanf("%lf", &a)) {
        fprintf(stderr, "invalid a");
        return 1;
    }

    printf("Enter b: ");
    if (!scanf("%lf", &b)) {
        fprintf(stderr, "invalid b");
        return 1;
    }

    r = sqrt(a * a + b * b);
    theta = acos(a / r);

    printf("r: %g\n", r);
    printf("θ: %g\n", theta);

}
