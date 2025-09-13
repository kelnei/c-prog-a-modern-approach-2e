#include <stdio.h>

int main(void) {
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    // read the newline left by scanf
    getchar();

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ;
        }
    }

    return 0;
}
