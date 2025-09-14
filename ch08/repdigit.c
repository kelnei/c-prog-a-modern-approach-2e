/* Checks numbers fo repeated digits */

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    bool digit_seen[10] = { false };
    int digit;
    long n;

    printf("Enter a number: ");
    if (!scanf("%ld", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            break;
        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0)
        printf("Repeated digit\n");
    else
        printf("No repeated digit\n");

    return 0;
}
