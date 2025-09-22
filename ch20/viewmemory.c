/* Allows the user to view regions of computer memory */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char BYTE;

int main(void)
{
    unsigned long long addr;
    int i, n;
    BYTE *ptr;

    printf("Address of main function: %llx\n", (unsigned long long)main);
    printf("Address of addr variable: %llx\n", (unsigned long long)&addr);

    printf("\nEnter a (hex) address: ");
    if(!scanf("%llx", &addr)) {
        printf("error: invalid input\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter number of bytes to view: ");
    if(!scanf("%d", &n)) {
        printf("error: invalid input\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("   Address                Bytes              Characters\n");
    printf(" -----------  -----------------------------  ----------\n");

    ptr = (BYTE *)addr;
    for (; n > 0; n -= 10) {
        printf("%12llX  ", (unsigned long long)ptr);
        for (i = 0; i < 10 && i < n; i++)
            printf("%.2X ", *(ptr + i));
        for (; i < 10; i++)
            printf("   ");
        printf(" ");
        for (i = 0; i < 10 && i < n; i++) {
            BYTE ch = *(ptr + i);
            if (!isprint(ch))
                ch = '.';
            printf("%c", ch);
        }
        printf("\n");
        ptr += 10;
    }

    return 0;
}
