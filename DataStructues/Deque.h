#pragma once

#include "Queue.h"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (��, dequeue�� ����)
template<typename T>
class Deque : public Queue<T>
{
	typedef Queue<T> Base;

public:
	Deque(int capacity)
		: Queue<T>(capacity)
	{
	}

	T& Front()
	{
		return Base::Front();
	}

	T& Back()
	{
		return Base::Rear();
	}

	void PushFront(const T& item)
	{
		if (Base::IsFull())
			Base::Resize();

		// TODO:

		Base::queue_[Base::front_] = item;
		Base::front_ = (Base::front_ - 1 + Base::capacity_) % Base::capacity_;
	}

	void PushBack(const T& item)
	{
		Base::Enqueue(item);
	}

	void PopFront()
	{
		Base::Dequeue();
	}

	void PopBack()
	{
		assert(!Base::IsEmpty());

		// TODO:
		Base::rear_ = (Base::rear_ - 1 + Base::capacity_) % Base::capacity_;
	}

private:
	// Queue�� ����
};