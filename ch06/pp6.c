#include <stdio.h>

int main(void) {
    int n, i;

    printf("Enter a number: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 2; i * i <= n; i++) {
        if (i * i % 2 == 0) {
            printf("%d\n", i * i);
        }
    }

    return 0;
}
