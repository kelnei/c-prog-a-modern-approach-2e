#include <stdio.h>

int main(void) {
    int d1, m1, y1, d2, m2, y2;

    printf("Enter a date (mm/dd/yy): ");
    if (scanf("%2d /%2d /%2d", &m1, &d1, &y1) != 3) {
        printf("Invalid input\n");
        return 1;
    }

    m2 = m1;
    d2 = d1;
    y2 = y1;

    while (m1 != 0 && d1 != 0 && y2 != 0) {
        printf("Enter a date (mm/dd/yy): ");
        if (scanf("%2d /%2d /%2d", &m1, &d1, &y1) != 3) {
            printf("Invalid input\n");
            return 1;
        }

        if (m1 == 0 || d1 == 0 || y1 == 0)
            break;

        if (y1 > y2) continue;
        if (y1 == y2 && m1 > m2) continue;
        if (y1 == y2 && m1 == m2 && d1 > d2) continue;

        y2 = y1;
        m2 = m1;
        d2 = d1;
    }

    printf("%d/%d/%.2d is the earliest date\n", m2, d2, y2);

    return 0;
}
