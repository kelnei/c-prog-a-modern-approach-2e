#include <complex.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, discriminant;

    printf("For the equation ax^2 + bx + c = 0,\n");
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

    printf("Enter c: "); 
    if (!scanf("%lf", &c)) {
        fprintf(stderr, "invalid c");
        return 1;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        double complex discriminant_sqrt = csqrt(discriminant);
        double complex root1 = (-b + discriminant_sqrt) / (2 * a);
        double complex root2 = (-b - discriminant_sqrt) / (2 * a);

        printf("root 1 = %g %c %gi\n", creal(root1), cimag(root1) < 0 ? '-' : '+', fabs(cimag(root1)));
        printf("root 2 = %g %c %gi\n", creal(root2), cimag(root2) < 0 ? '-' : '+', fabs(cimag(root2)));
    } else {
        double discriminant_sqrt = sqrt(discriminant);
        double root1 = (-b + discriminant_sqrt) / (2 * a);
        double root2 = (-b - discriminant_sqrt) / (2 * a);
        printf("root 1 = %g\n", root1);
        printf("root 2 = %g\n", root2);
    }

    return 0;
}
