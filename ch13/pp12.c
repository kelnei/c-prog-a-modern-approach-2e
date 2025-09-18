#include <stdio.h>
#include <string.h>

#define MAX_WORDS 30
#define MAX_WORD_LEN 20

int main(void)
{
    char words[MAX_WORDS+1][MAX_WORD_LEN+1] = {0};
    char ch = 0;
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    while (i < MAX_WORDS && scanf("%20s", &words[i][0])) {
        j = strlen(words[i]);
        ch = words[i][j - 1];
        if (ch == '.' || ch == '!' || ch == '?') {
            words[i][j - 1] = '\0';
            break;
        }
        i++;
    }

    printf("Reversal of sentence: ");
    while (i >= 0) {
        printf("%s", words[i]);
        if (i > 0) {
            putchar(' ');
        }
        i--;
    }
    printf("%c\n", ch);

    return 0;
}
