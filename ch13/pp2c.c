/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+12];
    char daytime_str[12], msg_str[MSG_LEN+1];
    int month, day, hour, min, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day (mm/dd), 24-hour time (HH:mm) and reminder: ");
        if (!scanf("%2d", &month)) {
            printf("Invalid input\n");
            return 1;
        }
        if (month == 0) break;
        if (day < 0 || day > 12) {
            printf("Invalid month, ignored\n");
            read_line(msg_str, 0);
            continue;
        }

        if (!scanf(" /%2d", &day)) {
            printf("Invalid input\n");
            return 1;
        }
        if (day == 0) break;

        if (day < 0 || day > 31) {
            printf("Invalid day, ignored\n");
            read_line(msg_str, 0);
            continue;
        }

        if (!scanf("%2d:%2d", &hour, &min)) {
            printf("Invalid input\n");
            return 1;
        }

        if (hour < 0 || hour > 23) {
            printf("Invalid hour, ignored\n");
            read_line(msg_str, 0);
            continue;
        }

        if (min < 0 || min > 59) {
            printf("Invalid minute, ignored\n");
            read_line(msg_str, 0);
            continue;
        }

        sprintf(daytime_str, "%2d/%.2d %.2d:%.2d", month, day, hour, min);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(daytime_str, reminders[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], daytime_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nYear Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
