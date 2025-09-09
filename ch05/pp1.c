#include <stdio.h>

int main(void) {
    int n, d;
    printf("Enter a number: ");
    if (!scanf("%4d", &n)) {
        printf("Invalid input\n");
        return 1;
    }
    if (n >= 0 && n < 10) {
        d = 1;
    } else if (n >= 10 && n < 100) {
        d = 2;
    } else if (n >= 100 && n < 1000) {
        d = 3;
    } else {
        d = 4;
    }

    printf("The number %d has %d digits\n", n, d);

    return 0;
}
