#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEMS 16
#define MAX_ITEM_NAME_STRING 25
#define MAX_ITEM_DESCRIPTION_STRING 80

typedef struct {

    char name[MAX_ITEM_NAME_STRING];
    char description[MAX_ITEM_DESCRIPTION_STRING];
} Item;

int ItemReadItems(Item items[], int maxItems, char *filename);

int ItemGetItemNumber(Item items[], int maxItems, char *itemName);

#endif