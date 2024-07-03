#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"

typedef struct str
{	
	str* ptr1;
	str* ptr2;
	int data;
};

int main()
{
	//str* a = (str*)malloc(sizeof(str));
	//str b = *a;
	//str& c  = *a;
	//str& d  = b;
	//
	//printf("%d %d %d %d\n", a, b, c, d);
	//printf("%d %d %d %d\n", &a, &b, &c, &d);
	//printf("%d\n", &a->ptr1);

	int a = 0;
	int* b = &a;
	int& c = *b;
	int& d = (int&)b;
	int** e = &b;

	int i = 5;
	int ii = i;
	int iii = (int&)i;	
	int* iiii= &i;
	int& iiiii = (int&)iiii;
	
	printf("%d", sizeof(int&));

	//printf("%d %d %d %d\n", i, &j, &i, j);

	return 0;
}