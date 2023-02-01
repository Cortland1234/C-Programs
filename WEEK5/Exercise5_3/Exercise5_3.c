/*****************************************************
 *
 *  CSCV352 - Program5_3.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////
#define MAX_NAME 64
#define MAX_EMAIL_ADDRESS 128
///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////
typedef struct {
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    char middleName[MAX_NAME];
    char emailAddress[MAX_EMAIL_ADDRESS];
    int grade; // on a 100% scale
} StudentInformation;
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

    FILE *fp;
    StudentInformation stuInfo[10];
    int gradeTotal = 0;
    float avgGrade = 0;
    int i;

    if (argc != 2)
    {
        printf("ERROR. Invalid or missing arguments."); 
    }
    else{

    fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        printf("Invalid file.");
        exit(0);
    }
    else
    {
        i = 0;
        while (fread(&stuInfo[i++], sizeof(StudentInformation), 1, fp) == 1);

        fclose(fp);
    }
    printf("\n\n%-20s %-20s %-30s %-20s\n", "Last Name", "First Name", "Email", "Grade");
    printf("---------------------------------------------------------------------------------\n");

    for (i=0; i < 10; ++i)
    {
        gradeTotal += stuInfo[i].grade;
        printf("%-20s %-20s %-30s %-20d\n", stuInfo[i].lastName, stuInfo[i].firstName, stuInfo[i].emailAddress, stuInfo[i].grade);
    }

    avgGrade = (gradeTotal / 10);

    printf("Class Average: %.1f\n", avgGrade);
    
    }

    return 0;
}