#include <stdio.h>

int main(void) {
    int i;
    printf("Enter a number: ");
    if (!scanf("%d", &i)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("The reversal is: ");
    do {
        printf("%d", i % 10);
        i /= 10;
    } while (i > 0);
    printf("\n");

    return 0;
}
