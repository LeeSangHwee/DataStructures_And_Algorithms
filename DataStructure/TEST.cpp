#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"

void testcreate(int i2, int* j2)
{
	i2 = 1;
	j2 = new int;
}

void testfunc(int* pnum)
{
	
}

int main()
{
	//int i = 0;
	//int* j = new int;
	//char* t = new char;
	//
	//testcreate(i, j);


	int num = 100;
	int* ptr = &num;
	int& ref = num;

	printf("%d", num);
	printf("%d", &num);

	printf("%d", ref);
	printf("%d", &ref);

	printf("%d", ptr);
	printf("%d", *ptr);
	printf("%d", &ptr);
	return 0;
}