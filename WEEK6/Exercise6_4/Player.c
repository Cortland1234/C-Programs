#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Player.h"

void PlayerInit(Player *pPlayer, int locationNumber) {

    ItemListInit(&pPlayer->items);
    pPlayer->Locations = locationNumber;
}

void PlayerAddItem(Player *pPlayer, int itemNumber) {

    ItemListAddItem(&pPlayer->items, itemNumber);
}

void PlayerRemoveItem(Player *pPlayer, int itemNumber) {

    ItemListRemoveItem(&pPlayer->items, itemNumber);
}

bool PlayerHasItem(Player *pPlayer, int itemNumber) {

    return ItemListHasItem(&pPlayer->items, itemNumber);
}