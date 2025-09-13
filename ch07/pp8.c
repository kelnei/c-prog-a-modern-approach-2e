#include <stdio.h>
#include <ctype.h>

int main(void) {
    int h, m, i;
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

    i = h * 60 + m;

    if (i < 3 * 60 - 7) {
        // less than 7 minutes before 3:00am is closer to 9:45pm than 8:00am
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    } else if (i < 8 * 60 + 52) { 
        // less than 52 minutes after 8:00am
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    } else if (i <= 9 * 60 + 43 + 48) {
        // up to 48 minutes after 9:43am
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    } else if (i <= 11 * 60 + 19 + 43) {
        // up to 43 minutes after 11:19am
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    } else if (i < 12 * 60 + 47 + 37) {
        // less than 37 minutes after 12:47pm
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    } else if (i < 14 * 60 + 53) {
        // less than 53 minutes after 2:00pm
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    } else if (i < 15 * 60 + 45 + 97) {
        // less than 97 minutes after 3:45pm
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    } else if (i < 19 * 60 + 83) {
        // less than 83 minutes after 7:00pm
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    } else {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }


    return 0;
}
