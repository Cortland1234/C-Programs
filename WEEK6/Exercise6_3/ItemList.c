#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ItemList.h"


void ItemListInit(ItemList *pItemList) { 

    pItemList->itemCount = 0; 
}

int ItemListAddItem(ItemList *pItemList, int itemNumber) {

    int count = 0;

    if (pItemList->itemCount == MAX_ITEM_LIST) 
    {
        count = -1;
    }
    else
    {
        int index = pItemList->itemCount;
        pItemList->items[index] = itemNumber;
        pItemList->itemCount++;
        count = pItemList->itemCount;
    }
    return count;

}

int ItemListRemoveItem(ItemList *pItemList, int itemNumber) {

    for (int i = 0; i < pItemList->itemCount; i++) {
        if (pItemList->items[i] == itemNumber) {
            // if itemNumber found remove it and return true
            while (i < pItemList->itemCount - 1) {
                pItemList->items[i] = pItemList->items[i + 1];
                i++;
            }
            pItemList->itemCount--;
            return 1;
        }
    }
    return 0;
}


bool ItemListHasItem(ItemList *pItemList, int itemNumber) {

    for (int i = 0; i < pItemList->itemCount; i++) {
        if (pItemList->items[i] == itemNumber) {
            return 1;
        }
    }
    return 0;
}