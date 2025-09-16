/* Classifies a poker hand */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
char hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/*
 * main: Calls read_cards, analyze_hand, and print_result
 *       repeatedly.
 */
int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/*
 * read_cards: Reads the cards into external variables;
 *             checks for bad cards and duplicate cards.
 */
void read_cards(void)
{
    char ch, rank_ch, suit_ch;
    int rank = 0, suit = 0;
    bool bad_card, duplicate;
    int cards_read = 0, i;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card)
            printf("Bad card; ignored.\n");
        else {
            duplicate = false;
            for (i = 0; i < cards_read; i++) {
                if (hand[i][0] == rank && hand[i][1] == suit) {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate) {
                printf("Duplicate card; ignored.\n");
            } else {
                hand[cards_read][0] = rank;
                hand[cards_read][1] = suit;
                cards_read++;
            }
        }
    }
}

/*
 * analyze_hand: Determines whether the hand contains a
 *               straight, a flush, four-of-a-kind,
 *               and/or three-of-a-kind; determines the
 *               number of pairs; stores the results into
 *               external variables straight, flush,
 *               four, three and pairs.
 */
void analyze_hand(void)
{
    int i, j, rank, suit;
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    // sort by rank using bubble sort
    for (i = NUM_CARDS - 1; i > 0; i--) {
        for (j = 0; j <= i; j++) {
            if (hand[j][0] > hand[i][0]) {
                rank = hand[j][0];
                suit = hand[j][1];
                hand[j][0] = hand[i][0];
                hand[j][1] = hand[i][1];
                hand[i][0] = rank;
                hand[i][1] = suit;
            }
        }
    }

    /* check for flush */
    for (i = 1; i < NUM_CARDS; i++)
        if (hand[0][1] != hand[i][1])
            flush = false;

    /* check for straight */
    for (i = 1; i < NUM_CARDS; i++)
        if (hand[i][0] != hand[0][0] + i)
            straight = false;

    /* Check for 4-of-a-kind, 3-of-a-kind, and pairs */
    i = 0;
    while (i < NUM_CARDS) {
        rank = hand[i][0];
        j = 0;
        while (++j && ++i < NUM_CARDS && hand[i][0] == rank)
            ;
        switch (j) {
            case 4: four = true; break;
            case 3: three = true; break;
            case 2: pairs++; break;
        }
    }
}

/*
 * print_result: Prints the classification of the hand,
 *               based on the values of the external
 *               variables straight, flush, four, three,
 *               and pairs.
 */
void print_result(void)
{
    if (straight && flush) printf("Straight flush");
    else if (four)         printf("Four of a kind"); 
    else if (three &&
             pairs == 1)   printf("Full house");
    else if (flush)        printf("Flush");
    else if (straight)     printf("Straight");
    else if (three)        printf("Three of a kind");
    else if (pairs == 2)   printf("Two pairs");
    else if (pairs == 1)   printf("Pair");
    else                   printf("High card");

    printf("\n\n");
}
