/* Checks numbers fo repeated digits */

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    int digit_seen[10] = {0};
    int digit;
    long n;
    bool repeated;

    printf("Enter a number: ");
    if (!scanf("%ld", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        if (digit_seen[digit] > 1)
            repeated = true;
        n /= 10;
    }

    if (repeated) {
        printf("Repeated digit(s):");
        for (digit = 0; digit < 10; digit++) {
            if (digit_seen[digit] > 1) {
                printf(" %d", digit);
            }
        }
        printf("\n");
    } else {
        printf("No repeated digit\n");
    }

    return 0;
}
