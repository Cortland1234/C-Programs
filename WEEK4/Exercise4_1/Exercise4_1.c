/*****************************************************
 *
 *  CSCV352 - Program4_1.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>


///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
int strend(const char *s, const char *t);
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

int main()
{
    char userInput[128];
    char userInput2[128];

    printf("Please enter a string: ");
    fgets(userInput, 128, stdin);

    printf("Please enter a second string: ");
    fgets(userInput2, 128, stdin);

    if (strend(userInput, userInput2))
    {
        printf("The string was found!");
    }
    else
    {
        printf("The string was not found!");
    }


    return 0;
}

/*****************************************************
 *
 *  Function:  strend()
 *
 *  Parameters:
 *
 *      s - parameter for first string input
 *      t - parameter for second string input
 *
******************************************************/

//I got the idea to use memcmp from this tutorial page: https://www.tutorialspoint.com/c_standard_library/c_function_memcmp.htm

int strend(const char *s, const char *t)
{
    int inputLength1 = strlen(s);
    int inputLength2 = strlen(t);

    if (inputLength2 <= inputLength1 && memcmp(t, s + inputLength1 - inputLength2, inputLength2) == 0)
    {
        return 1;
    }
    else
        return 0;


}