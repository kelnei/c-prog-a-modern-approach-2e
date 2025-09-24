#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;

    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            putchar(toupper(ch));
        } else {
            putchar(ch);
        }
    }

    fclose(fp);

    return 0;
}
