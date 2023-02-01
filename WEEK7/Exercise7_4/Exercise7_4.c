/* petclub.c -- use a binary search tree */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

/* redefine Item as appropriate */
typedef struct item
{
    char word[50];
    int occurances;
} Item;

#define MAXITEMS 10

typedef struct node
{
    Item item;
    struct node * left;    /* pointer to right branch  */
    struct node * right;   /* pointer to left branch   */
} Node;

typedef struct tree
{
    Node * root;           /* pointer to root of tree  */
    int size;              /* number of items in tree  */
} Tree;

typedef struct pair {
    Node * parent;
    Node * child;
} Pair;

void InitializeTree(Tree * ptree);
bool TreeIsEmpty(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
int TreeItemCount(const Tree * ptree);
bool AddItem(const Item * pi, Tree * ptree);
bool InTree(const Item * pi, const Tree * ptree);
bool DeleteItem(const Item * pi, Tree * ptree);
void Traverse (const Tree * ptree, void (* pfun)(Item item));
void DeleteAll(Tree * ptree);

char menu(void);
void addwords(Tree * pt, FILE *fptr);
void showwords(const Tree * pt);
void findword(const Tree * pt);
void printitem(Item item);

/* protototypes for local functions */
static Node * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode (Node * new_node, Node * root);
static void InOrder(const Node * root, void (* pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Node **ptr);
static void DeleteAllNodes(Node * ptr);


int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("Usage: %s filename", argv[0]);
    }
    else
    {
        FILE *fp = fopen(argv[1], "r");

        if (fp == 0) 
        {
            printf("Could not open file.");
        }
        else
        {
            Tree words;
            char choice;

            InitializeTree(&words);

            addwords(&words, fp);

            fclose(fp);

            while ((choice = menu()) != 'c')
            {
                switch (choice)
                {
                    case 'a' :  showwords(&words);
                                break;
                    case 'b' :  findword(&words);
                                break;
                    default  :  puts("Switching error");
                }
            }
            DeleteAll(&words);
            puts("Shutting Down!");
        
            return 0;
        }
    }
}

char menu(void)
{
    int ch;

    puts("\nEnter the letter corresponding to your choice:\n");
    puts("a) Show list of words");
    puts("b) Find word");
    puts("c) Quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')  /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("abc",ch) == NULL)
            puts("Please enter an a, b, or c:");
        else
            break;
    }
    if (ch == EOF)       /* make EOF cause program to quit */
        ch = 'c';

    return ch;
}

void addwords(Tree * pt, FILE *fptr)
{
    Item temp;

    if (TreeIsFull(pt))
        puts("No room in the tree!");
    else
    {
        while (fscanf(fptr, "%s", temp.word) != EOF)
        {
            temp.occurances = 1;
            AddItem(&temp, pt);
        }
    }
}

void showwords(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{

    printf("Word: \"%-19s\"  Occurences: %-19d\n", item.word,
            item.occurances);
}

void findword(const Tree * pt)
{
    Item temp;
    Pair seekResult;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;     /* quit function if tree is empty */
    }

    puts("Please enter word you wish to find:");
    gets(temp.word);

    seekResult = SeekItem(&temp, pt);
    
    if (seekResult.child != NULL)
    {
        printf("\nWord \"%s\" occurred {%d} times.\n", seekResult.child->item.word, seekResult.child->item.occurances);
    }     
    else
    {
        printf("\nWord not found!\n");
    }
}

/* function definitions */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Node * new_node;
    Pair seekResult;

    if  (TreeIsFull(ptree))
    {
        fprintf(stderr,"Tree is full\n");
        return false;             /* early return           */
    }

    seekResult = SeekItem(pi, ptree);
    if (seekResult.child != NULL)
    {
        seekResult.child->item.occurances++;
        return false;             /* early return           */
    }
    new_node = MakeNode(pi);      /* points to new node     */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;             /* early return           */
    }
    /* succeeded in creating a new node */
    ptree->size++;

    if (ptree->root == NULL)      /* case 1: tree is empty  */
        ptree->root = new_node;   /* new node is tree root  */
    else                          /* case 2: not empty      */
        AddNode(new_node,ptree->root); /* add node to tree  */
   
    return true;                  /* successful return      */
}

bool InTree(const Item * pi, const Tree * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;
    
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
 
    if (look.parent == NULL)      /* delete root item       */
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse (const Tree * ptree, void (* pfun)(Item item))
{

    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}


/* local functions */
static void InOrder(const Node * root, void (* pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Node * root)
{
    Node * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode (Node * new_node, Node * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)      /* empty subtree       */
            root->left = new_node;   /* so add node here    */
        else
            AddNode(new_node, root->left);/* else process subtree*/
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else                         /* should be no duplicates */
    {
        fprintf(stderr,"location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item * i1, const Item * i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->word, i2->word)) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->word, i2->word)) > 0)
        return true;
    else
        return false;
}

static Node * MakeNode(const Item * pi)
{
    Node * new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    
    return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;                        /* early return   */
 
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else       /* must be same if not to left or right    */
            break; /* look.child is address of node with item */
    }
 
    return look;                       /* successful return   */
}

static void DeleteNode(Node **ptr)
/* ptr is address of parent member pointing to target node  */
{
    Node * temp;

    puts((*ptr)->item.word);
    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else    /* deleted node has two children */
    {
        /* find where to reattach right subtree */
        for (temp = (*ptr)->left; temp->right != NULL;
                temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr =(*ptr)->left;
        free(temp);
    }
}

    
