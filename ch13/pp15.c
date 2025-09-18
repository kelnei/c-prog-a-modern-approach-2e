#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 255
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

int evaluate_RPN_expression(const char *expression);

int main(void)
{
    char expression[N+1] = {0};
    char ch;
    int n = 0;

    for (;;) {
        printf("Enter an RPN expression: ");
        while (n < N && (ch = getchar()) != '\n') {
            if (isspace(ch) ||
                isdigit(ch) ||
                ch == '+' ||
                ch == '-' ||
                ch == '*' ||
                ch == '/' ||
                ch == '=') {
                expression[n++] = ch;
            } else {
                exit(0);
            }
        }

        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));

        // reset
        memset(expression, 0, N);
        n = 0;
    }


    return 0;
}

int evaluate_RPN_expression(const char *expression)
{
    const char *p = expression;
    short a, b;

    make_empty();

    while (*p) {
        switch (*p) {
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
                return a;
                break;
            default:
                if (isdigit(*p)) {
                    push(*p - '0');
                } else if (!isspace(*p)) {
                    exit(0);
                }
        }
        p++;
    }

    return 0;
}
