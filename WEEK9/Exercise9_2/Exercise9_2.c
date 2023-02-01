/*****************************************************
 *
 *  Cortland Diehm - Exercise9_2
 *
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////
#define LINE_SIZE 128
#define MAX_WORD 30

typedef struct _linkedListNode {
char word[MAX_WORD];
struct _node *pNext;
} LinkedListNode;

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
void PrintList(LinkedListNode * pLinkedList);
LinkedListNode *AddSortedNode(LinkedListNode *pLinkedList, char *word);

/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char *argv[]) 
{
    LinkedListNode *pLinkedList;
    char aline[LINE_SIZE];
    char word[MAX_WORD];
    FILE *pFile;

    if (argc < 2)
    {
        printf("Usage: \nProgram {filename}\n");
        exit(1);
    }

    if ( (pFile = fopen(argv[1], "r")) != NULL)
    {
        while (!feof(pFile))
        {
            if (fgets(aline, LINE_SIZE, pFile) != NULL)
            {
                sscanf(aline, "%s", word);
                pLinkedList = AddSortedNode(pLinkedList, word);
            }
        }
        fclose(pFile);
    }

    PrintList(pLinkedList);

    return 0;
}

void PrintList(LinkedListNode *pPrintList)
{
    while (pPrintList != NULL)
    {
        printf("%s\n", pPrintList->word);
        pPrintList = pPrintList->pNext;
    }
}

LinkedListNode *AddSortedNode(LinkedListNode *pLinkedList, char *word)
{
    LinkedListNode *pNewNode = NULL;
    LinkedListNode *pCurNode = NULL;
    LinkedListNode *pPrevNode = NULL;

    pNewNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    if (pNewNode == NULL)
    {
        printf("Critical memory error\n");
        exit(0);
    }

    strcpy(pNewNode->word, word);
    pNewNode->pNext = NULL;


    if (pLinkedList == NULL)
    {
        pLinkedList = pNewNode;
    }
    else
    {
        pCurNode = pLinkedList;
        while (pCurNode != NULL)
        {
            int compareResult;
            if ((compareResult = strcmp(pCurNode->word, pNewNode->word)) >= 0)
            {
                break;
            }
            else
            {
                pPrevNode = pCurNode;
                pCurNode = pCurNode->pNext;
            }
        }
    }

    pNewNode->pNext = pCurNode;
    if (pPrevNode == NULL)
    {
        pLinkedList = pNewNode;
    }
    else
    {
        pPrevNode->pNext = pNewNode;
     }
    
    return pLinkedList;
}