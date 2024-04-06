#pragma once

class Searching
{
public:
	Searching();
	~Searching();

public:
	int Sequential_Search(int* arr, int size, int index);


public:
	int Count(int* arr, int size, int select);
	int SortedCount(int* arr, int size, int x);
	int SortedCountHelper(int* arr, int size, int x, int start);
	void InsertionSort(int* arr, int size);
	void Print(int* arr, int size);

public:
	void PrintHelper(int* arr, int n, int left, int right);
	int BinarySearch(int* arr, int n, int x); // ÀÌÁø Å½»ö
public:
	void Run();

private:

};

