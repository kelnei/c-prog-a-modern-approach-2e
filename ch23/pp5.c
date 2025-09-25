#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double p, r, t;

    printf("Enter amount: $ ");
    if (!scanf("%lf", &p)) {
        fprintf(stderr, "invalid amount\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter interest rate: %% ");
    if (!scanf("%lf", &r)) {
        fprintf(stderr, "invalid rate\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter years: ");
    if (!scanf("%lf", &t)) {
        fprintf(stderr, "invalid years\n");
        exit(EXIT_FAILURE);
    }

    printf("$%.2f at %g%% interest for %g years is: $%.2f\n",
           p, r, t, p * exp((r / 100) * t));

    return 0;
}
