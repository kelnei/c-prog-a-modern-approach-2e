/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>

#define N 10

void quicksort(int *low, int *high);
int *split(int *low, int *high);

int main(void) {
    int a[N], *p = a, *q = a + N;

    printf("Enter %d numbers to be sorted: ", N);
    while (p < q) {
        if (!scanf("%d", p++)) {
            printf("Invalid input\n");
            return 1;
        }
    }

    p = a;
    quicksort(p, q - 1);

    printf("In sorted order: ");
    while (p < q) {
        printf("%d ", *p++);
    }
    printf("\n");

    return 0;
}

void quicksort(int *low, int *high) {
    int *middle;

    if (low >= high) return;
    middle = split(low, high);
    quicksort(low, middle - 1);
    quicksort(middle + 1, high);
}

int *split(int *low, int *high) {
    int part_element = *low;

    for(;;) {
        while (low < high && part_element <= *high)
            high--;
        if (low >= high) break;
        *low++ = *high;

        while (low < high && *low <= part_element)
            low++;
        if (low >= high) break;
        *high-- = *low;
    }

    *high = part_element;
    return high;
}

