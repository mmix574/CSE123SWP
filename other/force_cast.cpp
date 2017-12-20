#include <stdio.h>
#include <stdint.h>

void test1(){
	int a = 0;
	uint16_t b = a;
	printf("%u\n", b);
	int c = (int)b;
	printf("%d\n", c);
}
void test2(){
	char a = 12;
	char b = a%10;
	printf("%d\n", b);
}

int main(void){
	test2();
	return 0;
}