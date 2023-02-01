#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentTime;

    struct tm *curGmtime;

    time(&currentTime);

    curGmtime = gmtime(&currentTime);

    printf("Current time is: %s", asctime(curGmtime));

    return 0;
}