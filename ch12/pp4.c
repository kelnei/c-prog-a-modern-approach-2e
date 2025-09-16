#include <stdio.h>
#include <ctype.h>

#define N 80

int main(void)
{
    char a[N] = {0}, ch, *p = a, *q = a + N;

    printf("Enter a message: ");
    while (p < q && (ch = getchar()) != '\n')
        if (isalpha(ch))
            *p++ = tolower(ch);

    q = a;
    p--;
    while (q < p && *q == *p && ++q && --p);

    if (q >= p) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}
