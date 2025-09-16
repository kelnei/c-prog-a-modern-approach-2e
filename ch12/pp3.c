#include <stdio.h>

#define N 80

int main(void)
{
    char a[N] = {0}, ch, *p = a, *q = a + N;

    printf("Enter a message: ");
    while (p < q && (ch = getchar()) != '\n')
        *p++ = ch;

    printf("Reversal is: ");
    while (p > a)
        printf("%c", *--p);
    printf("\n");

    return 0;
}
