/*****************************************************
 *
 *  CSCV352 - Program2_3.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
float cm = 0;
float inches = 0;
int feet = 0;
int counter = 0;
int cmRead;


do {
printf("Enter a height in centimers (0 to quit): ");
cmRead =scanf("%f", &cm);
if (cmRead != 1)
{
    printf("Invalid integer. Shutting down...");
    exit(0);
} 
if (cm == 0) {
    printf("Input '0' detected. Shutting down...");
    exit(0);
}
if (cm < 0){
    counter++;
    printf("Invalid integer. Shutting down...");
}
else {

feet = (cm / 2.54) / 12;
inches = (cm / 2.54) - (feet * 12);

printf("%.1f cm =  %d feet, %.1f inches\n", cm, feet, inches);
}

} while (counter != 1);


return 0;
}