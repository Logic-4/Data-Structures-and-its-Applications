#include<stdio.h>
#include<stdlib.h>

void tower(int n, char src, char tmp, char dst)
{
    if(n == 1)
    {
        printf("Move disk %d from %c to %c", n, src, dst);
        return;
    }
    tower(n-1, src, dst, tmp);
    printf("Move disk %d from %c to %c", n, src, dst);
    tower(n - 1, src, dst, tmp);
    return;
}