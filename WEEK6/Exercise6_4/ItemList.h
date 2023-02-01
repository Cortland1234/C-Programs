#ifndef ITEMLIST_H
#define ITEMLIST_H
#include <stdbool.h>

#define MAX_ITEM_LIST 20

typedef struct {
    int items[MAX_ITEM_LIST]; // the itemNumbers in the list
    int itemCount; // the number of items in the list
} ItemList;

void ItemListInit(ItemList *pItemList);

int ItemListAddItem(ItemList *pItemList, int itemNumber);

int ItemListRemoveItem(ItemList *pItemList, int itemNumber);

bool ItemListHasItem(ItemList *pItemList, int itemNumber);

#endif