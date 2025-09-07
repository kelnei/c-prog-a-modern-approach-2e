#include <stdio.h>

int main(void) {
    int area, prefix, line;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    if(scanf("(%d) %d-%d", &area, &prefix, &line) != 3) {
        printf("Invalid input\n");
        return -1;
    }

    printf("%.3d.%.3d.%.4d\n", area, prefix, line);
    return 0;
}
