/*****************************************************
 *
 *  CSCV352 - Exercise4_4.c
 *
 *  Student:  <Student's Name>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <stdint.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////
#define CWR 128
#define ECE 64
#define URG 32
#define ACK 16
#define PSH 8
#define RST 4
#define SYN 2
#define FIN 1
///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
void DumpHex(const void* data, size_t size, int width);

int DisplayTCPSegment(unsigned char *pSegment, int segmentLen);


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
	unsigned char segmentBuffer[1500];
    int bytesRead;
	unsigned char *pSegment = segmentBuffer;

    // Read the TCP segment from stdin
    bytesRead = fread(segmentBuffer, 1, 1500, stdin);

    // Uncomment this line to dump the packet to the console
    DumpHex(segmentBuffer, bytesRead, 16);
	printf("\n");




    // ADD YOUR CALL TO DisplayTCPSegment() HERE
	DisplayTCPSegment(pSegment, bytesRead);

    return 0;

}

/*******************************************************************
 * 
 *   DumpHex()
 * 
 *   Formatted output of raw data.
 * 
*******************************************************************/
void DumpHex(const void* data, size_t size, int width) 
{
	char ascii[17];
	size_t i, j;

	ascii[width] = '\0';
	for (i = 0; i < size; ++i) 
    {
        // Print the value
		printf("%02X ", ((unsigned char*)data)[i]);

        // save the ascii display value in the relative position
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') 
        {
			ascii[i % width] = ((unsigned char*)data)[i];
		} 
        else 
        {
			ascii[i % width] = '.';
		}


		if ((i+1) % (width / 2) == 0 || i+1 == size) 
        {
			printf(" ");
			if ((i+1) % width == 0) 
            {
				printf("|  %s \n", ascii);
			} 
            else if (i+1 == size) 
            {
				ascii[(i+1) % width] = '\0';
				if ((i+1) % width <= (width / 2)) 
                {
					printf(" ");
				}
				for (j = (i+1) % width; j < width; ++j) 
                {
					printf("   ");
				}
				printf("|  %s \n", ascii);
			}
		}
	}
}

int DisplayTCPSegment(unsigned char *pSegment, int segmentLen)
{
unsigned int sPort = 0;
unsigned int dPort = 0;
unsigned int sNum = 0;
unsigned int aNum = 0;
unsigned int flags = 0;
int flagCount = 0;

printf("TCP Header Fields: \n");


if (sizeof(*pSegment) <= segmentLen)
{

	sPort += *pSegment << 8;
	++pSegment;

	sPort += *pSegment;
	++pSegment;
	printf("Source Port: %u \n", sPort);
	//Source Port code==================================

	dPort += *pSegment << 8;
	++pSegment;

	dPort += *pSegment;
	++pSegment;
	printf("Destination Port: %u \n", dPort);
	//Destination Port code=============================


	sNum += *pSegment << 24;
	++pSegment;
	sNum += *pSegment << 16;
	++pSegment;
	sNum += *pSegment << 8;
	++pSegment;
	sNum += *pSegment;
	++pSegment;
	printf("Sequence Number: %u \n", sNum);
	//Seq Number code===================================

	aNum += *pSegment << 24;
	++pSegment;
	aNum += *pSegment << 16;
	++pSegment;
	aNum += *pSegment << 8;
	++pSegment;
	aNum += *pSegment;
	++pSegment;
	++pSegment;
	printf("Ack Number: %u \n", aNum);
	//Ack Number code====================================

	flags += *pSegment << 8;

	if ((*pSegment & CWR) != 0)
	{
		printf("CWR is set.\n");
		flagCount += 1;
	}
	if ((*pSegment & ECE) != 0)
	{
		printf("ECE is set.\n");
		flagCount += 1;
	}
	if ((*pSegment & URG) != 0)
	{
		printf("URG is set.\n");
		flagCount += 1;
	}
	if ((*pSegment & ACK) != 0)
	{
		printf("ACK is set.\n");
		flagCount += 1;
	}
	if ((*pSegment & PSH) != 0)
	{
		printf("PSH is set.\n");
		flagCount += 1;
	}
	if ((*pSegment & RST) != 0)
	{
		printf("RST is set.\n");
		flagCount += 1;
	}
	if ((*pSegment & SYN) != 0)
	{
		printf("SYN is set.\n");
		flagCount += 1;
	}
	if ((*pSegment & FIN) != 0)
	{
		printf("SYN is set.\n");
		flagCount += 1;
	}

	printf("Flags: %u ", flagCount);



	return 1;
}
else
{
	return printf("ERROR");
}


}

