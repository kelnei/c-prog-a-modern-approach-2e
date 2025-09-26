#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define N 64

int main(void)
{
    int n;
    char buf[N + 1] = {0};
    struct tm *pt;
    time_t now = time(NULL);

    pt = localtime(&now);

    n = strftime(buf, N, "%A, %B %e, %Y  %I:%M %p", pt);
    // make AM or PM just a or p
    if (n > 3) {
        buf[n - 3] = tolower(buf[n - 2]);
        buf[n - 2] = '\0';
    }
    printf("%s\n", buf);

    strftime(buf, N, "%a, %e %b %y  %R", pt);
    printf("%s\n", buf);

    strftime(buf, N, "%x  %r", pt);
    // remove zero from hour if present
    if (buf[10] == '0') {
        memmove(buf + 10, buf + 11, N - 11); 
    }
    printf("%s\n", buf);
}
