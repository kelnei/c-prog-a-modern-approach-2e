#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int chars = 0, spaces = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            spaces++;
        } else {
            chars++;
        }
    }
    spaces++;

    printf("Average word length: %.1f\n", (float)chars / spaces);

    return 0;
}
