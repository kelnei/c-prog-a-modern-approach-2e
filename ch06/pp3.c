#include <stdio.h>

int main(void) {
    int i, j, m, n, r; 

    printf("Enter a fraction: ");
    if (scanf("%d /%d", &i, &j) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    if (i == 0) {
        printf("In lowest terms: 0\n");
        return 0;
    } else if (j == 0) {
        printf("In lowest terms: undefined\n");
        return 0;
    }

    if (i > j) {
        m = i;
        n = j;
    } else {
        m = j;
        n = i;
    }

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    i /= m;
    j /= m;

    printf("In lowest terms: %d/%d\n", i, j);

    return 0;
}
