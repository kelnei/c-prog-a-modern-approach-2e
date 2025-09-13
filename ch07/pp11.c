#include <stdio.h>
#include <ctype.h>

int main(void) {
    char initial, ch;

    printf("Enter a first and last name: ");

    // discard whitespace
    while ((ch = getchar()) == ' ')
        ;

    initial = ch;

    // skip rest of first name and space
    while ((ch = getchar()) != ' ')
        ;

    // discard whitespace
    while ((ch = getchar()) == ' ')
        ;

    // first letter of last name
    putchar(ch);

    // continue until another space or new-line
    while ((ch = getchar()) != '\n' && ch != ' ') {
        putchar(ch);
    }

    printf(", %c.\n", initial);

    return 0;
}
