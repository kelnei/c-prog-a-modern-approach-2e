#include <stdio.h>

int main(void) {
    int i;

    const char *tens[] = {
        "",
        "ten",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",
    };

    const char *ones[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    };

    printf("Enter a two-digit number: ");
    if (!scanf("%2d", &i) || i < 0) {
        printf("Invalid input\n");
        return 1;
    }

    if (i < 20) {
        printf("%s\n", ones[i]);
    } else if (i % 10 == 0) {
        printf("%s\n", tens[i / 10]);
    } else {
        printf("%s-%s\n", tens[i / 10], ones[i % 10]);
    }

    return 0;
}
