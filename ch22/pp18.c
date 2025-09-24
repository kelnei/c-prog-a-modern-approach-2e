#include <stdio.h>
#include <stdlib.h>

#define N 10000

static int numbers[N+1];
static int n = 0;

int icmp(const void *p1, const void *p2) {
    return *(int *)p1 - *(int *)p2;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    int i;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "failed to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%d", &i) == 1) {
        numbers[n++] = i;
    }

    if (n == 0) {
        printf("no numbers in file\n");
        return 0;
    }

    qsort(numbers, n, sizeof(int), icmp); 

    printf("min: %d   median: %d   max: %d\n",
           numbers[0],
           n % 2 == 0
            ? (numbers[n / 2 - 1] + numbers[n / 2]) / 2
            : numbers[n / 2],
           numbers[n - 1]);

    return 0;
}
