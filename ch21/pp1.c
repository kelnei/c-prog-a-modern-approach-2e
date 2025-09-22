#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(void)
{
    struct s s1;
    printf("sizeof(struct s): %zu\n", sizeof(struct s));
    printf("a:\n  size: %zu\n  offset: %zu\n", sizeof(s1.a), offsetof(struct s, a));
    printf("b:\n  size: %zu\n  offset: %zu\n", sizeof(s1.b), offsetof(struct s, b));
    printf("c:\n  size: %zu\n  offset: %zu\n", sizeof(s1.c), offsetof(struct s, c));

    return 0;
}
