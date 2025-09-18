#include <stdio.h>
#include <ctype.h>

#define N 255

double compute_average_word_length(const char *sentence);

int main(void) {
    char sentence[N+1] = {0};
    char ch;
    int n = 0;

    printf("Enter a sentence: ");

    while (n < N && (ch = getchar()) != '\n')
        sentence[n++] = ch;

    printf("Average word length: %.1f\n", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    const char *p = sentence;
    int chars = 0, spaces = 0;

    while (*p) {
        if (*p == ' ') {
            spaces++;
        } else {
            chars++;
        }
        p++;
    }
    spaces++;

    return (double)chars / spaces;
}
