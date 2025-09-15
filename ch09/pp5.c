#include <stdio.h>
#include <string.h>

void create_magic_square(int n, short magic_square[n][n]);
void print_magic_square(int n, short magic_square[n][n]);

int main(void) {
    int n;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter the size of magic square: ");
    if (!scanf("%d", &n)) {
        printf("Invalid input\n");
        return 1;
    }


    if (n % 2 != 1 || n < 1 || n > 99) {
        printf("Invalid size\n");
        return 1;
    }

    short magic_square[n][n];
    memset(magic_square, 0, n * n * sizeof(short));
    create_magic_square(n, magic_square);
    print_magic_square(n, magic_square);

    return 0;
}

void create_magic_square(int n, short magic_square[n][n])
{
    int r, c;
    long i;
    r = 0;
    c = n / 2;
    for (i = 1; i <= n * n; i++) {
        // occupied? put it below last store number
        if (magic_square[r][c]) {
            r += 2;
            c--;
            if (r > n - 1) r %= n;
            if (c < 0) c = n - 1;
        }
        magic_square[r--][c++] = i;
        if (r < 0) r = n - 1;
        if (c > n - 1) c = 0;
    }
}

void print_magic_square(int n, short magic_square[n][n])
{
    int r, c;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            printf("%5hd", magic_square[r][c]);
        }
        printf("\n");
    }
}
