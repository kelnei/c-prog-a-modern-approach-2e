#include <stdio.h>

int main(void) {
    int i, n;
    short s;
    long l;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        s = (short)i;
        l = (long)i;
        printf("%12d %12d %12hd %12ld\n", i, i * i, s * s, l * l);
    }

    return 0;
}
