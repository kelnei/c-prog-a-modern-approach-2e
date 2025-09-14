/* Reverses a series of numbers using variable-length arrays */

#include <stdio.h>

int main(void) {

    int i, n;

    printf("How many numbers do you want to reverse? ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    int a[n];

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        if (!scanf("%d", &a[i])) {
            printf("Invalid input\n");
            return 1;
        }
    }

    printf("In reverse order:");
    for (i = n - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    printf("\n");


    return 0;
}
