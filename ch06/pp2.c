#include <stdio.h>

int main(void) {
    int m, n, r;

    printf("Enter two integers: ");
    if (scanf("%d%d", &m, &n) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    if (n > m) {
        r = n;
        n = m;
        m = r;
    }

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}
