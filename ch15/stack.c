#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
