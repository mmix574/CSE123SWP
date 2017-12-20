#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    char a = 65535;
    for(int i=0;i<10;i++)
    	a = (char)rand()%32768+32767;
        printf("%d\n",a);
    printf("\n");
    return 0;
}