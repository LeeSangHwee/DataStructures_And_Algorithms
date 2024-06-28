#include <iostream>

void CallByValue(int _num);
void CallByAddress(int* _num);
void CallByReference(int& _num);

int main(void)
{
	int num;

	num = 10;
	std::cout << "Before Call By Value : " << num << std::endl;
	CallByValue(num);
	std::cout << "After Call By Value : " << num << std::endl << std::endl;

	num = 10;
	std::cout << "Before Call By Address : " << num << std::endl;
	CallByAddress(&num);
	std::cout << "After Call By Address : " << num << std::endl << std::endl;

	num = 10;
	std::cout << "Before Call By Reference : " << num << std::endl;
	CallByReference(num);
	std::cout << "After Call By Reference : " << num << std::endl << std::endl;

	return 0;
}

void CallByValue(int _num)
{
	_num = 5;
	std::cout << "Call By Value() : " << _num << std::endl;
}

void CallByAddress(int* _num)
{
	*_num = 5;
	std::cout << "Call By Value() : " << *_num << std::endl;
}

void CallByReference(int& _num)
{
	_num = 5;
	std::cout << "Call By Value() : " << _num << std::endl;
}
