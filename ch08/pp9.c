#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    char a[10][10];
    int i = 0, j = 0; 
    char c = 'A';

    srand((unsigned)time(NULL));

    memset(a, '.', sizeof(a));

    // set origin
    a[i][j] = c++;

    while (1) {
        // are we blocked?
        if (
            (i == 0 || a[i - 1][j] != '.') && // can't go up
            (i == 9 || a[i + 1][j] != '.') && // can't go down
            (j == 0 || a[i][j - 1] != '.') && // can't go left
            (j == 9 || a[i][j + 1] != '.')    // can't go right
        ) break;

        switch (rand() % 4) {
            // go up
            case 0:
                if (i != 0 && a[i - 1][j] == '.') {
                    a[--i][j] = c++;
                }
                break;

            // go right
            case 1:
                if (j != 9 && a[i][j + 1] == '.') {
                    a[i][++j] = c++;
                }
                break;

            // go down
            case 2:
                if (i != 9 && a[i + 1][j] == '.') {
                    a[++i][j] = c++;
                }
                break;

            // go left
            case 3:
                if (j != 0 && a[i][j - 1] == '.') {
                    a[i][--j] = c++;
                }
                break;
        }

        // out of letters
        if (c > 'Z') break;
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
