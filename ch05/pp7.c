#include <stdio.h>

int main(void) {
    int i, j, k, l, min, max;

    printf("Enter four integers: ");
    if (scanf("%d%d%d%d", &i, &j, &k, &l) != 4) {
        printf("Invalid input\n");
        return 1;
    }

    max = min = i;

    if (j < i) {
        min = j;
    } else {
        max = j;
    }
    
    if (k < min) {
        min = k;
    } else if (k > max) {
        max = k;
    }

    if (l < min) {
        min = l;
    } else if (l > max) {
        max = l;
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}
