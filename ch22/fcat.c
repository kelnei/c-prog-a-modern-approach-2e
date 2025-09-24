#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, ch;

    if (argc < 2) {
        printf("usage: %s <filename> [<filename>...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "%s can't be opened\n", argv[i]);
        } else {
            while ((ch = fgetc(fp)) != EOF) {
                putchar(ch);
            }
            fclose(fp);
        }
    }

    return 0;
}
