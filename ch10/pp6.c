#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

short contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(short s)
{
    if (is_full()) {
        printf("Expression is too complex\n");
        exit(1);
    }
    contents[top++] = s;
}

short pop(void)
{
    if (is_empty()) {
        printf("Not enough operands in expression\n");
        exit(1);
    }
    return contents[--top];
}

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
