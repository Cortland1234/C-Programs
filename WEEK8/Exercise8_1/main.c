#include <stdio.h>
#include "testlib.h"

#define NUMBER 10

int main()
{
    printf("test(%d) = %d\n", NUMBER, test(NUMBER));
    return 0;
}