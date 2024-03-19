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
	bool CheckSorted(int a, int b);
	void Run();
private:

};

