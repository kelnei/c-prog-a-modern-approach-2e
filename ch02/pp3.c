#include <stdio.h>

#define PI 3.14159265359

int main(void) {
    int radius;
    float volume;
    printf("Enter the radius of the sphere: ");
    if (!scanf("%d", &radius)) {
        printf("Invalid input\n");
        return -1;
    }
    volume = (4.0f / 3.0f) * PI * radius * radius * radius;
    printf("Volume of %dm sphere is: %.3fm^3\n", radius, volume);
    return 0;
}
