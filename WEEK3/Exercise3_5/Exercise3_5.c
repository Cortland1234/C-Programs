/*****************************************************
 *
 *  CSCV352 - Program3_5.c
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

int alphaLocation(char letter)
    {
    int alphaLocation;
    if (isalpha(letter))
        {
        alphaLocation=(int)letter;
        if (letter > 64 && letter < 91)
            {
            printf("Your input was a letter! Location of '%c' is ", letter);
            return alphaLocation - 64;
            }
        else
        {
            printf("Your input was a letter! Location of '%c' is ", letter);
            return alphaLocation - 96;
        }
        }
    else
    {
        printf("Your input '%c' was not a letter! ", letter);    
        return -1;
    }
    }


int main()
{
char letter;


printf("Input your string here: \n");

while ((letter = getchar())!= EOF)
{
    if (letter == '\n')
    {
        continue;
    }
    else
    {
    printf("%d\n", alphaLocation(letter));
    }

}

    return 0;
}