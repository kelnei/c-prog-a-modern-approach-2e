/* Finds the largest and smallest elements in an array */

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int b[N], i, big, small;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++) {
        if (!scanf("%d", &b[i])) {
            printf("Invalid input\n");
            return 1;
        }
    }

    max_min(b, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
    int *p = a;

    *max = *min = a[0];

    while (p < a + n) {
        if (*p > *max) {
            *max = *p;
        } else if (*p < *min) {
            *min = *p;
        }
        p++;
    }
}
