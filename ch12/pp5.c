#include <stdio.h>

#define N 81

int main(void) {

    char ch;
    char a[N] = {0}, *p = a, *q = a + N;

    printf("Enter a sentence: ");
    while (p < q && ((ch = getchar()) != '\n') && ch != '.' && ch != '!' && ch != '?') {
        *p++ = ch;
    }

    printf("Reversal of sentence: ");
    while (p >= a) {
        if (p == a || *p == ' ') {
            // start of word
            q = p + (*p == ' ');
            // print the word
            while (*q) {
                putchar(*q++);
            }
            *p = '\0';
            if (p != a) {
                putchar(' ');
            }
        }
        p--;
    }

    printf("%c\n", ch);

    return 0;
}
