#include <stdio.h>

#define LEN(a) (sizeof(a)/sizeof(a[0]))

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = {
    {"Argentina", 54},
    {"Brazil", 55},
    {"China", 86},
    {"Congo", 243},
    {"Ethiopia", 251},
    {"Germany", 49},
    {"Indonesia", 62},
    {"Iran", 98},
    {"Italy", 39},
    {"Japan", 81},
    {"Mexico", 52},
    {"Nigeria", 234},
    {"Pakistan", 92},
    {"Phillippines", 63},
    {"Poland", 48},
    {"Russia", 7},
    {"South Africa", 27},
    {"South Korea", 82},
    {"Spain", 34},
    {"Sudan", 249},
    {"Thailand", 66},
    {"Turkey", 90},
    {"Ukraine", 380},
    {"United Kingdom", 44},
    {"United States", 1},
    {"Vietnam", 84},
};

const char *lookup_country(int code)
{
    for (size_t i = 0; i < LEN(country_codes); i++)
        if (country_codes[i].code == code)
            return country_codes[i].country;

    return NULL;
}

int main(void)
{
    int code;
    printf("Enter a country dialing code: ");

    if (!scanf("%d", &code)) {
        printf("Invalid input\n");
        return 1;
    }

    const char *country = lookup_country(code);

    if (!country) {
        printf("Not a recognized code.\n");
    } else {
        printf("%s\n", country);
    }

    return 0;
}
