#ifndef GAME_H
#define GAME_H

#include "ItemList.h"
#include "Location.h"
#include "Player.h"
#include "Item.h"

#define MAX_ITEM_COUNT 20
#define MAX_MAP_LOCATIONS 25
#define MAX_ITEM_NAME_STRING 25
#define MAX_ITEM_DESCRIPTION_STRING 80
#define MAX_LOC_NAME_STRING 25
#define MAX_LOC_DESCRIPTION_STRING 250

typedef struct {
    int numLocations;
    Location map[MAX_MAP_LOCATIONS];
    int itemCount;
    Item items[MAX_ITEM_COUNT];
    Player player;
} Game;

int GameInitialize(Game *pGame);

#endif