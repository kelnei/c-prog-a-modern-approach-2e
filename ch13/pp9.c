#include <stdio.h>
#include <ctype.h>

#define N 255

int compute_vowel_count(const char *sentence);

int main(void) {
    char ch;
    char sentence[N+1] = {0};
    int n = 0;

    printf("Enter a sentence: ");
    while (n < N && (ch = getchar()) != '\n') {
        sentence[n++] = ch;
    }

    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    const char *p = sentence;
    char ch;
    int n = 0;

    while ((ch = *p++)) {
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

    return n;
}
