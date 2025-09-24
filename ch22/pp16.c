/* Copies a file */

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 512

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    char buf[MAX_BUF_SIZE];
    int n;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <source> <dest>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    while ((n = fread(buf, sizeof(char), MAX_BUF_SIZE, source_fp)) > 0) {
        fwrite(buf, sizeof(char), n, dest_fp);
    }

    fclose(source_fp);
    fclose(dest_fp);

    return 0;
}
