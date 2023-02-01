#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Location.h"


int LocationReadMap(Location map[], int maxLocations, char *filename) {

    int i = 0; 
    int north =0;
    int east=0;
    int south=0;
    int west=0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;

    char line[MAX_LOC_DESCRIPTION_STRING + MAX_LOC_NAME_STRING];
    for (i = 0; i < maxLocations; ++i)
    {
        if (feof(fp))
        {
            return i-1;
            break;
        }
        else
        {
            while (fgets(line, sizeof(line), fp) != NULL)
            {
            north = atoi(strtok(line, ","));
            map[i].north = north;
            east = atoi(strtok(NULL, ","));
            map[i].east = east;
            south = atoi(strtok(NULL, ","));
            map[i].south = south;
            west = atoi(strtok(NULL, ","));
            map[i].west = west;

            strcpy(map[i].name, strtok(NULL, ","));
            strcpy(map[i].description, strtok(NULL, "\""));
            ++i;
            }
        }
    }
    
    return i;

}

void LocationAddItem(Location *pLocation, int itemNumber) {

    ItemListAddItem(&pLocation->items, itemNumber);
}

void LocationRemoveItem(Location *pLocation, int itemNumber) {

    ItemListRemoveItem(&pLocation->items, itemNumber);
}

bool LocationHasItem(Location *pLocation, int itemNumber) {

    return ItemListHasItem(&pLocation->items, itemNumber);
}