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

	// ��� ��
	int Sum(int* arr, int n);
	int RecurSum(int* arr, int n);

	// �Ǻ���ġ
	int Fibonnacci(int index);
	int RecurFibonnacci(int index);

	// ��� ���� Ž��
	int RecurBinarySearch(int* arr, int left, int right, int x);
	int BinarySearch(int* arr, int n, int x);
	
	// ����
	void RecurPermutations(char* arr, int left, int right);

	// ���丮��
	int RecurFactorial(int n);

	// �ŵ������� ���ϴ� �Լ�
	double slowPower(double x, int n);
	double Recurpower(double x, int n);

	// �ϳ��� Ÿ��
	void hanoiTower(int n, char from, char tmp, char to);
};

