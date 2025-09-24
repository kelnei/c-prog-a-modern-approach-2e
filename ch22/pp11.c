#include <stdio.h>
#include <stdlib.h>

static const char *months[] = {
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

int main(int argc, char *argv[])
{
    int m, d, y;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <date>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (sscanf(argv[1], "%d/%d/%d", &m, &d, &y) == 3) {
        printf("%s %d, %d\n", months[m - 1 % 12], d, y);
    } else if (sscanf(argv[1], "%d-%d-%d", &m, &d, &y) == 3) {
        printf("%s %d, %d\n", months[m - 1 % 12], d, y);
    } else {
        fprintf(stderr, "error: expected date in mm/dd/yyyy or mm-dd-yyyy format\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
