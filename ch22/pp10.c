/* Maintains a parts database (linked list version) */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    float price;
    struct part *next;
};

struct part *find_part(struct part *inventory, int number);
void clear(struct part *inventory);
void dump(const struct part *inventory);
struct part *read();
struct part *insert(struct part *inventory);
void search(struct part *inventory);
void update(struct part *inventory);
void update_price(struct part *inventory);
void print(const struct part *inventory);

/*
 * main: Prompts the user to enter an operation code,
 *       then calls a function to perform the requested
 *       action. Repeats until the user enters the
 *       command 'q'. Prints an error message if the user
 *       enters an illegal code.
 */
int main(void)
{
    struct part *inventory = NULL;
    char code;

    for (;;) {
        printf("Enter operation code: ");
        if (!scanf(" %c", &code)) {
            code = 0; // treat as illegal code
        }

        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'd': dump(inventory);
                      break;
            case 'r': clear(inventory);
                      inventory = read();
                      break;
            case 'i': inventory = insert(inventory);
                      break;
            case 's': search(inventory);
                      break;
            case 'u': update(inventory);
                      break;
            case 'c': update_price(inventory);
                      break;
            case 'p': print(inventory);
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
 *            list. Returns a pointer to part if the part
 *            number is found; otherwise, returns NULL;
 */
struct part *find_part(struct part *inventory, int number)
{
    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next)
        ;

    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

/*
 * clear: Clears the inventory and reclaims the memory.
 */
void clear(struct part *inventory)
{
    struct part *p = inventory, *q;
    
    if (p == NULL)
        return;

    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
}

/*
 * dump: Prompts the user for a filename and writes
 *       part data from inventory to the file. Truncates
 *       file if it already exists.
 */
void dump(const struct part *inventory)
{
    FILE *fp;
    struct part p = {0};
    char filename[FILENAME_MAX + 1] = {0};
    int n;

    printf("Enter file name: ");
    if (fgets(filename, FILENAME_MAX, stdin) == NULL) {
        fprintf(stderr, "invalid filename\n");
        return;
    }

    n = strlen(filename);
    if (filename[n - 1] == '\n') {
        filename[n - 1] = '\0';
        n--;
    }

    if ((fp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "unable to open %s for writing\n", filename);
        return;
    }

    while (inventory != NULL) {
        p = *inventory;
        p.next = NULL;
        fwrite(&p, offsetof(struct part, next), 1, fp); 
        inventory = inventory->next;
    }

    fclose(fp);
}

/*
 * read: Prompts the user for a filename and reads
 *       part data from the file into inventory. Sets
 *       num_parts to the number of parts read.
 */
struct part *read()
{
    struct part *inventory = NULL;  
    struct part *cur, *prev, *new_node;
    struct part p = {0};

    FILE *fp;
    char filename[FILENAME_MAX + 1] = {0};
    int n;

    printf("Enter file name: ");
    if (fgets(filename, FILENAME_MAX, stdin) == NULL) {
        fprintf(stderr, "invalid filename\n");
        return inventory;
    }

    n = strlen(filename);
    if (filename[n - 1] == '\n') {
        filename[n - 1] = '\0';
        n--;
    }

    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "unable to open %s for reading\n", filename);
        return inventory;
    }

    while(fread(&p, offsetof(struct part, next), 1, fp) == 1) {
        p.next = NULL;

        new_node = malloc(sizeof(struct part));
        if (new_node == NULL) {
            printf("Database is full; can't add more parts.\n");
            return inventory;
        }
        *new_node = p;

        for (cur = inventory, prev = NULL;
             cur != NULL && new_node->number > cur->number;
             prev = cur, cur = cur->next)
            ;

        new_node->next = cur;
        if (prev == NULL) {
            inventory = new_node;
        } else {
            prev->next = new_node;
        }
    }

    fclose(fp);

    return inventory;
}

/*
 * insert: Prompts the user for information about a new
 *         part and then inserts the part into the
 *         inventory list; the list remains sorted by
 *         part number. Prints an error message and 
 *         returns prematurely if the part already exists
 *         or space could not be allocated for the part.
 */
struct part *insert(struct part *inventory)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return inventory;
    }

    printf("Enter part number: ");
    if (!scanf("%d", &new_node->number)) {
        printf("Invalid part number.\n");
        free(new_node);
        return inventory;
    }

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;

    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return inventory;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    if(!scanf("%d", &new_node->on_hand)) {
        new_node->on_hand = 0;
    }
    printf("Enter price: $");
    if(!scanf("%f", &new_node->price)) {
        new_node->price = 0.0f;
    }

    new_node->next = cur;
    if (prev == NULL) {
        return new_node;
    } else {
        prev->next = new_node;
        return inventory;
    }
}

/*
 * search: Prompts the user to enter a part number, then
 *         looks up the part in the database. If the part
 *         exists, prints the name and quantity on hand;
 *         if not, prints an error message.
 */
void search(struct part *inventory)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    if (!scanf("%d", &number)) {
        printf("Invalid part number.\n");
        return;
    }

    p = find_part(inventory, number);

    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
        printf("Price: $%.2f\n", p->price);
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
void update(struct part *inventory)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    if (!scanf("%d", &number)) {
        printf("Invalid part number.\n");
        return;
    }

    p = find_part(inventory, number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        if (!scanf("%d", &change)) {
            printf("Invalid change amount.\n");
            return;
        }
        p->on_hand += change;
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
void update_price(struct part *inventory)
{
    int number;
    float price;
    struct part *p;

    printf("Enter part number: ");
    if (!scanf("%d", &number)) {
        printf("Invalid part number.\n");
        return;
    }

    p = find_part(inventory, number);
    if (p != NULL) {
        printf("Enter new price: $");
        if (!scanf("%f", &price)) {
            printf("Invalid price amount.\n");
            return;
        }
        p->price = price;
    } else {
        printf("Part not found.\n");
    }
}


/*
 * print: Prints a listing of all parts in the database,
 *        showing the part number, part name, and
 *        quantity on hand. Parts are printed in the
 *        order in which they were entered into the
 *        database.
 */
void print(const struct part *inventory)
{
    const struct part *p;

    printf("%-11s    %-25s    %-17s    %10s\n",
           "Part Number",
           "Part Name",
           "Quantity on Hand",
           "Price");

    for (p = inventory; p != NULL; p = p->next)
        printf(" %-10d    %-25s    %16d     %10.2f $\n",
               p->number,
               p->name,
               p->on_hand,
               p->price);
}
