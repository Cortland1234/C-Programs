/*****************************************************
 *
 *  CSCV352 - Program3_3.c
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

int main()
{
char userInput;
int wordCount = 0;
float letterCount = 0;



printf("Enter input here: \n");

while ((userInput = getchar()) != EOF)
{
    if (userInput == ' ')
    {
        wordCount++;
    }
    else
    {
        letterCount++;
    }
}

float averageLetter = (letterCount / wordCount); 

printf("The number of words is: %d\n", wordCount);
printf("The average number of letters per word is: %f\n", averageLetter);

    return 0;
}

