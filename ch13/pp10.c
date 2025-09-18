#include <stdio.h>
#include <ctype.h>

#define N 255

void reverse_name(char *name);

int main(void) {
    char input[N+1];
    char ch;
    int n = 0;

    printf("Enter a first and last name: ");
    while (n < N && (ch = getchar()) != '\n')
        input[n++] = ch;

    reverse_name(input);

    printf("%s\n", input);

    return 0;
}

void reverse_name(char *name)
{
    char initial, *p = name;

    while (*p && isspace(*p))
        p++;

    initial = *p;

    // skip rest of first name
    while (*p && !isspace(*p))
        p++;

    // skip whitespace
    while (*p && isspace(*p))
        p++;

    // copy lastname to start of name
    while (*p && !isspace(*p))
        *name++ = *p++;

    name += sprintf(name, ", %c.", initial);

    // add nul to trim the rest of string
    *name = '\0';
}
