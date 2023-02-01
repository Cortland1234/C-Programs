#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 64

int main()
{
    char a1[MAX];
    char b1[MAX];
    char c1[MAX];

    int a,b,c,d;
    int cube;
    int squared;

    while(1)
    {
    printf("Enter an integer:\n");
    
    if (fgets(a1, MAX, stdin)) { //Getting input
        if (1 == sscanf(a1, "%d", &a)) { //Checking if user input was an integer
            
            printf("You entered: %d\n", a);
        }
        else
        {
            printf("Invalid input. Shutting down.");
            return -1; //If invalid input, program exits
        }
    }

    printf("Enter a second integer:\n");
    
    if (fgets(b1, MAX, stdin)) { //Getting input
        if (1 == sscanf(b1, "%d", &b)) { //Checking if user input was an integer
            
            printf("You entered: %d\n", b);
        }
        else
        {
            printf("Invalid input. Shutting down.");
            return -1; //If invalid input, program exits
        }
    }

    printf("Enter a third integer:\n");
    
    if (fgets(c1, MAX, stdin)) { //Getting input
        if (1 == sscanf(c1, "%d", &c)) { //Checking if user input was an integer
            
            printf("You entered: %d\n", c);
        }
        else
        {
            printf("Invalid input. Shutting down.");
            return -1; //If invalid input, program exits
        }
    }

    cube = (a * a * a); //cubed number
    squared = (b * b); //squared number
    d = cube + squared + c; //desired equation
    printf("The result is %d!\n", d);
    }
 
            
    return 0;
}