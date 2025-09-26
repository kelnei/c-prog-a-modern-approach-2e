#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int t[1000];
int tt[10000];
int ht[100000]; 

int icmp(const void *i1, const void *i2) {
    return *(int *)i1 - *(int *)i2;
}

int main(void)
{
    int i = 0;
    clock_t c;

    for (i = 100000; i > 0; i--) {
        ht[100000 - i] = i;
        if (i > 10000) {
            continue;
        }
        tt[10000 - i] = i;
        if (i > 1000) {
            continue;
        }
        t[1000 - i] = i;
    }

    c = clock();
    qsort(t, 1000, sizeof(int), icmp);
    printf("qsort(1000): %lu ticks\n", (clock() - c));

    c = clock();
    qsort(tt, 10000, sizeof(int), icmp);
    printf("qsort(10000): %lu ticks\n", (clock() - c));

    c = clock();
    qsort(ht, 100000, sizeof(int), icmp);
    printf("qsort(100000): %lu ticks\n", (clock() - c));

    return 0;
}
