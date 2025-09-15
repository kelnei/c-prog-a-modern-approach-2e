#include <stdio.h>

int f(int x);

int main(void)
{
    int x;

    printf("Enter a value for x: ");
    if (!scanf("%d", &x)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("The value of 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 "
           "where x = %d is: %d\n", x, f(x));
    return 0;
}

int f(int x)
{
    return ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
}
