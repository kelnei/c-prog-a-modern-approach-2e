#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        if (iscntrl(ch) && ch != '\n') {
            putchar('?');
        } else {
            putchar(ch);
        }
    }

    return 0;
}
