#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: ���� ����Ʈ ����
		Node* current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // ��� ������(delete) �մϴ�.
	{
		// TODO: ��� ����
		Node* current = first_;
		while (current)
		{
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size�� �ϳ��ϳ� ��� ��ȯ
		Node* current = first_;
		while (current)
		{
			current = current->next;
			++size;
		}

		return size;
	}

	T Front()
	{
		assert(first_);

		return first_->item;
	}

	T Back()
	{
		assert(first_);

		Node* current = first_;
		while (current->next)
			current = current->next;

		return current->item;
	}

	Node* Find(T item)
	{
		// TODO: item�� ������ ��� ������ ��ȯ
		Node* current = first_;
		while (current)
		{
			if (current->item == item)
				return current;
		
			current = current->next;
		}

		return current;
	}

	void InsertBack(Node* node, T item)
	{
		// TODO:
		Node* temp = new Node;
		temp->item = item;
		temp->next = node->next;
		node->next = temp;
	}

	void Remove(Node* n)
	{
		assert(first_);

		Node* prev = first_;
		while (prev->next)
		{
			if (prev->next == n)
				break;

			prev = prev->next;
		}

		prev->next = n->next;
		delete n;
	}

	void PushFront(T item)
	{
		// first_�� nullptr�� ���� �ƴ� ��� ������ �����غ��� (�ᱹ�� �� ��츦 �ϳ��� ��ĥ �� ����)

		//z ���ο� ��� �����
		// TODO:
		Node* new_node = new Node;
		new_node->item = item;
		// ���� ���� ����
		// TODO:
		new_node->next = first_;
		first_ = new_node;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			// TODO:
			Node* current = first_;
			while (true)
			{
				Node* next = current->next;
				if (next == nullptr)
				{
					next = new Node;
					next->item = item;
					current->next = next;
					break;
				}
				current = current->next;
			}

			current = new Node;
			current->item = item;
		}
		else
		{
			// TODO:
			PushFront(item);
		}
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO: �޸� ����
		Node* next = first_->next;
		delete first_;
		first_ = next;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		if (first_->next == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		}
		// �� �ڿ��� �ϳ� ���� ��带 ã�ƾ� �մϴ�.
		assert(first_);
		// TODO: �޸� ����
		Node* second_last = first_;
		
		while (second_last->next->next)
			second_last = second_last->next;

		Node* temp = second_last->next;
		second_last->next = second_last->next->next;

		delete temp;
	}

	void Reverse()
	{
		// TODO: 
		Node* current = first_;
		Node* previous = nullptr;

		while (current)
		{
			Node* temp = previous;
			previous = current;
			current = current->next;
			previous->next = temp;
		}

		first_ = previous;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// �ּҸ� ª�� ������ ��� (�� �κ��� ��κ� �����ϱ⶧���� �޺κи� ���)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};