#include "Swap.h"
#include <iostream>
#include <algorithm>

Swap::Swap()
{
}

Swap::~Swap()
{
}

void Swap::MySwapRef(int& sour, int& dest)
{
	int temp = sour;
	sour = dest;
	dest = temp;
}

void Swap::MySwapPtr(int* sour, int* dest)
{
	int temp = *sour;
	*sour = *dest;
	*dest = temp;
}

void Swap::MyAscendingSort()
{
	int arr[2];

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
		{
			arr[0] = i;
			arr[1] = j;

			if (arr[0] > arr[1])
				std::swap(arr[0], arr[1]);
			
			std::cout << std::boolalpha;
			std::cout << arr[0] << " " << arr[1] << " " << CheckSorted(arr[0], arr[1]) << std::endl;
		}
}

bool Swap::CheckSorted(int a, int b)
{
	return !(a > b);

	//if (a <= b)
	//	return true;

	//return false;
}

void Swap::Run()
{
	//int a = 3; int b = 2;
	//std::cout << a << " " << b << std::endl;

	////MySwapRef(a, b);
	//MySwapPtr(&a, &b);
	//
	//std::cout << a << " " << b << std::endl;

	MyAscendingSort();
}
