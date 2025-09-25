#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    bool enable = false;
    int ch;

    while ((ch = getchar()) != EOF) {
        // skip start of line whitespace or entire line if all space
        if (!enable && isspace(ch))
            continue;
        // reset at end of line
        if (enable && ch == '\n') {
            enable = false;
            putchar(ch);
            continue;
        } else if (!enable) {
            enable = true;
        }
        putchar(ch);
    }

    return 0;
}


