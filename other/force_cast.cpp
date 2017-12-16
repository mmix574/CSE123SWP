#include <stdio.h>
#include <stdint.h>

int main(void){

	int a = 0;
	uint16_t b = a;
	printf("%u\n", b);
	int c = (int)b;
	printf("%d\n", c);
	return 0;
}