/*****************************************************
 *
 *  CSCV352 - Exercise5_4.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"

int ItemReadItems(Item items[], int maxItems, char *filename)
{
    int i = 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;

    char line[MAX_ITEM_DESCRIPTION_STRING + MAX_ITEM_NAME_STRING + 10];
    for (i = 0; i < maxItems; i++)
    {
        if (feof(fp))
        {
            return i-1;
            break;
        }
        while (fgets(line, sizeof(line), fp) != NULL)
        {
        strcpy(items[i].name, strtok(line, ","));
        strcpy(items[i].description, strtok(NULL, ","));
        i++;
        }
    }

    return i;
}

int ItemGetItemNumber(Item items[], int maxItems, char *itemName)
{
    for (int i = 0; i < maxItems; i++)
    {
        if (strcmp(itemName, items[i].name) == 0)
        {
            return i;
        }
    }

    return -1;
}