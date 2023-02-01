#include<stdio.h>
#include<time.h>

int timeDelay(double t);

int main(void)
{
    double t;

    printf("Enter your desired time: ");
    scanf("%lf", &t);

    timeDelay(t); 

    return 0;
}

int timeDelay(double t)
{
    clock_t startClock;
    clock_t stopClock;
    double timeElapsed;
    startClock = clock();
    while(1)
    {
        stopClock = clock();
        timeElapsed = ((double) (stopClock - startClock) / CLOCKS_PER_SEC);
        if(timeElapsed >= t)
        {
            printf("End of time delay!\n");
            break;
        }

    }
    return 0;
}