#include <stdio.h>

int main(void)
{
    const char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    };

    int m, d, y;
    printf("Enter a date: (mm/dd/yyyy): ");
    if (scanf("%d /%d /%d", &m, &d, &y) != 3) {
        printf("Invalid input\n");
        return 1;
    }

    printf("You entered the date %s, %d, %d\n", months[m - 1 % 12], d, y);

    return 0;
}
