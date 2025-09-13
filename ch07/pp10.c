#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int n = 0;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        if (ch == 'a' ||
            ch == 'e' ||
            ch == 'i' ||
            ch == 'o' ||
            ch == 'u'
        ) {
            n++;
        }
    }

    printf("Your sentence contains %d vowels.\n", n);

    return 0;
}
