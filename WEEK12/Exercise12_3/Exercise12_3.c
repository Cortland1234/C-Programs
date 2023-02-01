#include <stdio.h>
#include <time.h>

int main()
{
    time_t day;
    struct tm moonLanding;

    moonLanding.tm_sec = 0; 
    moonLanding.tm_min = 0; 
    moonLanding.tm_hour = 0; 
    moonLanding.tm_mday = 20; 
    moonLanding.tm_mon = 6; 
    moonLanding.tm_year = 1969 - 1900; 
    
    day = mktime(&moonLanding);

    printf("The first moon landing was %s", ctime(&day));

    return 0;
}