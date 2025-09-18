#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 80

bool is_palindrome(const char *message);

int main(void)
{
    char a[N] = {0}, ch, *p = a, *q = a + N;

    printf("Enter a message: ");
    while (p < q && (ch = getchar()) != '\n')
        if (isalpha(ch))
            *p++ = tolower(ch);

    if (is_palindrome(a)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *p = message, *q = message + strlen(message) - 1;

    while (p < q && *q == *p && ++p && --q)
        ;

    return p >= q;
}
