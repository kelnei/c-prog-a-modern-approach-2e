#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10

int main(int argc, char *argv[])
{
    FILE *fp;
    char phone[N + 1] = {0};
    int n, ch;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "failed to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    n = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (!isdigit(ch) && ch != '\n') continue;

        if (ch == '\n' && n > 0) {
            fprintf(stderr, "phone must be 10 digits, skipping...\n");
            n = 0;
            continue;
        }

        if (isdigit(ch)) {
            phone[n++] = ch;
        }

        if (n == N) {
            printf("(%.3s) %.3s-%.4s\n", phone, phone + 3, phone + 6);
            n = 0;
        }
    }
    fclose(fp);

    if (n == N) {
        printf("(%.3s) %.3s-%.4s\n", phone, phone + 3, phone + 6);
        n = 0;
    } else if (n > 0) {
        fprintf(stderr, "phone must be 10 digits, skipping...\n");
        n = 0;
    }

    return 0;
}
