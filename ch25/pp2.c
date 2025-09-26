#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    struct lconv *lc;
    char *ch;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <locale>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    setlocale(LC_ALL, argv[1]);

    lc = localeconv();

    // char *
    printf("decimal_point = \"%s\"\n", lc->decimal_point);
    printf("thousands_sep = \"%s\"\n", lc->thousands_sep);
    printf("grouping = ");
    for (ch = lc->grouping; *ch != '\0' && *ch != CHAR_MAX; ch++)
        printf("%hhd", *ch);
    printf("\n");
    printf("mon_decimal_point = \"%s\"\n", lc->mon_decimal_point);
    printf("mon_thousands_sep = \"%s\"\n", lc->mon_thousands_sep);
    printf("mon_grouping = ");
    for (ch = lc->mon_grouping; *ch != '\0' && *ch != CHAR_MAX; ch++)
        printf("%hhd", *ch);
    printf("\n");
    printf("positive_sign = \"%s\"\n", lc->positive_sign);
    printf("negative_sign = \"%s\"\n", lc->negative_sign);
    printf("currency_symbol = \"%s\"\n", lc->currency_symbol);
    // char
    printf("frac_digits = %hhu\n", lc->frac_digits);
    printf("p_cs_precedes = %hhu\n", lc->p_cs_precedes);
    printf("n_cs_precedes = %hhu\n", lc->n_cs_precedes);
    printf("p_sep_by_space = %hhu\n", lc->p_sep_by_space);
    printf("n_sep_by_space = %hhu\n", lc->n_sep_by_space);
    printf("p_sign_posn = %hhu\n", lc->p_sign_posn);
    printf("n_sign_posn = %hhu\n", lc->n_sign_posn);
    printf("int_curr_symbol = \"%s\"\n", lc->int_curr_symbol);
    printf("int_frac_digits = %hhu\n", lc->int_frac_digits);
    printf("int_p_cs_precedes = %hhu\n", lc->int_p_cs_precedes);
    printf("int_n_cs_precedes = %hhu\n", lc->int_n_cs_precedes);
    printf("int_p_sep_by_space = %hhu\n", lc->int_p_sep_by_space);
    printf("int_n_sep_by_space = %hhu\n", lc->int_n_sep_by_space);
    printf("int_p_sign_posn = %hhu\n", lc->int_p_sign_posn);
    printf("int_n_sign_posn = %hhu\n", lc->int_n_sign_posn);

    return 0;
}
