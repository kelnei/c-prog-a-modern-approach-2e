#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int sum = 0;

    printf("Enter a word: ");
    while ((ch = getchar()) != '\n') {
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

    printf("Scrabble value: %d\n", sum);

    return 0;
}
