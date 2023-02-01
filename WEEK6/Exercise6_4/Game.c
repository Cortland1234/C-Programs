#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Game.h"

int GameInitialize(Game *pGame) {

    int playerStart;

    //Read in all items
    pGame->itemCount = ItemReadItems(&pGame->items, MAX_ITEM_COUNT, "items.txt");

    // Read in all locations

    pGame->numLocations = LocationReadMap(&pGame->map, MAX_MAP_LOCATIONS, "map.txt");


    //Initialize Player
    srand(clock());
    playerStart = rand() % pGame->numLocations;

    PlayerInit(&pGame->player, playerStart);
    
    
    // distribute all items across map

    for (int i = 0; i < pGame->itemCount; ++i)
    {
        int randomLoc;
        Location *pLocForItem;

        randomLoc = rand() % pGame->numLocations;

        //Gets pointer to the rand location
        pLocForItem = &pGame->map[randomLoc];

        LocationAddItem(pLocForItem, i);
    }

    return 0;
}