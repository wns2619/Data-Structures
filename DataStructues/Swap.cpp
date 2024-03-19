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

void Swap::MyAscendingSort_Three()
{
	for(int k = 0; k < 3; ++k)
		for(int j = 0; j <3; ++j)
			for (int i = 0; i < 3; ++i)
			{
				int arr[3] = { i, j, k };
				int size = sizeof(arr) / sizeof(arr[0]);

				for (int e = 0; e < size; ++e)
					std::cout << arr[e] << " " << std::flush;

				std::cout << " -> " << std::flush;

				// TODO 정렬 해보기
				// 0번 인덱스가 다 비교해서 크면 앞 뒤 변경. 
				for(int e = 0; e < size; ++e)
					for (int r = e; r < size; ++r)
					{
						if (arr[e] > arr[r])
							std::swap(arr[e], arr[r]);
					}

				// 첫 번째는 가장 작은 자리를 찾아서 0번째 인덱스에 넣는다. 0번째 인덱스는 그 자리로 스왑함.



				//if (arr[0] > arr[1])
				//	std::swap(arr[0], arr[1]);

				//if (arr[1] > arr[2])
				//	std::swap(arr[1], arr[2]);

				//if (arr[0] > arr[1])
				//	std::swap(arr[0], arr[1]);


				for (int e = 0; e < size; ++e)
					std::cout << arr[e] << " " << std::flush;

				std::cout << std::boolalpha;
				std::cout << CheckSorted(arr, size);
				std::cout << std::endl;
			}
}

void Swap::Find_MinNumber()
{
	int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int minnumber = INT_MAX;

	for (int i = 0; i < size; ++i)
		minnumber = std::min(minnumber, arr[i]);

	std::cout << minnumber << std::endl;
}

void Swap::Find_MinIndex()
{
	int arr[] = { 8,3,2,5,5,4,2,5,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int index = 0;
	int minNumber = INT_MAX;

	// Me .
	//for (int i = 0; i < size; ++i)
	//{
	//	if (minNumber > arr[i])
	//	{
	//		index = i;
	//		minNumber = arr[i];
	//	}
	//}

	// HongLab
	int min_index = 0;
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < arr[min_index])
			min_index = i;
	}

	//std::cout << "The index of min is " << index << std::endl;
	//std::cout << "Minimum number is " << arr[index] << std::endl;
	std::cout << "The index of min is " << min_index << std::endl;
	std::cout << "Minimum number is " << arr[min_index] << std::endl;

}

void Swap::Selection_Sort()
{
	int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int min_index = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		// TODO
		// 가장 작은 인덱스를 찾아서 스왑.
		min_index = i;
		for (int j = 1 + i; j < size; ++j)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		std::swap(arr[min_index], arr[i]);

		Print(arr, size);

		std::cout << std::boolalpha;
		std::cout << CheckSorted(arr, size);
		std::cout << std::endl;
	}
}

bool Swap::CheckSorted(int a, int b)
{
	return !(a > b);

	//if (a <= b)
	//	return true;

	//return false;
}

bool Swap::CheckSorted(int arr[], int b)
{
	for (int i = 0; i < b - 1; ++i)
		if (arr[i] > arr[i + 1]) return false;
	
	return true;
}

void Swap::Print(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
}

void Swap::Run()
{
	//int a = 3; int b = 2;
	//std::cout << a << " " << b << std::endl;

	////MySwapRef(a, b);
	//MySwapPtr(&a, &b);
	//
	//std::cout << a << " " << b << std::endl;

	//MyAscendingSort();
	//MyAscendingSort_Three();
	//Find_MinNumber();
	//Find_MinIndex();
	Selection_Sort();
}
