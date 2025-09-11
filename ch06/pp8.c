#include <stdio.h>

int main(void) {
    int d, n, i;

    printf("Enter number of days in month: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    if (!scanf("%d", &d)) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 1; i < d; i++) {
        printf("   ");
    }
    for (i = 1; i <= n; i++) {
        printf("%2d ", i);
        if ((i + d - 1) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
