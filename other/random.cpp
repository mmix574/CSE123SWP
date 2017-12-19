#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    for(int i=0;i<10;i++)
        printf("%3d\n",rand()%32768+32767);
    printf("\n");
    return 0;
}