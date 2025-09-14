#include <stdio.h>

#define LEN(a) ((int)(sizeof(a)/sizeof(a[0])))

int main(void) {
    int i, j, a[5][5], sum;

    for (i = 0; i < LEN(a); i++) {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < LEN(a[i]); j++) {
            if (!scanf("%d", &a[i][j])) {
                printf("Invalid input\n");
                return 1;
            }
        }
    }

    printf("Row totals:");
    for (i = 0; i < LEN(a); i++) {
        sum = 0;
        for (j = 0; j < LEN(a[i]); j++) {
            sum += a[i][j];
        }
        printf(" %d", sum);
    }
    printf("\n");

    printf("Column totals:");
    for (i = 0; i < LEN(a); i++) {
        sum = 0;
        for (j = 0; j < LEN(a[i]); j++) {
            sum += a[j][i];
        }
        printf(" %d", sum);
    }
    printf("\n");
}
