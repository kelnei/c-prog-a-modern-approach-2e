/* Checks planet names */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int istrcmp(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    char *planets[] = {
        "Mercury",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Uranus",
        "Neptune",
        "Pluto",
    };

    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++) {
            if (istrcmp(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", planets[j], j + 1);
                break;
            }
        }
        if (j == NUM_PLANETS) {
            printf("%s is not a planet\n", argv[i]);
        }
    }

    return 0;
}

int istrcmp(const char *s1, const char *s2)
{
    const char *p = s1, *q = s2;
    while (tolower(*p) == tolower(*q)) {
        if (*p == '\0')
            return 0;
        p++;
        q++;
    }
    return *p - *q;
}
