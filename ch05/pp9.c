#include <stdio.h>

int main(void) {
    int d1, m1, y1, d2, m2, y2;

    printf("Enter first date (mm/dd/yy): ");
    if (scanf("%2d /%2d /%2d", &m1, &d1, &y1) != 3) {
        printf("Invalid input\n");
        return 1;
    }
    
    printf("Enter second date (mm/dd/yy): ");
    if (scanf("%2d /%2d /%2d", &m2, &d2, &y2) != 3) {
        printf("Invalid input\n");
        return 1;
    }

    if (y1 < y2) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
    } else if (y1 > y2) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
    } else if (m1 < m2) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
    } else if (m1 > m2) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
    } else if (d1 < d2) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
    } else if (d1 > d2) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
    } else {
        printf("Both dates are the same.\n");
    }

    return 0;
}
