#pragma once


class Recursion
{
public:
	Recursion();
	~Recursion();

public:
	void Run();
	void Func1();
	void Func2();

	void RecurFunc(int count);

	// 재귀 합
	int Sum(int* arr, int n);
	int RecurSum(int* arr, int n);

	// 피보나치
	int Fibonnacci(int index);
	int RecurFibonnacci(int index);

	// 재귀 이진 탐색
	int RecurBinarySearch(int* arr, int left, int right, int x);
	int BinarySearch(int* arr, int n, int x);
	
	// 순열
	void RecurPermutations(char* arr, int left, int right);

	// 팩토리얼
	int RecurFactorial(int n);

	// 거듭제곱을 구하는 함수
	double slowPower(double x, int n);
	double Recurpower(double x, int n);

	// 하노이 타워
	void hanoiTower(int n, char from, char tmp, char to);
};

