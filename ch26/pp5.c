#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int m, d, y;
    struct tm ts = {0};
    time_t t1, t2;

    printf("Enter first date (mm/dd/yyyy): ");
    if (scanf("%2d/%2d/%4d", &m, &d, &y) != 3) {
        fprintf(stderr, "invalid date");
        exit(EXIT_FAILURE);
    }

    ts.tm_mday = d;
    ts.tm_mon = m - 1;
    ts.tm_year = y - 1900;
    t1 = mktime(&ts);

    printf("Enter second date (mm/dd/yyyy): ");
    if (scanf("%2d/%2d/%4d", &m, &d, &y) != 3) {
        fprintf(stderr, "invalid date");
        exit(EXIT_FAILURE);
    }

    ts.tm_mday = d;
    ts.tm_mon = m - 1;
    ts.tm_year = y - 1900;
    t2 = mktime(&ts);

    printf("Date difference in days: %g\n", difftime(t2, t1) / 86400); 

    return 0;
}
