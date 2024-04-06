#include "StringAlgorithm.h"
#include <assert.h>
#include <iostream>

StringAlgorithm::StringAlgorithm()
{
}

StringAlgorithm::~StringAlgorithm()
{
}

void StringAlgorithm::Run()
{
	char arr[] = "ababcdfdceeedag";
	int n = sizeof(arr) - 1;

	assert(n >= 1);

	InsertionSort(arr, n);

	char c = arr[0];
	int count = 1;

	std::cout << c;

	for (int i = 1; i < n; ++i)
	{
		if (arr[i] == c)
		{
			++count;
		}
		else
		{
			std::cout << count;

			count = 1;
			c = arr[i];

			std::cout << c;
		}
	}

	std::cout << count << std::endl;
}

int StringAlgorithm::Count(char* arr, int size, int select)
{
	int count = 0;
	for (int i = 0; i < size; ++i) if (arr[i] == select) ++count;
	return count;
}

void StringAlgorithm::InsertionSort(char* arr, int size)
{
	int i, j;
	int key;

	for (int i = 1; i < size; ++i)
	{
		key = static_cast<int>(arr[i]);
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = static_cast<char>(key);
	}
}
