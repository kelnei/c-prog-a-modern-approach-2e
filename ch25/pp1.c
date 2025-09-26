#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    struct lconv c, native, *lc;
    setlocale(LC_ALL, "C");
    lc = localeconv();
    memcpy(&c, lc, sizeof(struct lconv));

    setlocale(LC_ALL, "");
    lc = localeconv();
    memcpy(&native, lc, sizeof(struct lconv));

    // char *
    printf("Property            \tC\t\tNative\n");
    printf("\n");
    printf("decimal_point:      \t\"%s\"\t\t\"%s\"\n", c.decimal_point,     native.decimal_point);
    printf("thousands_sep:      \t\"%s\"\t\t\"%s\"\n", c.thousands_sep,     native.thousands_sep);
    printf("grouping:           \t%hhd\t\t%hhd\n", *c.grouping,          *native.grouping);
    printf("mon_decimal_point:  \t\"%s\"\t\t\"%s\"\n", c.mon_decimal_point, native.mon_decimal_point);
    printf("mon_thousands_sep:  \t\"%s\"\t\t\"%s\"\n", c.mon_thousands_sep, native.mon_thousands_sep);
    printf("mon_grouping:       \t%hhd\t\t%hhd\n", *c.mon_grouping,      *native.mon_grouping);
    printf("positive_sign:      \t\"%s\"\t\t\"%s\"\n", c.positive_sign,     native.positive_sign);
    printf("negative_sign:      \t\"%s\"\t\t\"%s\"\n", c.negative_sign,     native.negative_sign);
    printf("currency_symbol:    \t\"%s\"\t\t\"%s\"\n", c.currency_symbol,   native.currency_symbol);
    printf("int_curr_symbol:    \t\"%s\"\t\t\"%s\"\n", c.int_curr_symbol,   native.int_curr_symbol);
    // char
    printf("frac_digits:        \t%hhd\t\t%hhd\n", c.frac_digits,        native.frac_digits);
    printf("p_cs_precedes:      \t%hhd\t\t%hhd\n", c.p_cs_precedes,      native.p_cs_precedes);
    printf("n_cs_precedes:      \t%hhd\t\t%hhd\n", c.n_cs_precedes,      native.n_cs_precedes);
    printf("p_sep_by_space:     \t%hhd\t\t%hhd\n", c.p_sep_by_space,     native.p_sep_by_space);
    printf("n_sep_by_space:     \t%hhd\t\t%hhd\n", c.n_sep_by_space,     native.n_sep_by_space);
    printf("p_sign_posn:        \t%hhd\t\t%hhd\n", c.p_sign_posn,        native.p_sign_posn);
    printf("n_sign_posn:        \t%hhd\t\t%hhd\n", c.n_sign_posn,        native.n_sign_posn);
    printf("int_frac_digits:    \t%hhd\t\t%hhd\n", c.int_frac_digits,    native.int_frac_digits);
    printf("int_p_cs_precedes:  \t%hhd\t\t%hhd\n", c.int_p_cs_precedes,  native.int_p_cs_precedes);
    printf("int_n_cs_precedes:  \t%hhd\t\t%hhd\n", c.int_n_cs_precedes,  native.int_n_cs_precedes);
    printf("int_p_sep_by_space: \t%hhd\t\t%hhd\n", c.int_p_sep_by_space, native.int_p_sep_by_space);
    printf("int_n_sep_by_space: \t%hhd\t\t%hhd\n", c.int_n_sep_by_space, native.int_n_sep_by_space);
    printf("int_p_sign_posn:    \t%hhd\t\t%hhd\n", c.int_p_sign_posn,    native.int_p_sign_posn);
    printf("int_n_sign_posn:    \t%hhd\t\t%hhd\n", c.int_n_sign_posn,    native.int_n_sign_posn);

    setlocale(LC_ALL, "C");
    return 0;
}
