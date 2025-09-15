#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char ch;
    int wins = 0, losses = 0;

    srand((int)time(NULL));

    do {
        if (play_game()) {
            wins++;
            printf("You win!\n");
        } else {
            losses++;
            printf("You lose!\n");
        }

        printf("\nPlay again? ");
        ch = getchar();
        (void)getchar(); // \n
        printf("\n");
    } while(ch == 'y' || ch == 'Y');

    printf("Wins: %d\tLosses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void)
{
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

bool play_game(void)
{
    int point = 0;

    for (;;) {
        int dice = roll_dice();
        printf("You rolled: %d\n", dice);

        if (!point) {
            // first roll
            if (dice == 7 || dice == 11)
                return true;

            if (dice == 2 || dice == 3 || dice == 12)
                return false;

            point = dice;
            printf("You point is %d\n", point);
        } else if (dice == point) {
            return true;
        } else if (dice == 7) {
            return false;
        }
    }
}
