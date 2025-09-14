/* Reverses a series of numbers */

#include <stdio.h>

#define LEN(a) ((int)(sizeof(a)/sizeof(a[0])))

int main(void) {

    int a[10], i;

    printf("Enter %d numbers: ", LEN(a));
    for (i = 0; i < LEN(a); i++)
        if (!scanf("%d", &a[i])) {
            printf("Invalid input\n");
            return 1;
        }

    printf("In reverse order:");
    for (i = LEN(a) - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");


    return 0;
}
