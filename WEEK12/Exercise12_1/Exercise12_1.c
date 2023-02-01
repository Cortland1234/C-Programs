#include <stdio.h>
#include <time.h>

int main ()
{
   time_t currentTime;

   time(&currentTime);

   char * timeString = ctime(&currentTime);

   printf("The current time is: %s", timeString);

   return(0);
}