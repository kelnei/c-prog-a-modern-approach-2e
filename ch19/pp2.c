#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stackADT.h"

int main(void)
{
    char ch;
    short a, b;
    Stack s = create();

    printf("Enter an RPN expression: ");
    while (scanf(" %c", &ch)) {
        switch (ch) {
            case '+':
                b = pop(s);
                a = pop(s);
                push(s, a + b);
                break;
            case '-':
                b = pop(s);
                a = pop(s);
                push(s, a - b);
                break;
            case '*':
                b = pop(s);
                a = pop(s);
                push(s, a * b);
                break;
            case '/':
                b = pop(s);
                a = pop(s);
                push(s, (short)((float)a / b));
                break;
            case '=':
                a = pop(s);
                printf("Value of expression: %d\n", a);
                make_empty(s);
                printf("Enter an RPN expression: ");
                break;
            default:
                if (isdigit(ch)) {
                    push(s, ch - '0');
                } else {
                    exit(0);
                }
        }
    }

    destroy(s);

    return 0;
}
