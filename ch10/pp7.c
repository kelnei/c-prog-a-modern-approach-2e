#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

const int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1},  // 9
};

char digits[4][MAX_DIGITS * 4];
int n;

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    char ch;

    clear_digits_array();

    printf("Enter a number: ");
    while (n < MAX_DIGITS && (ch = getchar()) != '\n') {
        if (isdigit(ch)) {
            process_digit(ch - '0', n++);
        }
    }

    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        for (n = 0; n < MAX_DIGITS * 4; n++) {
            digits[i][n] = ' ';
        }
    }
    n = 0;
}

void process_digit(int digit, int position)
{
    int i, p;
    p = position * 4;
    for (i = 0; i < 7; i++) {
        if (segments[digit][i]) {
            switch (i) {
                case 0:
                    digits[0][p + 1] = '_';
                    break;
                case 1:
                    digits[1][p + 2] = '|';
                    break;
                case 2:
                    digits[2][p + 2] = '|';
                    break;
                case 3:
                    digits[2][p + 1] = '_';
                    break;
                case 4:
                    digits[2][p] = '|';
                    break;
                case 5:
                    digits[1][p] = '|';
                    break;
                case 6:
                    digits[1][p + 1] = '_';
                    break;
            }
        }
    }
}

void print_digits_array(void)
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < n * 4; j++) {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
}
