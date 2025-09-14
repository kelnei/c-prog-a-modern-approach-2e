#include <stdio.h>

int main(void) {

    char ch;
    char a[81] = {0};
    int i = 0, j;

    printf("Enter a sentence: ");
    while (i < 80 && ((ch = getchar()) != '\n') && ch != '.' && ch != '!' && ch != '?') {
        a[i++] = ch;
    }

    printf("Reversal of sentence: ");
    while (i >= 0) {
        if (i == 0 || a[i] == ' ') {
            // start of word
            j = i + (a[i] == ' ');
            // print the word
            while (a[j]) {
                putchar(a[j++]);
            }
            a[i] = '\0';
            if (i != 0) {
                putchar(' ');
            }
        }
        i--;
    }

    printf("%c\n", ch);

    return 0;
}
