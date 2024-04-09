#pragma once

#include <cassert>
#include <iostream>

template<typename T> // ���ø� ���
class Stack
{
public:
	Stack(int capacity = 1)
	{
		assert(capacity > 0);
		Resize(capacity);
	}

	~Stack()
	{
		if (stack_) delete[] stack_;
	}


	void Resize(int new_capacity)
	{
		T* new_stack = new T[new_capacity];
		memcpy(new_stack, stack_, sizeof(T) * Size());
		if (stack_) delete[] stack_;
		stack_ = new_stack;
		capacity_ = new_capacity;
	}

	bool IsEmpty() const
	{
		return top_ == -1;
	}

	int Size() const
	{
		return top_ + 1;
	}

	void Print()
	{
		using namespace std;

		for (int i = 0; i < Size(); i++) // Size() ���
			cout << stack_[i] << " ";
		cout << endl;
	}

	// Returns TOP element of stack.
	T& Top() const
	{
		assert(!IsEmpty());

		return stack_[top_];
	}

	// Insert item into the TOP of the stack
	void Push(const T& item)
	{
		// TODO: �ʿ��ϸ� �������� 
		if (top_ == capacity_ - 1)
			Resize(capacity_ * 2);
		// TODO:
		stack_[++top_] = item;
	}

	// Delete the TOP element of the stack
	void Pop()
	{
		assert(!IsEmpty());

		// TODO:
		--top_;
	}

protected: // �ڿ��� ����ؼ� ���
	T* stack_ = nullptr;
	int top_ = -1; // 0 �ƴ�
	int capacity_ = 0;
};