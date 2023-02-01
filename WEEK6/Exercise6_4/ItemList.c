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

    int itemIndex = -1; //finds where item number is in array

    for (int i = 0; i < pItemList->itemCount; ++i)
    {
        if (pItemList->items[i] == itemNumber)
        {
            itemIndex = i;
            break;
        }
    }

    //if the item is in list
    if (itemIndex != -1)
    {
        //shifts all of the entries down from that index
        for (int i = itemIndex; i < pItemList->itemCount-1; ++i)
        {
            pItemList->items[i] = pItemList->items[i+1];
        }
        //decrements itemCount
        --pItemList->itemCount;
    }


    return pItemList->itemCount;
}

bool ItemListHasItem(ItemList *pItemList, int itemNumber) {


    for (int i = 0; i < MAX_ITEM_LIST; ++i)
    {
        if (pItemList->items[i] == itemNumber)
        {
            return 1;
        }
    }

    return 0;
}