/*****************************************************
 *
 *  Cortland Diehm - Exercise10_3
 *
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
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

#define MAX_WORDS  100
LinkedListNode allNodes[MAX_WORDS];

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
char menu(void);
void PrintList(LinkedListNode * pLinkedList);
LinkedListNode *AddSortedNode(LinkedListNode *pLinkedList, char *word);
int RemoveNode(LinkedListNode *pLinkedList, char *word);
LinkedListNode *GetNode();
void ReleaseNode(LinkedListNode *pNode);
int FindNode(LinkedListNode *pLinkedList, char *word);


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

    memset(allNodes, 0, sizeof(allNodes));

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

    char choice;
    while ((choice = menu()) != 'e')
    {
        switch (choice)
        {
            case 'a' :  PrintList(pLinkedList);
                        break;

            case 'b' :  printf("Input word you would like to check for:\n");
                        gets(word);
                        if ( FindNode(pLinkedList, word) == 1)
                        {
                            printf("That word IS in the list!\n");
                        }
                        else
                        {
                            printf("That word is NOT in the list.\n");
                        }
                        
                        break;

            case 'c' :  printf("Input word you would like to add:\n");
                        gets(word);
                        pLinkedList = AddSortedNode(pLinkedList, word);
                        break;

            case 'd' :  printf("Input word you would like to remove:\n");
                        gets(word);
                        RemoveNode(pLinkedList, word);
                        break;
                        
            default  :  puts("Switching error\n");
        }
    }

    return 0;
}

char menu(void)
{
    int ch;

    puts("\nEnter the letter corresponding to your choice:\n");
    puts("a) Show list of words");
    puts("b) Find word");
    puts("c) Add Word");
    puts("d) Remove Word");
    puts("e) Quit\n");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')  /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("abcde",ch) == NULL)
            puts("Please enter a, b, c, d, or e:\n");
        else
            break;
    }
    if (ch == EOF)       /* make EOF cause program to quit */
        ch = 'e';

    return ch;
}

void PrintList(LinkedListNode *pPrintList)
{
    while (pPrintList != NULL)
    {
        printf("%s\n", pPrintList->word);
        pPrintList = pPrintList->pNext;
    }
}

LinkedListNode *GetNode()
{
    LinkedListNode *pEmptyNode = NULL;
    int i = 0;

    while (i < MAX_WORDS)
    {
        if (strlen(allNodes[i].word) == 0)
        {
            pEmptyNode = &allNodes[i];
            break;
        }
        ++i;
    }
    return pEmptyNode;
}

void ReleaseNode(LinkedListNode *pNode)
{ 
    // makes sure the node reports as empty
    memset(pNode, 0, sizeof(LinkedListNode));
}

LinkedListNode *AddSortedNode(LinkedListNode *pLinkedList, char *word)
{
    LinkedListNode *pNewNode = NULL;
    LinkedListNode *pCurNode = NULL;
    LinkedListNode *pPrevNode = NULL;

    pNewNode = GetNode();
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

int RemoveNode(LinkedListNode *pLinkedList, char *word)
{
    int retVal = 0;
	LinkedListNode *pCurNode=NULL;
	LinkedListNode *pPrevNode=NULL;

    if (pLinkedList != NULL)
    {
        // start at the beginning of the list
        pCurNode = pLinkedList;
        while (pCurNode != NULL)
        {
            int compareResult;
            // if we found the last name, break the loop
            if ((compareResult = strcmp(pCurNode->word, word)) == 0)
            {
                break;
            }
            else
            {
                pPrevNode = pCurNode;
                // move to the next node
                pCurNode = pCurNode->pNext;
            }
        }

        // we have the node remove 
        if (pPrevNode == NULL)
        {
            // insert at the beginning of the list
            pLinkedList = pCurNode->pNext;
        }
        else
        {
            pPrevNode->pNext = pCurNode->pNext;
        }

        // set the record in the array as empty
        ReleaseNode(pCurNode);
    }
    return retVal;
}

int FindNode(LinkedListNode *pLinkedList, char *word)
{
    int retVal = 0;
	LinkedListNode *pCurNode=NULL;
	LinkedListNode *pPrevNode=NULL;

    if (pLinkedList != NULL)
    {
        // start at the beginning of the list
        pCurNode = pLinkedList;
        while (pCurNode != NULL)
        {
            int compareResult;
            // if we found the word, break the loop
            if ((compareResult = strcmp(pCurNode->word, word)) == 0)
            {
                retVal = 1;
                break;
            }
            else
            {
                pPrevNode = pCurNode;
                // move to the next node
                pCurNode = pCurNode->pNext;
            }
        }

        return retVal;
    }
}