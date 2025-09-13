#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y = 1.0, y2;

    printf("Enter a positive number: ");
    if (!scanf("%lf", &x) || x < 0) {
        printf("Invalid input\n");
        return 1;
    }

    y2 = (y + (x / y)) / 2.0;

    while (fabs(y - y2) > .00001) {
        y = y2;
        y2 = (y + (x / y)) / 2.0;
    }

    y = y2;

    printf("Square root: %g\n", y);

    return 0;
}
