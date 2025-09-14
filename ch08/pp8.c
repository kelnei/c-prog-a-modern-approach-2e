#include <stdio.h>

#define LEN(a) ((int)(sizeof(a)/sizeof(a[0])))

int main(void) {
    int i, j, a[5][5], total, max, min;

    for (i = 0; i < LEN(a); i++) {
        printf("Enter five scores for student %d: ", i + 1);
        for (j = 0; j < LEN(a[i]); j++) {
            if (!scanf("%d", &a[i][j])) {
                printf("Invalid input\n");
                return 1;
            }
        }
    }

    printf("\n");
    printf("\t\tTotal\tAvg\n");
    for (i = 0; i < LEN(a); i++) {
        total = 0;
        for (j = 0; j < LEN(a[i]); j++) {
           total += a[i][j];
        }
        printf("Student %d:\t%d\t%.1f\n", i + 1, total, (float)total / LEN(a[i]));
    }
    printf("\n");

    printf("\t\tAvg\tHigh\tLow\n");
    for (i = 0; i < LEN(a); i++) {
        total = 0;
        for (j = 0; j < LEN(a[i]); j++) {
            total += a[j][i];
            if (j == 0) {
                max = a[j][i];
                min = a[j][i];
            } else {
                if (a[j][i] > max) max = a[j][i];
                if (a[j][i] < min) min = a[j][i];
            }
        }
        printf("Quiz %d:\t\t%.1f\t%d\t%d\n", i + 1, (float)total / LEN(a[i]), max, min);
    }
    printf("\n");
}
