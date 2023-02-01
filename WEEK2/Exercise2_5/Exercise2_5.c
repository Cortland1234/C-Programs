/*****************************************************
 *
 *  CSCV352 - Program2_5.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>


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

    float hourWage;
    float hoursPW;
    float grocery;
    float util;
    float cell;
    float other;
    float rentCost;
    float totalCost;


    printf("Enter your hourly wage: ");
    scanf("%f", &hourWage);

    printf("Enter the amount of hours worked per week: ");
    scanf("%f", &hoursPW);

    float weeklyPay = hourWage * hoursPW;                
    float extraHours = hoursPW - 40;
    float extraPay = hourWage * 1.5;
    float extraTotal = weeklyPay + (extraHours * extraPay);
    float totalPay = 0;

    if (hoursPW <= 40)
    {
        totalPay = weeklyPay;
    }
    else
    {
        totalPay = extraTotal; 
    }

    printf("Enter how much you spend on groceries per week: ");
    scanf("%f", &grocery);



    printf("Enter how much you spend on utilities per month: ");
    scanf("%f", &util);


    printf("Enter how much you spend on your cell plan per month: ");
    scanf("%f", &cell);


    printf("Enter any additional costs for the month: ");
    scanf("%f", &other);

    totalCost = grocery + util + cell + other;

    printf("How much is your rent per month? ");
    scanf("%f", &rentCost);

    printf("Total non-rent costs are %f. Total pay is %f\n", totalCost, totalPay);

    if ((totalPay - totalCost) < rentCost)
    {
        printf("You cannot pay your rent.");
    }
    else
    {
        printf("You have enough money to pay rent!");
    }



    return 0;
}