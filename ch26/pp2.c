#include <stdio.h>
#include <stdlib.h>

void thatsall(void);
void folks(void);

int main(void)
{
    atexit(folks);
    atexit(thatsall);
    return 0;
}

void thatsall(void) {
    printf("That's all, ");
}

void folks(void) {
    printf("folks!\n");
}
