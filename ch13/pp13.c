#include <stdio.h>

void encrypt(char *message, int shift);

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

    encrypt(a, s);
    printf("Encrypted message: %s\n", a);

    return 0;
}

void encrypt(char *message, int shift)
{
    char *p = message; 

    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            *p = ((*p - 'a') + shift) % 26 + 'a';
        } else if (*p >= 'A' && *p <= 'Z') {
            *p = ((*p - 'A') + shift) % 26 + 'A';
        }
        p++;
    }
}
