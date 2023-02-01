#ifndef LOCATION_H
#define LOCATION_H

#define MAX_LOC_NAME_STRING 25
#define MAX_LOC_DESCRIPTION_STRING 250
#include "ItemList.h"

typedef struct {
    char name[MAX_LOC_NAME_STRING];
    char description[MAX_LOC_DESCRIPTION_STRING];
    int north; // index of location to the north
    int east; // index of location to the east
    int south; // index of location to the south
    int west; // index of location to the west
    ItemList items; // items in this location
} Location;

int LocationReadMap(Location map[], int maxLocations, char *filename);

void LocationAddItem(Location *pLocation, int itemNumber);

void LocationRemoveItem(Location *pLocation, int itemNumber);

bool LocationHasItem(Location *pLocation, int itemNumber);


#endif

