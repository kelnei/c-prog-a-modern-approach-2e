#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    bool word = false;
    int ch;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch) && !word) {
            word = true;
            putchar(toupper(ch));
            continue;
        } else if (word && !isalpha(ch)) { 
            // could use `word && isspace(ch)` if you want
            // to treat any sequence of chars not containing
            // a space as a word
            word = false;
        }
        putchar(ch);
    }

    return 0;
}


