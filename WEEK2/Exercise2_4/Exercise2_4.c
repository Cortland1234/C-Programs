/*****************************************************
 *
 *  CSCV352 - Program2_4.c
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

int main(int argc, char *argv[]) 
{
   double fArray[7];
   double totalArray[7]; 
   double *pArray;
   int i;
   double currentTotal = 0;
   double currentValue;
   

   pArray = fArray;

   printf("Input elements for your array: ");

   for(i = 0; i < 7; ++i)
   {

	   scanf("%lf", &currentValue);

       fArray[i] = currentValue;

       currentTotal = currentTotal + currentValue;

       totalArray[i] = currentTotal;
      
      // move to the next entry in the array
      ++pArray;
   }

   printf("Displaying Cumulative Array\n");

   for(i = 0; i < 7; ++i)
   {
   printf("%lf ", fArray[i]);
   } 

   printf("\n");
   
   for(i = 0; i < 7; ++i)
   {
       printf("%lf ", totalArray[i]);
   }

   return 0;
}