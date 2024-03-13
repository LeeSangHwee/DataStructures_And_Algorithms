#include "stdio.h"
#include "stdlib.h"

// Dynamic Array(동적 배열)
void funcArray(int n)
{
	int* numArray = (int*)malloc(sizeof(int) * n);
	free(numArray);
}

int main()
{
	funcArray(6);
	return 0;
}

