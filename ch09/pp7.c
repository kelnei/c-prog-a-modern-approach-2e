#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int x, n;

    printf("Enter a value for x: ");
    if (!scanf("%d", &x)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter a value for n: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("%d^%d is: %d\n", x, n, power(x, n));

    return 0;
}

int power(int x, int n)
{
    if (n == 0) return 1;

    if (n % 2 == 0) {
        x = power(x, n / 2);
        return x * x;
    } else {
        return x * power(x, n - 1);
    }
}
