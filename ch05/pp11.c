#include <stdio.h>

int main(void) {
    int i;

    printf("Enter a two-digit number: ");
    if (!scanf("%2d", &i)) {
        printf("Invalid input\n");
        return 1;
    }

    switch (i / 10) {
        case 9:
            printf("ninety");
            break;
        case 8:
            printf("eighty");
            break;
        case 7:
            printf("seventy");
            break;
        case 6:
            printf("sixty");
            break;
        case 5:
            printf("fifty");
            break;
        case 4:
            printf("forty");
            break;
        case 3:
            printf("thirty");
            break;
        case 2:
            printf("twenty");
            break;
        case 1:
            switch (i % 10) {
                case 9:
                    printf("nineteen\n");
                    return 0;
                case 8:
                    printf("eighteen\n");
                    return 0;
                case 7:
                    printf("seventeen\n");
                    return 0;
                case 6:
                    printf("sixteen\n");
                    return 0;
                case 5:
                    printf("fifteen\n");
                    return 0;
                case 4:
                    printf("fourteen\n");
                    return 0;
                case 3:
                    printf("thirteen\n");
                    return 0;
                case 2:
                    printf("twelve\n");
                    return 0;
                case 1:
                    printf("eleven\n");
                    return 0;
                case 0:
                    printf("ten\n");
                    return 0;
            }
            break;
    }

    if (i > 20 && i % 10 != 0) {
        printf("-");
    }

    switch (i % 10) {
        case 9:
            printf("nine\n");
            break;
        case 8:
            printf("eight\n");
            break;
        case 7:
            printf("seven\n");
            break;
        case 6:
            printf("six\n");
            break;
        case 5:
            printf("five\n");
            break;
        case 4:
            printf("four\n");
            break;
        case 3:
            printf("three\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 1:
            printf("one\n");
            break;
        case 0:
            if (i == 0) {
                printf("zero\n");
            } else {
                printf("\n");
            }
            break;
    }

    return 0;
}
