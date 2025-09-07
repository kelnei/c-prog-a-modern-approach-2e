#include <stdio.h>

int main(void) {
    int m, d, y;
    printf("Enter a date (mm/dd/yyyy): ");
    if(scanf("%d/%d/%d", &m, &d, &y) != 3) {
        printf("Invalid input\n");
        return -1;
    }
    printf("You entered the date %.4d%.2d%.2d\n", y, m, d);
    return 0;
}
