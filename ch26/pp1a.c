#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, r, n = 0;

    srand((unsigned)time(NULL));

    for (i = 1; i <= 1000; i++) {
        r = rand();
        if (r % 2 == 0) {
            n++;
        }
        printf("%.2hx ", (r & 0xff));
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    printf("\neven: %d, odd: %d\n", n, 1000 - n);

    return 0;
}
