#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a value for x: ");
    if (!scanf("%d", &x)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("The value of 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 "
           "where x = %d is: %d\n", x,
           3 * (x * x * x * x * x) +
           2 * (x * x  * x * x) -
           5 * (x * x * x) -
           (x * x) + 7 * x - 6);
    return 0;
}
