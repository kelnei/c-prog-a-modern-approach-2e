#include <stdio.h>
#include <string.h>

#define WORD_MAX_LEN 20

int main(void)
{
    char smallest_word[WORD_MAX_LEN+1] = {0}, largest_word[WORD_MAX_LEN+1] = {0}, word[WORD_MAX_LEN+1] = {0};

    printf("Enter word: ");
    if (!scanf("%20s", word)) {
        printf("Invalid input\n");
        return 1;
    }

    strcpy(smallest_word, word);
    strcpy(largest_word, word);

    while (strlen(word) != 4) {
        printf("Enter word: ");
        if (!scanf("%20s", word)) {
            printf("Invalid input\n");
            return 1;
        }

        if (strcmp(word, smallest_word) < 0) {
            strcpy(smallest_word, word);
        } else if (strcmp(word, largest_word) > 0) {
            strcpy(largest_word, word);
        }
    }
    printf("\n");
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
