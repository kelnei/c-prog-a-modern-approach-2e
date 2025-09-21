#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
    char *word;
    struct node *next;
};

struct node *line = NULL, *tail = NULL;
int lines = 0;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    struct node *p = line, *q;
    while (p != NULL) {
        q = p->next;
        free(p->word);
        free(p);
        p = q;
    }
    line = NULL;
    tail = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct node *p = malloc(sizeof(*p));
    if (p == NULL) {
        printf("out of memory\n");
        exit(EXIT_FAILURE);
    }

    p->next = NULL;
    p->word = malloc(strlen(word) + 1);
    if (p->word == NULL) {
        printf("out of memory\n");
        exit(EXIT_FAILURE);
    }

    if (num_words > 0) line_len++; // for spacing
    strcpy(p->word, word);
    line_len += strlen(word);
    num_words++;

    if (line == NULL) {
        line = p;
        tail = p;
    } else {
        tail->next = p;
        tail = tail->next;
    }
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i = 0, j, m;
    struct node *p;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (p = line; p != NULL; p = p->next) {
        if (i != 0) {
            m = lines % 2 == 1 && extra_spaces >= 1 ? 1 : 0;
            spaces_to_insert = extra_spaces / (num_words - 1);
            spaces_to_insert = m > spaces_to_insert ? m : spaces_to_insert;
            for (j = 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
        printf("%s", p->word);
        i++;
    }
    putchar('\n');
    lines++;
    clear_line();
}

void flush_line(void)
{
    int i = 0;
    struct node *p;
    for (p = line; p != NULL; p = p->next) {
        if (i != 0) putchar(' ');
        printf("%s", p->word);
        i++;
    }
    putchar('\n');
    clear_line();
}
