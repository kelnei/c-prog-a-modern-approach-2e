#include <stdio.h>
#include <string.h>

#define N 80

void reverse(char *message);

int main(void)
{
    char a[N] = {0}, ch, *p = a;

    printf("Enter a message: ");
    while (p < a + N && (ch = getchar()) != '\n')
        *p++ = ch;

    reverse(a);

    printf("Reversal is: %s\n", a);

    return 0;
}

void reverse(char *message)
{
    char ch, *p = message, *q = message + strlen(message) - 1;

    while (p < q) {
        ch = *p;
        *p++ = *q;
        *q-- = ch;
    }
}
