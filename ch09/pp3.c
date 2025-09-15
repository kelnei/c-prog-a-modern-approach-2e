#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
    char walk[10][10];

    srand((unsigned)time(NULL));
    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[10][10])
{
    int i = 0, j = 0; 
    char c = 'A';

    memset(walk, '.', 100);

    // set origin
    walk[i][j] = c++;

    while (1) {
        // are we blocked?
        if (
            (i == 0 || walk[i - 1][j] != '.') && // can't go up
            (i == 9 || walk[i + 1][j] != '.') && // can't go down
            (j == 0 || walk[i][j - 1] != '.') && // can't go left
            (j == 9 || walk[i][j + 1] != '.')    // can't go right
        ) break;

        switch (rand() % 4) {
            // go up
            case 0:
                if (i != 0 && walk[i - 1][j] == '.') {
                    walk[--i][j] = c++;
                }
                break;

            // go right
            case 1:
                if (j != 9 && walk[i][j + 1] == '.') {
                    walk[i][++j] = c++;
                }
                break;

            // go down
            case 2:
                if (i != 9 && walk[i + 1][j] == '.') {
                    walk[++i][j] = c++;
                }
                break;

            // go left
            case 3:
                if (j != 0 && walk[i][j - 1] == '.') {
                    walk[i][--j] = c++;
                }
                break;
        }

        // out of letters
        if (c > 'Z') break;
    }
}

void print_array(char walk[10][10])
{
    int i, j; 
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}
