#include <stdio.h>
#include <stdlib.h>

#define LEN(a) ((int)(sizeof(a)/sizeof(a[0])))

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

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {
    int h, m, dt, at, dh, dm, ah, am;

    printf("Enter a 24-hour time: ");
    if (scanf("%2d:%2d", &h, &m) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    find_closest_flight(h * 60 + m, &dt, &at);

    dh = dt / 60;
    dm = dt % 60;
    ah = at / 60;
    am = at % 60;

    printf("Closest departure time is %d:%.2d%cm, arriving at %d:%.2d%cm\n",
           dh > 12 ? dh - 12 : (dh == 0 ? 12 : dh),
           dm,
           dh >= 12 ? 'p' : 'a',
           ah > 12 ? ah - 12 : (ah == 0 ? 12 : ah),
           am,
           ah >= 12 ? 'p' : 'a');


    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    int i, d, idx = 0, min = 0;

    for (i = 0; i < LEN(departures); i++) {
        d = abs(departures[i] - desired_time); 
        if (i == 0 || d < min) {
            idx = i;
            min = d;
        }
    }

    *departure_time = departures[idx];
    *arrival_time = arrivals[idx];
}
