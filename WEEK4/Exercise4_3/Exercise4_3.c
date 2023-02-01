/*****************************************************
 *
 *  CSCV352 - Program4_2.c
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
#define ADULT_TICKET_PRICE 39.00
#define CHILD_TICKET_PRICE 17.00
///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
int PurchaseTickets(double *pRemainingCash, int adultTickets,
int childTickets);
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
    double totalCash = 0;
    double *pRemainingCash;
    int adultTickets = 0;
    int childTickets = 0;

    printf("Welcome to the Ticket Station!\n");

    printf("How much cash do you have to spend? \n");
        scanf("%lf", &totalCash);

    pRemainingCash = &totalCash;

    printf("How many adult tickets do you want to purchase? \n");
    scanf("%d", &adultTickets);

    printf("How many child tickets do you want to purchase? \n");
    scanf("%d", &childTickets);

    PurchaseTickets(pRemainingCash, adultTickets, childTickets);






    return 0;
}

/*****************************************************************
*
* Function: PurchaseTickets
*
* Parameters:
*
* pRemainingCash - points to a variable containing the
* amount of cash the user has
*
* adultTickets - specifies the number of adult tickets
* the user wants to purchase.
*
* childTickets - specifies the number of child tickets
* the user wants to purchase.
*
*
* Description:
* The function will determine if the user has enough
* money to purchase the specified number of tickets.
* If they do, then the function deducts the proper
* funds from their remaining cash and returns
* the total number of tickets purchsed. If they do not
* the function returns 0.
*
******************************************************************/
int PurchaseTickets(double *pRemainingCash, int adultTickets,
int childTickets)
{

double totalFunds = *pRemainingCash;
int ticketsPurchased = 0;
double ticketTotal = 0;
double adultTotal = 0;
double childTotal = 0;
double remain = 0;
 
adultTotal = (adultTickets * ADULT_TICKET_PRICE);
childTotal = (childTickets * CHILD_TICKET_PRICE);

ticketTotal += childTotal + adultTotal;

remain = (totalFunds - ticketTotal);

if (remain > 0)
{
    ticketsPurchased = adultTickets + childTickets;
    return printf("You have purchased {%d} tickets and you have $%.2lf remaining.", ticketsPurchased, remain);
}
else
{
    printf("Insufficient funds.");
    return 0;
}


}