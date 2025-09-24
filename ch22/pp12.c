#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int item, m, d, y;
    float price;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "failed to open %s for reading\n", argv[1]);
    }

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    while (fscanf(fp, "%d,%f,%d/%d/%d", &item, &price, &m, &d, &y) == 5) {
        printf("%-d\t\t$%7.2f\t%d/%d/%.4d\n", item, price, m, d, y);
    }

    fclose(fp);

    return 0;
}
