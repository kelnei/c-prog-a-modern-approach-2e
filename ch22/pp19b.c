#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;
    int ch;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <infile> <outfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((ifp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "failed to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((ofp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "failed to open %s for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(ifp)) != EOF) {
        if (ch == '\n') {
            fputc('\r', ofp);
        }
        fputc(ch, ofp);
    }

    return 0;
}
