#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
    int ch, chb;
    bool unmatched = false;
    Stack s = create();

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == '(' || ch == '{') {
            push(s, ch);
        }
        else if (ch == ')' || ch == '}') {
            if (is_empty(s))
                break;

            chb = pop(s); 

            if (ch == ')' && chb == '(') continue;
            if (ch == '}' && chb == '{') continue;

            unmatched = true;
            break;
        }
        // ignore other chars
    }

    if (is_empty(s) && !unmatched) {
        printf("Paratheses/braces are nested properly\n");
    } else {
        printf("Parentheses/braces are not nested properly\n");
    }

    destroy(s);

    return 0;
}
