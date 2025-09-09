#include <stdio.h>

int main(void) {
    int grade;

    printf("Enter numerical grade: ");
    if (!scanf("%d", &grade)) {
        printf("Invalid input\n");
        return 1;
    }

    if (grade > 100) {
        printf("Error: the numerical grade must be <= 100\n");
        return 1;
    } else if (grade < 0) {
        printf("Error: the numerical grade must be >= 0\n");
        return 1;
    }

    switch (grade / 10) {
        case 10:
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        default:
            printf("F\n");
            break;
    }

    return 0;
}
