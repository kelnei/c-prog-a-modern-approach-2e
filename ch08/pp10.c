#include <stdio.h>
#include <stdlib.h>

#define LEN(a) ((int)(sizeof(a)/sizeof(a[0])))

int main(void) {
    int h, m, n, i, d, idx = 0, min = 0, dh, ah;

    int departures[] = {
         8 * 60     ,   //  8:00am
         9 * 60 + 43,   //  9:43am
        11 * 60 + 19,   // 11:19am
        12 * 60 + 47,   // 12:47am
        14 * 60     ,   //  2:00pm
        15 * 60 + 45,   //  3:45pm
        19 * 60 + 00,   //  7:00pm
        21 * 60 + 45,   //  9:45pm
    };

    int arrivals[] = {
        10 * 60 + 16,   // 10:16am
        11 * 60 + 52,   // 11:52am
        13 * 60 + 31,   //  1:31pm
        15 * 60     ,   //  3:00pm
        16 * 60 +  8,   //  4:08pm
        17 * 60 + 55,   //  5:55pm
        21 * 60 + 20,   //  9:20pm
        23 * 60 + 58,   // 11:58pm
    };

    printf("Enter a 24-hour time: ");
    if (scanf("%2d:%2d", &h, &m) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    n = h * 60 + m;

    for (i = 0; i < LEN(departures); i++) {
        d = abs(departures[i] - n); 
        if (i == 0 || d < min) {
            idx = i;
            min = d;
        }
    }

    dh = departures[idx] / 60;
    ah = arrivals[idx] / 60;

    printf("Closest departure time is %d:%.2d%cm, arriving at %d:%.2d%cm\n",
           dh > 12 ? dh - 12 : (dh == 0 ? 12 : dh),
           departures[idx] % 60,
           dh >= 12 ? 'p' : 'a',
           ah > 12 ? ah - 12 : (ah == 0 ? 12 : ah),
           arrivals[idx] % 60,
           ah >= 12 ? 'p' : 'a');


    return 0;
}
