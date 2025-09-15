#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);

int main(void) {
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++) {
        if (!scanf("%d", &a[i])) {
            printf("Invalid input\n");
            return 1;
        }
    }

    selection_sort(a, N);

    printf("In sorted order: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n) {
    int i, k = 0, max;

    if (n <= 1) return;

    max = a[k];

    // find largest element
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            k = i;
        }
    }

    // swap to last element
    if (k != n - 1) {
        i = a[n - 1];
        a[n - 1] = a[k];
        a[k] = i;
    }

    selection_sort(a, n - 1);
}
