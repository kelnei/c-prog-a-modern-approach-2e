#include <stdio.h>
#include <tgmath.h>

#define PI 3.14159265358979323846

int main(void)
{
    int k, n;

    double complex root;

    printf("Enter positive integer n: ");
    if (!scanf("%d", &n) || n <= 0) {
        fprintf(stderr, "invalid n");
        return 1;
    }

    for (k = 0; k < n; k++) {
        root = exp((2 * PI * I * k) / n);
        if (cimag(root) == 0) {
            printf("When k = %d, the root is %g\n", k, creal(root));
        } else {
            printf("When k = %d, the root is %g %c %gi\n", k, creal(root), cimag(root) < 0 ? '-' : '+', fabs(cimag(root)));
        }
    }

    return 0;
}

