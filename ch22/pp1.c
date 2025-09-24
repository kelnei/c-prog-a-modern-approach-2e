/* Checks whether a file can be opened for reading */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    bool failed = false;
    int i;

    if (argc < 2) {
        printf("usage: %s <filename> [<filename>...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
            failed = true;
        } else {
            printf("%s can be opened\n", argv[i]);
            fclose(fp);
        }
    }

    if (failed) 
        exit(EXIT_FAILURE);

    return 0;
}
