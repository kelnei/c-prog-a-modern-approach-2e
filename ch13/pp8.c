#include <stdio.h>
#include <ctype.h>

int compute_scrabble_value(const char *word);

int main(void) {

    char word[45+1];

    printf("Enter a word: ");
    if (!scanf("%45s", word)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Scrabble value: %d\n", compute_scrabble_value(word));

    return 0;
}

int compute_scrabble_value(const char *word)
{
    const char *p = word;
    char ch;
    int sum = 0;

    while ((ch = *p++)) {
        if (ch >= 'a' && ch <= 'z') {
            ch = toupper(ch);
        }

        if (ch >= 'A' && ch <= 'Z') {
            switch (ch) {
                case 'Q':
                case 'Z':
                    sum += 10;
                    break;
                case 'J':
                case 'X':
                    sum += 8;
                    break;
                case 'K':
                    sum += 5;
                    break;
                case 'F':
                case 'H':
                case 'V':
                case 'W':
                case 'Y':
                    sum += 4;
                    break;
                case 'B':
                case 'C':
                case 'M':
                case 'P':
                    sum += 3;
                    break;
                case 'D':
                case 'G':
                    sum += 2;
                    break;
                default:
                    sum += 1;
            }
        }
    }

    return sum;
}
