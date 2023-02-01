#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2) 
    {
        printf("Usage: %s (float)\n", argv[0]);
    }
    else
    {
        double input = atof(argv[1]);
        double answer = sqrt(input);

        printf("The Square Root of %.2lf is %.2lf.\n\nShutting Down!\n", input, answer);
    }

    return 0;
}