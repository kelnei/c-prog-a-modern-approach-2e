#include <stdio.h>

int main(void) {
    int gs1, gi, publisher, item, check;

    printf("Enter ISBN: ");
    if(scanf("%d-%d-%d-%d-%d", &gs1, &gi, &publisher, &item, &check) != 5) {
        printf("Invalid input\n");
        return -1;
    }

    printf("GS1 Prefix: %.3d\n", gs1);
    printf("Group identifier: %.1d\n", gi);
    printf("Publisher code: %.3d\n", publisher);
    printf("Item number: %.5d\n", item);
    printf("Check digit: %.1d\n", check);
    return 0;
}
