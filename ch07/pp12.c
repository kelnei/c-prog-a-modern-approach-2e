#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char ch, op = '\0';
    int i = 0, p = 1;
    float f, value = 0;
    bool decimal = false;

    printf("Enter an expression: ");

    while ((ch = getchar()) != '\n') {
        if (ch >= '0' && ch <= '9') {
            i *= 10;
            i += (ch - '0');
            if (decimal) p *= 10;
        } else if (ch == '.') {
            decimal = true;
        } else if (
            ch == '*' ||
            ch == '/' ||
            ch == '+' ||
            ch == '-'
        ) {
            f = (float)i / p;
            i = 0;
            p = 1;
            decimal = false;
            if (!op) {
                value = f;
                op = ch;
            } else {
                switch (op) {
                    case '*':
                        value *= f;
                        break;
                    case '/':
                        value /= f;
                        break;
                    case '+':
                        value += f;
                        break;
                    case '-':
                        value -= f;
                        break;
                }
                op = ch;
            }
        }
    }

    f = (float)i / p;

    if (!op) {
        value = f;
    } else {
        switch (op) {
            case '*':
                value *= f;
                break;
            case '/':
                value /= f;
                break;
            case '+':
                value += f;
                break;
            case '-':
                value -= f;
                break;
        }
    }

    printf("Value of expression: %g\n", value);

    return 0;
}
