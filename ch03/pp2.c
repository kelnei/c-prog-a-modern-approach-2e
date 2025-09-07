#include <stdio.h>

int main(void) {
    int item, m, d, y;
    float price;

    printf("Enter item number: ");
    if(!scanf("%d", &item)) {
        printf("Invalid input\n");
        return -1;
    }

    printf("Enter unit price: ");
    if(!scanf("%f", &price)) {
        printf("Invalid input\n");
        return -1;
    }

    printf("Enter purchase date (mm/dd/yyyy): ");
    if(scanf("%d/%d/%d", &m, &d, &y) != 3) {
        printf("Invalid input\n");
        return -1;
    }

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%-d\t\t$%4.2f\t\t%-.2d/%-.2d/%-.4d\n", item, price, m, d, y);
    return 0;
}
