#include <stdio.h>

int main(void) {
    char ch;
    char a[16] = {0};
    int i = 0;

    printf("Enter a phone number: ");
    while (i < 15 && (ch = getchar()) != '\n') {
        a[i++] = ch;
    }
    a[i++] = ch;

    printf("In numeric form: ");
    i = 0;
    while ((ch = a[i++])) {
        if (ch >= 'A' && ch <= 'Z') {
            if (ch <= 'C') {
                putchar('2');
            } else if (ch <= 'F') {
                putchar('3');
            } else if (ch <= 'I') {
                putchar('4');
            } else if (ch <= 'L') {
                putchar('5');
            } else if (ch <= 'O') {
                putchar('6');
            } else if (ch <= 'S') {
                putchar('7');
            } else if (ch <= 'V') {
                putchar('8');
            } else {
                putchar('9');
            }
        } else {
            putchar(ch);
        }
    }

    return 0;
}
