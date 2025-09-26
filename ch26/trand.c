/* Tests the pseudo-random sequence generation functions */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, seed;

    printf("This program displays the first five values of "
           "rand.\n");

    for (;;) {
        for (i = 0; i < 5; i++)
            printf("%d ", rand());
        printf("\n\n");
        printf("Enter new seed value (0 to terminate): ");
        if (!scanf("%d", &seed)) {
            fprintf(stderr, "invalid seed\n");
            exit(EXIT_FAILURE);
        }
        if (seed == 0)
            break;
        srand(seed);
    }

    return 0;
}
