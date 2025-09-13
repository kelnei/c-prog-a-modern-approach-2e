#include <stdio.h>

int main(void) {
    double n, sum = 0;

    printf("This program sums a series of doubles.\n");
    printf("Enter doubles (0 to terminate): ");

    if (!scanf("%lf", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    while (n != 0) {
        sum += n;
        if (!scanf("%lf", &n)) {
            printf("Invalid input\n");
            return 1;
        }
    }

    printf("The sum is: %f\n", sum);

    return 0;
}
