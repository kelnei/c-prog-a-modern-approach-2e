#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

int compare_dates(const struct date *d1, const struct date *d2);


int main(void) {

    struct date d1, d2;
    int cmp;

    printf("Enter first date (mm/dd/yy): ");
    if (scanf("%2d /%2d /%2d", &d1.month, &d1.day, &d1.year) != 3) {
        printf("Invalid input\n");
        return 1;
    }
    
    printf("Enter second date (mm/dd/yy): ");
    if (scanf("%2d /%2d /%2d", &d2.month, &d2.day, &d2.year) != 3) {
        printf("Invalid input\n");
        return 1;
    }


    cmp = compare_dates(&d1, &d2);
    if (cmp < 0) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
               d1.month, d1.day, d1.year,
               d2.month, d2.day, d2.year);
    } else if (cmp > 0) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
               d2.month, d2.day, d2.year,
               d1.month, d1.day, d1.year);
    } else {
        printf("Both dates are the same.\n");
    }

    return 0;
}

int compare_dates(const struct date *d1, const struct date *d2)
{
    int i;

    i = d1->year - d2->year;
    if (i) return i < 0 ? -1 : 1;

    i = d1->month - d2->month;
    if (i) return i < 0 ? -1 : 1;

    i = d1->day - d1->day;
    if (i) return i < 0 ? -1 : 1;

    return 0;
}
