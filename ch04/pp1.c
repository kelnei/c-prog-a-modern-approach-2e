#include <stdio.h>

int main(void) {
    int i;
    printf("Enter a two-digit number: ");
    if (!scanf("%2d", &i)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("The reversal is: %d\n", (i % 10) * 10 + (i / 10));

    return 0;
}
