/* Maintains a parts database (array version) */

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

int find_part(const struct part *inventory, int num_parts, int number);
void insert(struct part *inventory, int *num_parts);
void search(const struct part *inventory, int num_parts);
void update(struct part *inventory, int num_parts);
void update_price(struct part *inventory, int num_parts);
void print(struct part *inventory, int num_parts);

/*
 * main: Prompts the user to enter an operation code,
 *       then calls a function to perform the requested
 *       action. Repeats until the user enters the
 *       command 'q'. Prints an error message if the user
 *       enters an illegal code.
 */
int main(void)
{
    struct part inventory[MAX_PARTS] = {0};
    int num_parts = 0;
    char code;

    for (;;) {
        printf("Enter operation code: ");
        if (!scanf(" %c", &code)) {
            code = 0; // treat as illegal code
        }

        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert(inventory, &num_parts);
                      break;
            case 's': search(inventory, num_parts);
                      break;
            case 'u': update(inventory, num_parts);
                      break;
            case 'c': update_price(inventory, num_parts);
                      break;
            case 'p': print(inventory, num_parts);
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }

    return 0;
}

/* 
 * find_part: Looks up a part number in the inventory
 *            array. Returns the array index if the part
 *            number is found; otherwise, returns -1;
 */
int find_part(const struct part *inventory, int num_parts, int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

/*
 * insert: Prompts the user for information about a new
 *         part and then inserts the part into the
 *         database. Prints an error message and returns
 *         prematurely if the part already exists or the
 *         database is full.
 */
void insert(struct part *inventory, int *num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    if (!scanf("%d", &part_number)) {
        printf("Invalid part number.\n");
        return;
    }

    if (find_part(inventory, *num_parts, part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    if(!scanf("%d", &inventory[*num_parts].on_hand)) {
        inventory[*num_parts].on_hand = 0;
    }
    printf("Enter price: $");
    if(!scanf("%f", &inventory[*num_parts].price)) {
        inventory[*num_parts].price = 0.0f;
    }
    (*num_parts)++;
}

/*
 * search: Prompts the user to enter a part number, then
 *         looks up the part in the database. If the part
 *         exists, prints the name and quantity on hand;
 *         if not, prints an error message.
 */
void search(const struct part *inventory, int num_parts)
{
    int i, part_number;

    printf("Enter part number: ");
    if (!scanf("%d", &part_number)) {
        printf("Invalid part number.\n");
        return;
    }

    i = find_part(inventory, num_parts, part_number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: $%.2f\n", inventory[i].price);
    } else {
        printf("Part not found.\n");
    }
}

/*
 * update: Prompts the user to enter a part number.
 *         Prints an error message if the part doesn't
 *         exit; otherwise, prompts the user to enter
 *         change in quantity on hand and updates the
 *         database.
 */
void update(struct part *inventory, int num_parts)
{
    int i, part_number, change;

    printf("Enter part number: ");
    if (!scanf("%d", &part_number)) {
        printf("Invalid part number.\n");
        return;
    }

    i = find_part(inventory, num_parts, part_number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        if (!scanf("%d", &change)) {
            printf("Invalid change amount.\n");
            return;
        }
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

/*
 * update_price: Prompts the user to enter a part number.
 *               Prints an error message if the part doesn't
 *               exit; otherwise, prompts the user to enter
 *               a new price and updates the database.
 */
void update_price(struct part *inventory, int num_parts)
{
    int i, part_number;
    float price;

    printf("Enter part number: ");
    if (!scanf("%d", &part_number)) {
        printf("Invalid part number.\n");
        return;
    }

    i = find_part(inventory, num_parts, part_number);
    if (i >= 0) {
        printf("Enter new price: $");
        if (!scanf("%f", &price)) {
            printf("Invalid price amount.\n");
            return;
        }
        inventory[i].price = price;
    } else {
        printf("Part not found.\n");
    }
}

int compare_parts(const void *p1, const void* p2)
{
    return ((struct part *)p1)->number - ((struct part *)p2)->number;
}

/*
 * print: Prints a listing of all parts in the database,
 *        showing the part number, part name, and
 *        quantity on hand. Parts are printed in the
 *        order in which they were entered into the
 *        database.
 */
void print(struct part *inventory, int num_parts)
{
    int i;

    qsort(inventory, num_parts, sizeof(struct part), compare_parts);

    printf("%-11s    %-25s    %-17s    %10s\n",
           "Part Number",
           "Part Name",
           "Quantity on Hand",
           "Price");

    for (i = 0; i < num_parts; i++)
        printf(" %-10d    %-25s    %16d     %10.2f $\n",
               inventory[i].number,
               inventory[i].name,
               inventory[i].on_hand,
               inventory[i].price);
}

