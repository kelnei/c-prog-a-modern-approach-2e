#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50   
#define MAX_WORD_LEN 20

int read_line(char str[], int n);
int compare_str(const void *p1, const void *p2);

int main(void)
{
    char *words[MAX_WORDS];
    char word[MAX_WORD_LEN+1] = {0};
    int n = 0;

    for (;;) {
        if (n == MAX_WORDS) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter word: ");
        read_line(word, MAX_WORD_LEN);
        if (strlen(word) == 0)
            break;

        words[n] = malloc(strlen(word) + 1);
        if (words[n] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(words[n], word);
        n++;
    }

    qsort(words, n, sizeof(char *), compare_str);

    printf("\nIn sorted order: ");
    for (int i = 0; i < n; i++) {
        printf("%s", words[i]);
        if (i < n - 1) {
            putchar(' ');
        }
    }
    putchar('\n');

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int compare_str(const void *p1, const void *p2)
{
    return strcmp(*(const char **)p1, *(const char **)p2);
}
