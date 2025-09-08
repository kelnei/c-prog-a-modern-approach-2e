#include <stdio.h>

int main(void) {
    int i;
    printf("Enter a three-digit number: ");
    if (!scanf("%3d", &i)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("The reversal is: %d\n", (i % 10) * 100 + ((i / 10) % 10) * 10 + (i / 100));

    return 0;
}
