#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    bool word = false;
    int n = 0, ch;

    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) {
            if (word) {
                word = false;
                n++;
            }
        }
        else {
            word = true;
        }
    }

    fclose(fp);

    printf("%d\n", n);

    return 0;
}
