#include <stdio.h>

int main(void) {
    int i;
    printf("Enter a number between 0 and 32767: ");
    if (!scanf("%d", &i)) {
        printf("Invalid input\n");
        return -1;
    }
    printf("In octal, your number is: 0%d%d%d%d\n",
           i / 8 / 8 / 8 % 8, 
           i / 8 / 8 % 8, 
           i / 8 % 8, 
           i % 8); 

    return 0;
}
