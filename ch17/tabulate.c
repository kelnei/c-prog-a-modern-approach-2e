/* Tabulates values of trigonometric functions */

#include <math.h>
#include <stdio.h>

void tabulate(double (*f)(double), double first,
              double last, double incr);

int main(void)
{
    double final, increment, initial;

    printf("Enter initial value: ");
    if (!scanf("%lf", &initial)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter final value: ");
    if (!scanf("%lf", &final)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter increment: ");
    if (!scanf("%lf", &increment)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("\n      x        cos(x)"
           "\n   -------    -------\n");
    tabulate(cos, initial, final, increment);

    printf("\n      x        sin(x)"
           "\n   -------    -------\n");
    tabulate(sin, initial, final, increment);

    printf("\n      x        tan(x)"
           "\n   -------    -------\n");
    tabulate(tan, initial, final, increment);

    return 0;
}

void tabulate(double (*f)(double), double first,
              double last, double incr)
{
    double x;
    int i, num_intervals;

    num_intervals = ceil((last - first) / incr);
    for (i = 0; i <= num_intervals; i++) {
        x = first + i * incr;
        printf("%10.5f %10.5f\n", x, (*f)(x));
    }
}
