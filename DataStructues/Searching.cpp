#include "Searching.h"
#include <iostream>
#include <iomanip>
#include <cassert>

Searching::Searching()
{
}

Searching::~Searching()
{
}

int Searching::Sequential_Search(int* arr, int size, int index)
{
	// Horowitz 자료구조 참고
	int i;
	for (i = 0; i < size && arr[i] != index; ++i);
	if (i == size) return -1;
	else return i;

	//for (int i = 0; i < size; ++i)
	//{
	//	if (arr[i] == index)
	//		return i;
	//}

	// return -1;
}

int Searching::Count(int* arr, int size, int select)
{
	int count = 0;

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == select)
			++count;
	}

	return count;
}

int Searching::SortedCount(int* arr, int size, int x)
{
	int i = Sequential_Search(arr, size, x);

	if (i >= 0)
		return SortedCountHelper(arr, size, x, i + 1) + 1;
	else
		return 0;
}

int Searching::SortedCountHelper(int* arr, int size, int x, int start)
{
	int count = 0;
	for (int i = start; i < size; ++i)
	{
		if (arr[i] == x)
			++count;
		else
			break; // 조기 종료
	}

	return count;
}

void Searching::InsertionSort(int* arr, int size)
{
	int key, i, j;

	for (i = 1; i < size; ++i)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void Searching::Print(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}

void Searching::PrintHelper(int* arr, int n, int left, int right)
{
	std::cout << "[" << left << "," << right << "]" << std::endl;

	std::cout << "Indices: ";
	for (int i = left; i <= right; ++i)
		std::cout << std::setw(2) << i << " ";
	std::cout << std::endl;

	std::cout << "Values : " << std::setw(2);
	for (int i = left; i <= right; ++i)
		std::cout << std::setw(2) << arr[i] << " ";
	std::cout << std::endl;


}

int Searching::BinarySearch(int* arr, int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		PrintHelper(arr, n, left, right);
		
		int middle = (left + right) / 2;
		std::cout << "middle" << std::endl;

		if (x < arr[middle])
		{
			right = middle - 1;
			std::cout << "right " << right << std::endl;
		}
		else if (x > arr[middle])
		{
			left = middle + 1;
			std::cout << "left " << left << std::endl;
		}
		else
		{
			std::cout << "Found " << middle << std::endl;
			return middle;
		}

		//break;
	}

	std::cout << "Not found" << std::endl;
	return -1;
}

void Searching::Run()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	 assert(n > 0);

	BinarySearch(arr, n, 3);

	//int arr[] = { 8,1,1,3,2,5,1,2,1,1 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	//std::cout << "Count 9 = " << Count(arr, n, 9) << std::endl;
	//std::cout << "Count 2 = " << Count(arr, n, 2) << std::endl;
	//std::cout << "Count 8 = " << Count(arr, n, 8) << std::endl;
	//std::cout << "Count 1 = " << Count(arr, n, 1) << std::endl;
	//std::cout << std::endl;
	//
	//std::cout << "Search 2 = " << Sequential_Search(arr, n, 2) << std::endl;
	//std::cout << "Search 5 = " << Sequential_Search(arr, n, 5) << std::endl;
	//std::cout << "Search 9 = " << Sequential_Search(arr, n, 9) << std::endl;
	//std::cout << std::endl;

	//InsertionSort(arr, n);
	//Print(arr, n);

	//std::cout << "Sorted Count 9 = " << SortedCount(arr, n, 9) << std::endl;
	//std::cout << "Sorted Count 2 = " << SortedCount(arr, n, 2) << std::endl;
	//std::cout << "Sorted Count 8 = " << SortedCount(arr, n, 8) << std::endl;
	//std::cout << "Sorted Count 1 = " << SortedCount(arr, n, 1) << std::endl;
	//std::cout << std::endl;
}
