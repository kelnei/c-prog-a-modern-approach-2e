#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

int main(void)
{
    char buffer[N];
    char *p;
    int n;
    
    printf("Enter a series of words separated by single spaces: ");
    if (fgets(buffer, N, stdin) == NULL) {
        fprintf(stderr, "input error\n");
        exit(EXIT_FAILURE);
    }

    n = strlen(buffer);

    // strip the new line
    if (buffer[n - 1] == '\n') {
        buffer[n - 1] = '\0';
        n--;
    }

    p = strtok(buffer, " ");

    printf("In reverse order: ");

    if (p == NULL) {
        printf("%s\n", buffer);
        return 0;
    }

    while ((p = strtok(NULL, " ")) != NULL)
        ;

    p = buffer + n - 1;
    while (p > buffer) {
        if (*p == '\0') {
            printf("%s ", p + 1);
        }
        p--;
    }
    printf("%s\n", buffer);

    return 0;
}
