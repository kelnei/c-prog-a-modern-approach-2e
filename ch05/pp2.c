#include <stdio.h>

int main(void) {
    int h, m;

    printf("Enter a 24-hour time: ");
    if (scanf("%2d:%2d", &h, &m) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Equivalent 12-hour time: ");
    if (h > 12) {
        printf("%d:%.2d PM\n", h - 12, m);
    } else {
        printf("%d:%.2d AM\n", h == 0 ? 12 : h, m);
    }

    return 0;
}
