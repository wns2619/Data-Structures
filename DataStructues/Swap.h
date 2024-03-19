#pragma once


class Swap
{
public:
	Swap();
	~Swap();

public:
	void MySwapRef(int& sour, int& dest);
	void MySwapPtr(int* sour, int* dest);
	void MyAscendingSort();
	void MyAscendingSort_Three();
	void Find_MinNumber();
	void Find_MinIndex();
	void Selection_Sort();
	bool CheckSorted(int a, int b);
	bool CheckSorted(int arr[], int b);
	void Print(int* arr, int size);
	void Run();
private:

};

