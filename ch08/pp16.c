#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch = 0;
    int i = 0;
    int a[26] = {0};

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        if (isalpha(ch)) {
            a[ch - 'a']++;
        }
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        if (isalpha(ch)) {
            a[ch - 'a']--;
        }
    }

    for (i = 0; i < 26; i++) {
        if (a[i]) {
            printf("The words are not anagrams.\n");
            return 0;
        }
    }
    printf("The words are anagrams.\n");

    return 0;
}
