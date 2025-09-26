#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int m, d, y, n;
    struct tm t = {0};
    char date[11] = {0};

    printf("Enter a date (mm/dd/yyyy): ");
    if (scanf("%2d/%2d/%4d", &m, &d, &y) != 3) {
        fprintf(stderr, "invalid date");
        exit(EXIT_FAILURE);
    }

    printf("Enter a number: ");
    if (!scanf("%d", &n)) {
        fprintf(stderr, "invalid number");
        exit(EXIT_FAILURE);
    }

    t.tm_mday = d + n;
    t.tm_mon = m - 1;
    t.tm_year = y - 1900;

    mktime(&t);

    strftime(date, sizeof(date) / sizeof(*date), "%m/%d/%Y", &t);

    printf("It will be %s in %d days.\n", date, n);

    return 0;
}
