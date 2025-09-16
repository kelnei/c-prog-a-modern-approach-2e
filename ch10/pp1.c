#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void stack_overflow()
{
    printf("Stack overflow\n");
    exit(1);
}

void stack_underflow()
{
    printf("Parentheses/braces are not nested properly\n");
    exit(0);
}

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

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
        // never happens
        return '\0';
    }
    else
        return contents[--top];
}

int main(void)
{
    char ch, chb;
    bool unmatched = false;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        if (ch == '(' || ch == '{') {
            push(ch);
        }
        else if (ch == ')' || ch == '}') {
            chb = pop(); 

            if (ch == ')' && chb == '(') continue;
            if (ch == '}' && chb == '{') continue;

            unmatched = true;
            break;
        }
        // ignore other chars
    }

    if (is_empty() && !unmatched) {
        printf("Paratheses/braces are nested properly\n");
    } else {
        printf("Parentheses/braces are not nested properly\n");
    }

    return 0;
}
