#include <stdio.h>

#define PI 3.14159265359

int main(void) {
    float radius = 10.0f;
    float volume = (4.0f / 3.0f) * PI * radius * radius * radius;
    printf("Volume of 10m sphere is: %.3fm^3\n", volume);
    return 0;
}
