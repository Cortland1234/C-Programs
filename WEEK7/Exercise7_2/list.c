/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(ItemData item, Node * pnode);

/* interface functions */
/* set the list to empty */
void InitializeList(List * plist)
{
    
    plist->pHead = NULL;
    plist->pTail = NULL;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if (plist->pHead == NULL)
        return true;
    else
        return false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->pHead;    /* set to start of list */

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->pNext;  /* set to next node */
    }

    return count;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation) */
bool AddItem(ItemData item, List * plist)
{
    Node * pnew = plist->pTail;
    Node * scan = plist->pHead;


    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false;     /* quit function on failure */

    CopyToNode(item, pnew);
    pnew->pNext = NULL;
    if (scan == NULL)          /* empty list, so place */
        plist->pHead = pnew;         /* pnew at head of list */
    else
    {
        while (scan->pNext != NULL)
            scan = scan->pNext;  /* find end of list */
        scan->pNext = pnew;      /* add pnew to end */

    }

    return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List * plist, void(*pfun)(ItemData item))
{
    Node * pnode = plist->pHead;    /* set to start of list */

    while (pnode != NULL)
    {
        (*pfun)(pnode->itemData); /* apply function to item */
        pnode = pnode->pNext;  /* advance to next item */
    }
}

/* free memory allocated by malloc() */
/* set list pointer to NULL */
void EmptyTheList(List * plist)
{
    Node * psave;

    while (plist->pHead != NULL)
    {
        psave = (plist->pHead)->pNext; /* save address of next node */
        free(plist->pHead);           /* free current node */
        plist->pHead = psave;         /* advance to next node */
    }
}

/* local function definition */
/* copies an item into a node */
static void CopyToNode(ItemData item, Node * pnode)
{
    pnode->itemData = item;  /* structure copy */
}