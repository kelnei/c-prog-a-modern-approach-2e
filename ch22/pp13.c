#include <stdio.h>
#include <stdlib.h>

#define LEN(a) ((int)(sizeof(a)/sizeof(a[0])))
#define DAT_FILE "flight.dat"
#define MAX_FLIGHTS 20

struct flight {
    int departure;
    int arrival;
};

static struct flight flights[MAX_FLIGHTS] = {0};
static int n = 0;

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {
    int h, m, dt, at, dh, dm, ah, am;
    FILE *fp;

    if ((fp = fopen(DAT_FILE, "r")) == NULL) {
        fprintf(stderr, "failed to open %s for reading\n", DAT_FILE);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%d:%d%d:%d", &dh, &dm, &ah, &am) == 4) {
        flights[n].departure = dh * 60 + dm;
        flights[n].arrival = ah * 60 + am;
        n++;
    }
    fclose(fp);

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

    for (i = 0; i < n; i++) {
        d = abs(flights[i].departure - desired_time);
        if (i == 0 || d < min) {
            idx = i;
            min = d;
        }
    }

    *departure_time = flights[idx].departure;
    *arrival_time = flights[idx].arrival;
}
