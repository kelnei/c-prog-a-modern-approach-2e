#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    double a, b, r, theta;
    printf("Converts polar coords r and θ of a complex to cartesian.\n");

    printf("Enter r: ");
    if (!scanf("%lf", &r)) {
        fprintf(stderr, "invalid r");
        return 1;
    }

    printf("Enter θ: ");
    if (!scanf("%lf", &theta)) {
        fprintf(stderr, "invalid theta");
        return 1;
    }

    a = r * cos(theta);
    b = r * sin(theta);

    printf("%g %c %gi\n", a, b < 0 ? '-' : '+', fabs(b));

}
