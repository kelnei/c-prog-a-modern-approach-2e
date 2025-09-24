#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *ofp;
    char infile[FILENAME_MAX+1], outfile[FILENAME_MAX+1];
    int s, n;
    int ch;

    printf("Enter name of file to be encrypted: ");
    if (fgets(infile, FILENAME_MAX, stdin) == NULL) {
        fprintf(stderr, "invalid filename\n");
        exit(EXIT_FAILURE);
    }

    n = strlen(infile);
    if (infile[n - 1] == '\n') {
        infile[n - 1] = '\0';
        n--;
    }

    if ((ifp = fopen(infile, "rb")) == NULL) {
        fprintf(stderr, "unable to open %s for reading\n", infile);
        exit(EXIT_FAILURE);
    }

    strncpy(outfile, infile, FILENAME_MAX);
    strncat(outfile, ".enc", FILENAME_MAX - n);

    if ((ofp = fopen(outfile, "wb")) == NULL) {
        fprintf(stderr, "unable to open %s for reading\n", outfile);
        exit(EXIT_FAILURE);
    }

    printf("Enter shift amount (1-25): ");
    if (!scanf("%d", &s)) {
        fprintf(stderr, "invalid shift amount\n");
        exit(EXIT_FAILURE);
    }

    // clamp it
    if (s > 25) {
        s = 25;
    } else if (s < 1) {
        s = 1;
    }

    while ((ch = fgetc(ifp)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') + s) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') + s) % 26 + 'A';
        }
        fputc(ch, ofp);
    }

    return 0;
}
