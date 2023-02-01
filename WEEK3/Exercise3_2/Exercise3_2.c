/*****************************************************
 *
 *  CSCV352 - Program3_2.c
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
    float priceArray[10];
    float *pArray;
    int i;
    float currentTotal = 0;
    float currentPrice = 0;
    float taxRate;
    char userInput[100];


    printf("Hello! Please input the prices of 10 items you're buying from the store: \n");
    
        for (i = 0; i < 10; ++i)
        {
            fgets(userInput, 99, stdin);
            if (sscanf(userInput, "%f", &currentPrice) == 1)
            {
                priceArray[i] = currentPrice;

                currentTotal += currentPrice;


                ++pArray;
            }
            else
            {
                break;
            }
            
        }

    printf("You entered the following prices: \n");
    for(i = 0; i < 10; ++i)
    {
        printf("%f ", priceArray[i]);
    } 

    printf("\n");
    printf("Please input your local sales tax rate: \n");
    scanf("%f", &taxRate);

    float realTax = (taxRate / 100);
    float taxTotal = (currentTotal * realTax) + currentTotal;

    printf("Total price without tax is: %f\n", currentTotal);
    printf("Total price with tax is: %f\n", taxTotal);
    



    return 0;
}