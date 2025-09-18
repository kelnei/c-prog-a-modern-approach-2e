#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define N 20

bool are_anagrams(const char *word1, const char *word2);

int main(void) {
    char word1[N+1] = {0}, word2[N+1] = {0};

    printf("Enter first word: ");
    if (!scanf("%20s", word1)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter second word: ");
    if (!scanf("%20s", word2)) {
        printf("Invalid input\n");
        return 1;
    }

    if (are_anagrams(word1, word2)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int a[26] = {0}, i;
    const char *p = word1, *q = word2;

    while (*p) {
        if (isalpha(*p))
            a[*p - 'a']++;
        p++;
    }

    while (*q) {
        if (isalpha(*q))
            a[*q - 'a']--;
        q++;
    }

    for (i = 0; i < 26; i++)
        if (a[i])
            return false;

    return true;
}

