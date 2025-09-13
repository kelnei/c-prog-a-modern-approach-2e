#include <stdio.h>
#include <ctype.h>

int main(void) {
    int h, m;
    char c1, c2;

    printf("Enter a 12-hour time: ");
    if (scanf("%2d:%2d", &h, &m) != 2) {
        printf("Invalid input\n");
        return 1;
    }
    if (scanf(" %c%c", &c1, &c2) < 1) {
        printf("Invalid input\n");
        return 1;
    }

    c1 = toupper(c1);
    c2 = toupper(c2);

    if (c1 == 'P') {
        h += 12;
    }

    printf("Equivalent 24-hour time: %.2d:%.2d\n", h, m);

    return 0;
}
