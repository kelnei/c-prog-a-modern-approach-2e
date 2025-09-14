#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch, message[80] = {0};
    int i = 0;

    char BIFF[] = {
        '4','8','C','D','3','F','G','H','1','J','K','L','M',
        'N','0','P','Q','R','5','T','U','V','W','X','Y','Z'
    };

    printf("Enter message: ");

    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        if (ch >= 'A' && ch <= 'Z') {
            message[i++] = BIFF[ch - 'A'];
        } else {
            message[i++] = ch;
        }
    }
    printf("In B1FF-speak: %s!!!!!!!!!!\n", message);

    return 0;
}
