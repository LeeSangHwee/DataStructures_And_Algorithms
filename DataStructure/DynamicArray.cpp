#include "stdio.h"
#include "stdlib.h"

// Dynamic Array(���� �迭)
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

