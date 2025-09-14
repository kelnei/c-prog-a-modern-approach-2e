#include <stdio.h>

int main(void) {
    int i = 0, s;
    char a[81] = {0};
    char ch;

    printf("Enter a message to be encrypted: ");
    while (i < 80 && (ch = getchar()) != '\n') {
        a[i++] = ch;
    }

    printf("Enter shift amount (1-25): ");
    if (!scanf("%d", &s)) {
        printf("Invalid input\n");
        return 1;
    }

    // clamp it
    if (s > 25) {
        s = 25;
    } else if (s < 1) {
        s = 1;
    }

    printf("Encrypted message: ");
    i = 0;
    while (i < 80 && a[i]) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            ch = ((a[i] - 'a') + s) % 26 + 'a';
        } else if (a[i] >= 'A' && a[i] <= 'Z') {
            ch = ((a[i] - 'A') + s) % 26 + 'A';
        } else {
            ch = a[i];
        }
        putchar(ch);
        i++;
    }
    printf("\n");


    return 0;
}
