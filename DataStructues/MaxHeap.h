#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>

template<typename T>
class MaxHeap
{
public:
	MaxHeap(int cap = 10)
	{
		assert(cap > 0);

		capacity_ = cap;
		size_ = 0;
		heap_ = new T[capacity_ + 1]; // heap[0]�� ����Ӵϴ�.
	}

	void Resize(int new_capacity)
	{
		T* new_heap = new T[new_capacity];
		memcpy(new_heap, heap_, sizeof(T) * (size_ + 1)); // +1 ����
		if (heap_) delete[] heap_;
		heap_ = new_heap;
		capacity_ = new_capacity;
	}

	T Top()
	{
		return heap_[1]; // 1�� �ε��� �ڸ�
	}

	bool IsEmpty()
	{
		return size_ == 0;
	}

	void Print()
	{
		using namespace std;
		cout << "Index: ";
		for (int i = 1; i <= size_; i++)
			cout << setw(3) << i;
		cout << endl;

		cout << "Value: ";
		for (int i = 1; i <= size_; i++)
			cout << setw(3) << heap_[i];
		cout << endl << endl;
	}

	void Push(const T& item)
	{
		//using namespace std;
		//cout << "Push " << item << endl;

		if (size_ == capacity_)
			Resize(capacity_ * 2);

		// ����: �ϴ� �� �������� ������ �Ŀ� �θ� ���� �ø���.
		size_ += 1;
		int current = size_; // �������� �߰����� ��ġ (�ε���)

		while (current != 1 && heap_[current / 2] < item) // �θ� ��ġ�� ���� �߰��Ϸ��� ������ �۴ٸ�
		{
			// �θ� ��ġ�� ���� �ڽ� ��ġ�� �����ؼ� ������.
			// TODO:
			heap_[current] = heap_[current / 2];

			cout << "Current = " << current << endl;
			Print();

			// TODO:
			current /= 2;
		}

		heap_[current] = item; // ���������� ������ ��ġ�� ����
	}

	void Pop()
	{
		assert(!IsEmpty());

		//using namespace std;
		cout << "Pop()" << endl;

		// heap[1].~T(); // �Ҹ��� ȣ�� 

		// ����: ���� ������ ���� ��Ʈ�� �ű� �Ŀ� ���� ������.

		T last_item = heap_[size_]; // ������ ������ ����
		size_--;					// ũ�� ���̱�

		int current = 1;			// ��Ʈ ��忡�� ����
		int child = 2;				// current * 2 (��Ʈ�� ���� �ڽ� �ε���)
		while (child <= size_)
		{
			// left, right �߿��� �� ū �ڽ��� �ε����� ã�´�. �̶� �ڽ��� �ϳ���� ã�� �ʿ� ����
			// TODO:
			if (child < size_ && heap_[child] < heap_[child + 1]) ++child;

			// ������ ���� �� ū �ڽ��� �� �̻��̸� ���̻� ������ ��ġ�� ã�� �ʿ䰡 ���� ������ ���� �ߴ�
			// TODO:
			if (last_item >= heap_[child])
				break;

			// �ڽ� ���� �θ� ��ġ�� ����, 
			// TOD:
			heap_[current] = heap_[child];

			cout << "Current = " << current << ", child = " << child << endl;
			Print();

			// �� �ڽ� ��ġ�� current �ε��� ����, child �ε����� �� ���� �ڽ� ��ġ�� ����
			// TODO:
			current = child;
			child *= 2;
		}

		heap_[current] = last_item;
	}

private:
	T* heap_ = nullptr;
	int size_ = 0;
	int capacity_ = 0;
};