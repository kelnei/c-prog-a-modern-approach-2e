#include <stdio.h>

int main(void) {
    int dollars;
    printf("Enter a dollar amount: ");
    if (!scanf("%d", &dollars)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("$20 bills: %d\n", dollars / 20);
    dollars = dollars - ((dollars / 20) * 20);
    printf("$10 bills: %d\n", dollars / 10);
    dollars = dollars - ((dollars / 10) * 10);
    printf(" $5 bills: %d\n", dollars / 5);
    dollars = dollars - ((dollars / 5) * 5);
    printf(" $1 bills: %d\n", dollars);
    return 0;
}
