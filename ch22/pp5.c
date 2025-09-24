/* Performs XOR encryption */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;
    int ich, och;

    if (argc != 3) {
        printf("usage: %s <infile> <outfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((ifp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((ofp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[2]);
        fclose(ifp);
        exit(EXIT_FAILURE);
    }

    while ((ich = fgetc(ifp)) != EOF) {
        och = ich ^ KEY;
        fputc(och, ofp);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
