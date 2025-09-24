#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned char buf[N], out[N];
    int offset = 0, i, n;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "unable to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes               Characters\n");
    printf("------  ------------------------------  ----------\n");
    while ((n = fread(buf, sizeof(char), N, fp)) > 0) {
        for (i = 0; i < n; i++)
            out[i] = isprint(buf[i]) ? buf[i] : '.';

        printf("%6d  ", offset);

        for (i = 0; i < n; i++) {
            printf("%.2X ", buf[i]);
        }

        // fill rest of byte segment
        for (i = n; i < N; i++) {
            printf("   ");
        }

        printf("  "); // gap between bytes and characters

        for (i = 0; i < n; i++) {
            printf("%c", out[i]);
        }

        // fill rest of line
        for (i = n; i < N; i++) {
            printf(" ");
        }

        printf("\n");
        offset += 10;
    }

    return 0;
}
