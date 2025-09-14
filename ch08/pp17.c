#include <stdio.h>

int main(void) {
    int s[99][99] = {0};
    int n, r, c;
    long i;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter the size of magic square: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    if (n % 2 != 1 || n < 1 || n > 99) {
        printf("Invalid size\n");
        return 1;
    }

    r = 0;
    c = n / 2;
    for (i = 1; i <= n * n; i++) {
        // occupied? put it below last store number
        if (s[r][c]) {
            r += 2;
            c--;
            if (r > n - 1) r %= n;
            if (c < 0) c = n - 1;
        }
        s[r--][c++] = i;
        if (r < 0) r = n - 1;
        if (c > n - 1) c = 0;
    }

    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            printf("%5d", s[r][c]);
        }
        printf("\n");
    }

    return 0;
}
