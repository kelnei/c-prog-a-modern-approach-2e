#include <stdio.h>
#include <ctype.h>

int main(void) {
    char initial, ch;
    char last[21] = {0};
    int i = 0;

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
    last[i++] = ch;

    // continue until another space or new-line
    while ((ch = getchar()) != '\n' && ch != ' ') {
        last[i++] = ch;
    }

    printf("You entered the name: %s, %c.\n", last, initial);

    return 0;
}
