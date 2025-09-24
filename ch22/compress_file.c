#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char filename[FILENAME_MAX+1] = {0};
    FILE *ifp, *ofp;
    int n = 0, ch, pch = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((ifp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "unable to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    strncpy(filename, argv[1], FILENAME_MAX);
    strncat(filename, ".rle", FILENAME_MAX - strlen(argv[1]));

    if ((ofp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "unable to open %s for writing\n", filename);
        fclose(ifp);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(ifp)) != EOF) {
        if ((ch != pch) || (ch == pch && n == 255)) {
            if (n > 0) {
                fputc(n, ofp);
                fputc(pch, ofp);
            }
            n = 1;
            pch = ch;
        }
        else {
            n++;
        }
    }

    if (n > 0) {
        fputc(n, ofp);
        fputc(pch, ofp);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
