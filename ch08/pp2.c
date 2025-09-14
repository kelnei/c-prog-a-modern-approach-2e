/* Checks numbers fo repeated digits */

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    int digit_seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    if (!scanf("%ld", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Digit:\t\t");
    for (digit = 0; digit < 10; digit++) {
        printf("%3d", digit);
    }
    printf("\n");

    printf("Occurrences:\t");
    for (digit = 0; digit < 10; digit++) {
        printf("%3d", digit_seen[digit]);
    }
    printf("\n");

    return 0;
}
