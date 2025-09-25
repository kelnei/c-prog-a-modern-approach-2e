#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int pch, ch, n = 0;

    pch = 0;
    while ((ch = getchar()) != EOF) {
        if (isspace(ch) && (pch == '.' || pch == '?' || pch == '!'))
            n++;
        pch = ch;
    }

    printf("%d\n", n);

    return 0;
}
