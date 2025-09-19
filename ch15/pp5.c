#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int main(void)
{
    char ch;
    short a, b;

    printf("Enter an RPN expression: ");
    while (scanf(" %c", &ch)) {
        switch (ch) {
            case '+':
                b = pop();
                a = pop();
                push(a + b);
                break;
            case '-':
                b = pop();
                a = pop();
                push(a - b);
                break;
            case '*':
                b = pop();
                a = pop();
                push(a * b);
                break;
            case '/':
                b = pop();
                a = pop();
                push((short)((float)a / b));
                break;
            case '=':
                a = pop();
                printf("Value of expression: %d\n", a);
                make_empty();
                printf("Enter an RPN expression: ");
                break;
            default:
                if (isdigit(ch)) {
                    push(ch - '0');
                } else {
                    exit(0);
                }
        }
    }

    return 0;
}
