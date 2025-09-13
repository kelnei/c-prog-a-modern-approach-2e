#include <stdio.h>

int main(void) {
    printf("int:\t\t%zu\n", sizeof(int));
    printf("short:\t\t%zu\n", sizeof(short));
    printf("long:\t\t%zu\n", sizeof(long));
    printf("float:\t\t%zu\n", sizeof(float));
    printf("double:\t\t%zu\n", sizeof(double));
    printf("long double:\t%zu\n", sizeof(long double));
    return 0;
}
