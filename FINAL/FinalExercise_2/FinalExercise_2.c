#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv []) 
{
    int vowelCount = 0;
    int spaceCount = 0;
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;
    int charCount = 0;
    int a;


        while ((a = getchar()) != EOF) //Getting characters until EOF detected
        {
            
            if (strchr(" ",a)) //if char is space, adds to spaceCount and charCount
            {
                spaceCount++;
                charCount++;
            }
            if (strchr("aeiou",a)) //if char is vowel, adds to vowelCount and charCount
            {
                vowelCount++;
                charCount++;
            }
            if (strchr("a",a)) //if char is a, adds to aCount and charCount
            {
                aCount++;
                charCount++;
            }
            if (strchr("e",a)) //if char is e, adds to eCount and charCount
            {
                eCount++;
                charCount++;
            }
            if (strchr("i",a)) //if char is i, adds to iCount and charCount
            {
                iCount++;
                charCount++;
            }
            if (strchr("o",a)) //if char is o, adds to oCount and charCount
            {
                oCount++;
                charCount++;
            }
            if (strchr("u",a)) //if char is u, adds to uCount and charCount
            {
                uCount++;
                charCount++;
            }
            if (a == EOF) //if a is EOF, breaks out of loop
            {
                break;
            }
            else
            {
                charCount++; //counting all characters
            }
        }

    printf("========================\nUSER INPUT REPORT:\n========================\n\n"); //printing input statistics
    printf("Number of characters: %d\n", charCount);
    printf("Number of spaces: %d\n", spaceCount);
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of \"a\" characters: %d\n", aCount);
    printf("Number of \"e\" characters: %d\n", eCount);
    printf("Number of \"i\" characters: %d\n", iCount);
    printf("Number of \"o\" characters: %d\n", oCount);
    printf("Number of \"u\" characters: %d\n", eCount);
    printf("\n========================\nEND OF REPORT, GOODBYE\n========================\n");
    return 0;
}