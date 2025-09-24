#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    float price;
};

int compare_parts(const void *p1, const void *p2)
{
    return ((struct part *)p1)->number - ((struct part *)p2)->number;
}


int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;
    struct part inventory[MAX_PARTS] = {0};
    struct part p = {0};
    int n, i;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <in.dat> <in2.dat> <out.dat>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((ifp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "unable to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // read in first file
    n = fread(inventory, sizeof(struct part), MAX_PARTS, ifp); 
    fclose(ifp);

    if ((ifp = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "unable to open %s for reading\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fread(&p, sizeof(struct part), 1, ifp) == 1) {
        for (i = 0; i < n; i++) {
            if (inventory[i].number == p.number) {
                inventory[i].on_hand += p.on_hand;
                if (strncmp(inventory[i].name, p.name, NAME_LEN) != 0) {
                    fprintf(stderr, "Part %d name mismatch: %s != %s\n",
                            inventory[i].number, inventory[i].name, p.name);
                }
                break;
            }
        }
        if (n < MAX_PARTS) {
            if (i == n) {
                inventory[n++] = p;
            }
        } else {
            fprintf(stderr, "out of parts space, skipping %d\n", p.number);
        }
    }
    fclose(ifp);

    qsort(inventory, n, sizeof(struct part), compare_parts); 

    if ((ofp = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "unable to open %s for writing\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    fwrite(inventory, sizeof(struct part), n, ofp);
    fclose(ofp);

    return 0;
}
