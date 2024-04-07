#include "Recursion.h"
#include <iostream>
#include <iomanip>

Recursion::Recursion()
{
}

Recursion::~Recursion()
{
}

void Recursion::Run()
{
	//RecurFunc(5);
	
	// Sum vs RecurSum

	/*int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << Sum(arr, n) << std::endl;
	std::cout << RecurSum(arr, n) << std::endl;*/

#pragma region Fibonnacci
	//std::cout << "Input     : ";
	//for (int i = 0; i < 15; ++i)
	//	std::cout << std::setw(3) << i << " ";
	//std::cout << std::endl;

	//// Fibonacci
	//std::cout << "Fibonnacci: ";
	//for (int i = 0; i < 15; ++i)
	//	std::cout << std::setw(3) << Fibonnacci(i) << " ";
	//std::cout << std::endl;

	//std::cout << "Fibonnacci: ";
	//for (int i = 0; i < 15; ++i)
	//	std::cout << std::setw(3) << RecurFibonnacci(i) << " ";
	//std::cout << std::endl;
#pragma endregion


#pragma region RecurBinarySearch
	/*int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << BinarySearch(arr, n, -2) << std::endl;
	std::cout << RecurBinarySearch(arr, 0, n - 1, -2) << std::endl;*/
#pragma endregion


#pragma region RecurPermutations
	/*char arr[] = "abc";

	RecurPermutations(arr, 0, 2);*/
#pragma endregion

#pragma region RecurFactorial
	// std::cout << RecurFactorial(5);
#pragma endregion

#pragma region Pow
	/*std::cout << slowPower(5, 3) << std::endl;
	std::cout << Recurpower(5, 3);*/
#pragma endregion

#pragma region HanoiTower
	hanoiTower(4, 'A', 'B', 'C');
#pragma endregion

	

}

void Recursion::Func1()
{
	int i = 1;

	Func2();
	
	std::cout << "This is Func1() " << i << std::endl;
}

void Recursion::Func2()
{
	int j = 2;
	std::cout << "This is Func2() " << j << std::endl;


}

void Recursion::RecurFunc(int count)
{
	if (count == 0)
		return;

	RecurFunc(count - 1);

	std::cout << count << std::endl;
}

int Recursion::Sum(int* arr, int n)
{
	int sum = 0;

	for (int i = 0; i < n; ++i)
		sum += arr[i];

	return sum;
}

int Recursion::RecurSum(int* arr, int n)
{
	if (n == 0)
		return 0;

	return RecurSum(arr, n - 1) + arr[n - 1];
}

int Recursion::Fibonnacci(int index)
{
	if (0 == index || 1 == index)
		return index;
	else
	{
		int prev1 = 0;
		int prev2 = 1;
		int fn = 0;

		for (int i = 2; i <= index; ++i)
		{
			fn = prev1 + prev2;

			prev1 = prev2;
			prev2 = fn;
		}

		return fn;
	}
}

int Recursion::RecurFibonnacci(int index)
{
	if (0 == index || 1 == index)
		return index;

	return RecurFibonnacci(index - 1) + RecurFibonnacci(index - 2);
}

int Recursion::RecurBinarySearch(int* arr, int left, int right, int x)
{
	if (left <= right)
	{
		int middle = (left + right) / 2;

		if (x < arr[middle])
		{
			return RecurBinarySearch(arr, left, middle - 1, x);
		}
		else if (x > arr[middle])
		{
			return RecurBinarySearch(arr, middle + 1, right, x);
		}
		else
			return middle;
	}

	return -1;
}

int Recursion::BinarySearch(int* arr, int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (x > arr[middle])
			left = middle + 1;
		else if (x < arr[middle])
			right = middle - 1;
		else
			return middle;
	}

	return -1;
}

void Recursion::RecurPermutations(char* arr, int left, int right)
{
	if (left == right)
	{
		for (int i = 0; i <= right; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		return;
	}

	for (int i = left; i <= right; ++i)
	{
		std::swap(arr[left], arr[i]);

		RecurPermutations(arr, left + 1, right);

		std::swap(arr[left], arr[i]);
	}
}

int Recursion::RecurFactorial(int n)
{
	if (n <= 1)
		return 1;

	return n * RecurFactorial(n - 1);
}

double Recursion::slowPower(double x, int n)
{
	double result = 1.0;
	for (int i = 0; i < n; ++i)
		result = result * x;
	return result;
}

double Recursion::Recurpower(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return Recurpower(x * x, n / 2);
	else
		return x * Recurpower(x * x, (n - 1) / 2);
}

void Recursion::hanoiTower(int n, char from, char tmp, char to)
{
	if (1 == n)
	{
		//from에서 to로 원판을 옮긴다.
		std::cout << "원판 1을 " << from << "에서" << to << "으로 옮긴다." << std::endl;
	}
	else
	{
		hanoiTower(n - 1, from, to, tmp);
		std::cout << "원판 " << n << "을 " << from << "에서 " << to << "으로 옮긴다." << std::endl;
		hanoiTower(n - 1, tmp, from, to);
	}
}
