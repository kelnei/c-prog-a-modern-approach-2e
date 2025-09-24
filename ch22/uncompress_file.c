#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char filename[FILENAME_MAX+1] = {0};
    FILE *ifp, *ofp;
    int n = 0, i, j, ch;
    char *p;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <filename.rle>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = strlen(argv[1]);
    p = argv[1];

    if (n < 4 ||
        *(p + n - 1) != 'e' ||
        *(p + n - 2) != 'l' ||
        *(p + n - 3) != 'r' ||
        *(p + n - 4) != '.')
    {
        fprintf(stderr, "%s does not have the extension .rle\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((ifp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "unable to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    strncpy(filename, argv[1], n - 4);

    if ((ofp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "unable to open %s for writing\n", filename);
        fclose(ifp);
        exit(EXIT_FAILURE);
    }

    i = 0;
    while ((ch = fgetc(ifp)) != EOF) {
        if (i % 2 == 0) {
            n = ch;
        } else {
            for (j = 0; j < n; j++) {
                fputc(ch, ofp);
            }
        }
        i++;
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
