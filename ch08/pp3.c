/* Checks numbers fo repeated digits */

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    bool digit_seen[10] = { false };
    int digit;
    long n, i;

    printf("Enter numbers (0 to terminate): ");

    if (!scanf("%ld", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    while (n != 0) {
        i = n;

        while (i > 0) {
            digit = i % 10;
            if (digit_seen[digit])
                break;
            digit_seen[digit] = true;
            i /= 10;
        }

        if (i > 0) {
            printf("%ld has repeated digits\n", n);
        } else {
            printf("%ld has no repeated digits\n", n);
        }

        for (i = 0; i < 10; i++) {
            digit_seen[i] = false;
        }

        if (!scanf("%ld", &n)) {
            printf("Invalid input\n");
            return 1;
        }
    }

    return 0;
}
