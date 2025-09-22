#include <stdio.h>

typedef struct {
    unsigned int fraction: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
} float_bits;

typedef union {
    float f;
    float_bits bits;
} f32;

int main(void)
{
    f32 f = {0};

    f.bits.exponent = 128;
    f.bits.sign = 1;

    printf("%.1f\n", f.f);

    return 0;
}

