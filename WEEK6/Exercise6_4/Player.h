#ifndef PLAYER_H
#define PLAYER_H

#include "ItemList.h"

typedef struct {
    int Locations;
    ItemList items;
} Player;

void PlayerInit(Player *pPlayer, int locationNumber);

void PlayerAddItem(Player *pPlayer, int itemNumber);

void PlayerRemoveItem(Player *pPlayer, int itemNumber);

bool PlayerHasItem(Player *pPlayer, int itemNumber);

#endif