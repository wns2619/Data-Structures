#include "Swap.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cassert>

struct Element
{
	int key;
	char value;
};

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


	// 시간복잡도 확인

	{
		//std::ofstream ofile("log.txt");
		//for (int size = 1; size < 1000; ++size)
		//{
		//	int count = 0;
		//	int* arr = new int[size];
		//	for (int s = 0; s < size; ++s)
		//		arr[s] = size - s;

		//	int min_index;
		//	for (int i = 0; i < size - 1; ++i)
		//	{
		//		min_index = i;
		//		for (int j = i + 1; j < size; ++j)
		//		{
		//			++count;
		//			if (arr[i] < arr[min_index])
		//				min_index = j;
		//		}

		//		std::swap(arr[i], arr[min_index]);
		//	}

		//	ofile << size << ", " << count << std::endl;

		//	delete[]arr;
		//}

		//ofile.close();
	}



	//// 안전성 확인(unstable)
	//{
	//	Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
	//	int size = sizeof(arr) / sizeof(arr[0]);

	//	Print(arr, size);

	//	int min_index;
	//	for (int i = 0; i < size - 1; ++i)
	//	{
	//		min_index = i;
	//		for (int j = i + 1; j < size; ++j)
	//		{
	//			if (arr[j].key < arr[min_index].key)
	//				min_index = j;
	//		}
	//		std::swap(arr[i], arr[min_index]);

	//		Print(arr, size);
	//	}
	//}


}

void Swap::Bubble_Sort()
{
	int arr[] = { 5, 1, 4, 2, 8 };
	//int arr[] = { 5, 4, 3, 2, 1 };
	//int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Print(arr, n);
	std::cout << std::endl;

	// Bubble Sort
	// 이미 정렬이 되있거나, 거의 정렬이 되어있는 경우 버블소트가 빠르다.
	// 경우에 따라서 정렬 알고리즘의 속도가 달라짐.
	{
		for (int i = 0; i < n - 1; ++i)
		{
			bool swapped = false;
			
			for(int j = 0; j < n - i - 1; ++j)
			//for (int j = 0; j < n - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
				{
					std::swap(arr[j], arr[j + 1]);
					swapped = true;
				}

				Print(arr, n);
			}

			std::cout << std::endl;

			if (false == swapped)
				break;
		}
	}
}

void Swap::Insertion_Sort()
{
	// 오른 쪽으로 하나 밀기
	{
		int arr[] = { 1,2,4,5,3,6 };
		//int arr[] = { 1,2,3,4,5,6 };
		int n = sizeof(arr) / sizeof(arr[0]);
		Print(arr, n);


		int i, key, j;
		{
#pragma region Me
			// TODO
			for (i = n - 1; i > 0; --i)
			{
				key = arr[i];

				for (j = i; j > 0 && arr[j - 1] > key; --j)
				{
					arr[j] = arr[j - 1];

					std::cout << "Inner ";
					Print(arr, n);
				}

				arr[j] = key;

				std::cout << "Outer ";
				Print(arr, n);
			}
#pragma endregion Me


#pragma region	HongLab
				//for (i = 1; i < n; ++i)
			//{
			//	key = arr[i];
			//	for (j = i; j > 0 && arr[j - 1] > key; --j)
			//	{
			//		arr[j] = arr[j - 1];
			//		Print(arr, n);
			//	}

			//	arr[j] = key;
			//	Print(arr, n);
			//}
#pragma endregion HongLab

#pragma region HongLabWhile
			//for (int i = 1; i < n; ++i)
			//{
			//	int key = arr[i];
			//	j = i - 1;

			//	while (j >= 0 && arr[j] > key)
			//	{
			//		arr[j + 1] = arr[j];
			//		j = j - 1;
			//		Print(arr, n);
			//	}

			//	arr[j + 1] = key;
			//	Print(arr, n);
			//}
#pragma endregion



	/*		for (; j > 0 && arr[j - 1] > key; --j)
			{
				arr[j] = arr[j - 1];
				Print(arr, n);
			}

			arr[j] = key;

			Print(arr, n);
			std::cout << std::endl;*/
		}
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

	std::cout << std::endl;
}

void Swap::Print(Element* arr, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i].key << " ";

	std::cout << std::endl;

	for (int i = 0; i < size; ++i)
		std::cout << arr[i].value << " ";

	std::cout << std::endl;
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
	
	// Sort
	{
		//Selection_Sort();
		//Bubble_Sort();
		Insertion_Sort();
	}

}
