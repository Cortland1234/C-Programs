#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//============================================================
//CONSTANTS
//============================================================

#define MAX_NAME 128
#define MAX_DATE 64
#define MAX_EMAIL_ADDRESS 128
#define MAX_RECORDS  30

//============================================================
//STRUCT PROTOTYPES
//============================================================
typedef struct __attribute__((packed, aligned(1))) employee_data {
int employeeId;
char firstName[MAX_NAME];
char lastName[MAX_NAME];
char middleName[MAX_NAME];
char emailAddress[MAX_EMAIL_ADDRESS];
char title[MAX_EMAIL_ADDRESS];
float annualSalary;
char dataOfHire[MAX_DATE];
struct employee_data *pNext;
} EmployeeInformation;
 
//============================================================
//FUNCTION PROTOTYPES
//============================================================
EmployeeInformation *GetNode();
EmployeeInformation *PopulateSortedList(EmployeeInformation *EmployeeList, int numEntries);
void PrintList(EmployeeInformation *pListToPrint);
void ReleaseNode(EmployeeInformation *pNode);
int RemoveEmployee(EmployeeInformation *pEmployeeList, int employeeId);
int EditSalary(EmployeeInformation *pEmployeeList, int employeeId, double salary);
int DisplayEmployee(EmployeeInformation *pEmployeeList, int employeeId);
bool isPresent(EmployeeInformation *pEmployeeList, int employeeId);
char menu(void);

EmployeeInformation allRecords[MAX_RECORDS];

int main(int argc, char *argv[])
{

    FILE *fp;
    EmployeeInformation *employeeData;
    EmployeeInformation *pEmployeeList;

    char idInput[6];
    char salInput[20];
    int id;
    double sal;
    char choice;

    int employeeCount = 0;
    int i = 0;

    if (argc < 2) //Checking File existence, exits if invalid
    {
        printf("ERROR. Invalid or missing arguments."); 
    }
    else
    {

        fp = fopen(argv[1], "rb");  
        if (fp == NULL)
        {
            printf("Invalid file.");
            exit(0);
        }
        else
        {
            EmployeeInformation employeeRecord;

            fseek(fp, 0, SEEK_END);
            employeeCount = ((int)ftell(fp) / sizeof(EmployeeInformation)) + 1; //Dividing contents of fp by the size of struct
            employeeData = malloc(sizeof(EmployeeInformation) * employeeCount); //Allocating memory for list
            if (employeeData == NULL)
            {
                printf("EMPTY");
                return -1;
            }
            
            fseek(fp, 0, SEEK_SET); 

            employeeCount = 0;
            while (fread(&employeeRecord, sizeof(EmployeeInformation) - sizeof(struct employee_data *), 1, fp) == 1) //Reading in data
            {
                employeeData[i++] = employeeRecord;
                ++employeeCount;
            }

            pEmployeeList = PopulateSortedList(employeeData, employeeCount); //Creating sorted list

            fclose(fp);

            //MENU FOR USER

            while ((choice = menu()) != 'e')
            {
                switch (choice)
                {
                    case 'a' :  PrintList(pEmployeeList);
                                break;
                    case 'b' :  printf("Please enter Employee ID: \n");
                                if (fgets(idInput, 6, stdin)) 
                                {
                                    if (1 == sscanf(idInput, "%d", &id)) //checking if input is an integer
                                    {
                                        if (DisplayEmployee(pEmployeeList, id) == 0) //checking return value of DisplayEmployee()
                                        {
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        printf("INVALID ID.\n");
                                    }
                                }
                                break;
                    case 'c' :  printf("Please enter Employee ID: \n");
                                if (fgets(idInput, 6, stdin)) 
                                {
                                    if (1 == sscanf(idInput, "%d", &id)) //checking if input is an integer
                                    {
                                        if (RemoveEmployee(pEmployeeList, id) == 0) //checking return value of RemoveEmployee()
                                        {
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        printf("INVALID ID.\n");
                                    }
                                }
                                break;
                    case 'd' :  printf("Please enter Employee ID: \n");
                                if (fgets(idInput, 6, stdin)) 
                                {
                                    if (1 == sscanf(idInput, "%d", &id)) //checking if input is an integer
                                    {
                                        if (isPresent(pEmployeeList, id) == false) //checking return value of isPresent()
                                        {
                                            break;
                                        }
                                        printf("Please enter the desired salary: \n");
                                        if (fgets(salInput, 6, stdin)) 
                                        {
                                            if (1 == sscanf(salInput, "%lf", &sal)) //checking if input is double
                                            {    
                                                if (EditSalary(pEmployeeList, id, sal) == 0) //checking EditSalary() return value
                                                {
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                printf("INVALID SALARY INPUT!\n");
                                                break;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        printf("INVALID ID.\n");
                                    }
                                }
                                break;
                    default  :  puts("Switching error");
                }
            }

        }
    }

    return 0;

}


char menu(void) //Menu function to check for valid input and printing the options display
{
    int ch;

    puts("\nEnter the letter corresponding to your choice:\n");
    puts("a) Display all Employees");
    puts("b) Find Employee");
    puts("c) Remove Employee");
    puts("d) Edit Employee Salary");
    puts("e) Quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')  /* discard rest of line */
            continue;
        if (strchr("abcde",ch) == NULL)
            puts("Please enter a valid choice (a, b, c, d, or e)");
        else
            break;
    }
    if (ch == EOF)       /* make EOF cause program to quit */
        ch = 'e';

    return ch;
}

EmployeeInformation *GetNode() //Function that gets empty node for list
{
    EmployeeInformation *pEmptyNode = NULL;
    int i = 0;

    while (i < MAX_RECORDS)
    {
        if (strlen(allRecords[i].lastName) == 0)
        {
            pEmptyNode = &allRecords[i];
            break;
        }
        ++i;
    }
    return pEmptyNode;
}

EmployeeInformation *PopulateSortedList(EmployeeInformation *EmployeeList, int numEntries) //Function that populates a sorted linked list from file data
{
    EmployeeInformation *pListHead=NULL;
	EmployeeInformation *pListTail=NULL;
	EmployeeInformation *pNewNode=NULL;
	EmployeeInformation *pCurNode=NULL;
	EmployeeInformation *pPrevNode=NULL;

    for (int i = 0; i < numEntries; ++i)
	{
		//Allocate memory for the new node 
		pNewNode = GetNode(numEntries);
		if (pNewNode == NULL)
		{
			printf("Critical memory error\n");
			exit(0);
		}

        pNewNode->employeeId = EmployeeList[i].employeeId;
        strcpy(pNewNode->firstName, EmployeeList[i].firstName); //Copying information into new node
		strcpy(pNewNode->lastName, EmployeeList[i].lastName);
		strcpy(pNewNode->middleName, EmployeeList[i].middleName);
		strcpy(pNewNode->emailAddress, EmployeeList[i].emailAddress);
        strcpy(pNewNode->title, EmployeeList[i].title);
        pNewNode->annualSalary = EmployeeList[i].annualSalary;
		strcpy(pNewNode->dataOfHire, EmployeeList[i].dataOfHire);
		pNewNode->pNext =  NULL;  // pNext set to NULL

		if (pListHead == NULL)
		{
            pListTail = pListHead = pNewNode;
		}
		else
		{
            pCurNode = pListHead;

            while (pCurNode != NULL)
            {
                //Compares the records to see if this is the place to insert into list
                if (pCurNode->employeeId > pNewNode->employeeId)
                {
                    break;
                }
                else
                {
                    pPrevNode = pCurNode;
                    pCurNode = pCurNode->pNext;
                }
            }

            pNewNode->pNext = pCurNode;

            if (pPrevNode == NULL)
            {
                //Insert at beginning
                pListHead = pNewNode;
            }
            else
            {
                pPrevNode->pNext = pNewNode;
            }
		}
	}

	return pListHead;
}        

void PrintList(EmployeeInformation *pListToPrint) //Function that prints list from parameter
{
	while (pListToPrint != NULL)
	{
        printf("Employee ID: %d\n", pListToPrint->employeeId);
	    printf("Employee Name: %s %s %s\n", pListToPrint->firstName, pListToPrint->lastName, pListToPrint->middleName);
	    printf("Email Address: %s\n", pListToPrint->emailAddress);
        printf("Title: 	       %s\n", pListToPrint->title);
		printf("Salary:        %.2lf\n", pListToPrint->annualSalary);
        printf("Date of Hire:  %s\n", pListToPrint->dataOfHire);
		printf("------------------------------------------------------------\n");
        pListToPrint = pListToPrint->pNext; //Go to next node
	}
}

void ReleaseNode(EmployeeInformation *pNode)
{
    //Makes sure the node reports as empty
    memset(pNode, 0, sizeof(EmployeeInformation));
}

int RemoveEmployee(EmployeeInformation *pEmployeeList, int employeeId)
{
	EmployeeInformation *pCurNode=NULL;
	EmployeeInformation *pPrevNode=NULL;

    if (pEmployeeList != NULL)
    {
        //Start at the beginning of the list
        pCurNode = pEmployeeList;
        while (pCurNode != NULL)
        {
            int compareResult;
            //If ID is found, break the loop
            if (compareResult = pCurNode->employeeId == employeeId)
            {
                break;
            }
            if (pCurNode->pNext == NULL)
            {
                printf("INVALID ID.\n");
                return 0;
            }
            else
            {
                pPrevNode = pCurNode;
                //Move to the next node
                pCurNode = pCurNode->pNext;
            }
        }

        if (pPrevNode == NULL)
        {
            //Insert at the beginning of the list
            pEmployeeList = pCurNode->pNext;
        }
        else
        {
            pPrevNode->pNext = pCurNode->pNext;
        }

        //Set the record in the array as empty
        ReleaseNode(pCurNode);
        printf("EMPLOYEE %d HAS BEEN REMOVED!\n", employeeId);
    }
    return 1;
}

int EditSalary(EmployeeInformation *pEmployeeList, int employeeId, double salary) //Function that finds employee record and allows for user to change salary
{
	EmployeeInformation *pCurNode=NULL;
    EmployeeInformation *pPrevNode=NULL;

    if (pEmployeeList != NULL)
    {
        //Start at the beginning of the list
        pCurNode = pEmployeeList;
        while (pCurNode != NULL)
        {
            int compareResult;
            //If we found the ID, break the loop
            if (compareResult = pCurNode->employeeId == employeeId)
            {
                break;
            }
            if (pCurNode->pNext == NULL)
            {
                printf("INVALID ID.\n");
                return 0;
            }
            else
            {
                pPrevNode = pCurNode;
                //Move to the next node
                pCurNode = pCurNode->pNext;
            }
        }

        pCurNode->annualSalary = salary; //Change the desired node's salary
        printf("SALARY CHANGED!\n\n");
        return 1;
    }
}

int DisplayEmployee(EmployeeInformation *pEmployeeList, int employeeId) //Function that displays employee record by ID
{
    EmployeeInformation *pCurNode=NULL;
    EmployeeInformation *pPrevNode=NULL;

    if (pEmployeeList != NULL)
    {
        // start at the beginning of the list
        pCurNode = pEmployeeList;
        while (pCurNode != NULL)
        {
            int compareResult;
            // if we found the ID, break the loop
            if (compareResult = pCurNode->employeeId == employeeId) 
            {
                break;
            }
            if (pCurNode->pNext == NULL)
            {
                printf("INVALID ID.\n");
                return 0;
            }
            else
            {
                pPrevNode = pCurNode;
                // move to the next node
                pCurNode = pCurNode->pNext;
            }

        }
        //Printing desired employee data
        printf("------------------------------------------------------------\n");
        printf("\n\nEmployee ID: %d\n", pCurNode->employeeId);
	    printf("Employee Name: %s %s %s\n", pCurNode->firstName, pCurNode->lastName, pCurNode->middleName);
	    printf("Email Address: %s\n", pCurNode->emailAddress);
        printf("Title: 	       %s\n", pCurNode->title);
		printf("Salary:        %.2lf\n", pCurNode->annualSalary);
        printf("Date of Hire:  %s\n", pCurNode->dataOfHire);
		printf("------------------------------------------------------------\n");

        return 1;
    }
}

bool isPresent(EmployeeInformation *pEmployeeList, int employeeId) //Function that checks list for certain ID; returns true if found, false if not
{
    EmployeeInformation *pCurNode=NULL;
    EmployeeInformation *pPrevNode=NULL;

    if (pEmployeeList != NULL)
    {
        // start at the beginning of the list
        pCurNode = pEmployeeList;
        while (pCurNode != NULL)
        {
            int compareResult;
            // if we found the ID, break the loop
            if (compareResult = pCurNode->employeeId == employeeId)
            {
                break;
            }
            if (pCurNode->pNext == NULL)
            {
                printf("INVALID ID.\n");
                return false;
            }
            else
            {
                pPrevNode = pCurNode;
                // move to the next node
                pCurNode = pCurNode->pNext;
            }
        }
        return true;
    }
}