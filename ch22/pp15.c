#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

char line[MAX_LINE_LEN+1];
int lines = 0;
int line_len = 0;
int num_words = 0;


void clear_line(void);
void add_word(const char *word);
int space_remaining(void);
void write_line(FILE *stream);
void flush_line(FILE *stream);
int read_word(char *word, int len, FILE *stream);

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;
    char word[MAX_WORD_LEN+1];
    int word_len;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <infile> <outfile>", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((ifp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "failed to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((ofp = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "failed to open %s for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    clear_line();
    for (;;) {
        word_len = read_word(word, MAX_WORD_LEN, ifp);
        if (word_len == 0) {
            flush_line(ofp);
            return 0;
        }

        if (word_len + 1 > space_remaining()) {
            write_line(ofp);
            clear_line();
        }
        add_word(word);
    }

    return 0;
}

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len+1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(FILE *stream)
{
    int extra_spaces, spaces_to_insert, i, j, m;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ')
            fputc(line[i], stream);
        else {
            m = lines % 2 == 1 && extra_spaces >= 1 ? 1 : 0;
            spaces_to_insert = extra_spaces / (num_words - 1);
            spaces_to_insert = m > spaces_to_insert ? m : spaces_to_insert;
            for (j = 1; j <= spaces_to_insert + 1; j++)
                fputc(' ', stream);
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    fputc('\n', stream);
    lines++;
}

void flush_line(FILE *stream)
{
    if (line_len > 0)
        fputs(line, stream);
}

static int read_char(FILE *stream)
{
    int ch = fgetc(stream);

    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

int read_word(char *word, int len, FILE *stream)
{
    int ch, pos = 0;

    while ((ch = read_char(stream)) == ' ')
        ;
    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        else
            word[pos-1] = '*';
        ch = read_char(stream);
    }
    word[pos]='\0';
    return pos;
}
