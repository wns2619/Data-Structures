#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	DoublyLinkedList(const DoublyLinkedList& list)
	{
		Node* current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->right;
		}
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO:
		Node* current = first_;
		while (current)
		{
			Node* temp = current;
			current = current->right;
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

		// TODO:
		Node* current = first_;
		while (current)
		{
			++size;
			current = current->right;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:
			while (current)
			{
				cout << current->item << ", ";
				
				if (current->right != nullptr)
					current = current->right;
				else
					break;
			}
			cout << endl;

			cout << "Backward: ";
			// TODO:
			while (current)
			{
				cout << current->item << ", ";
				
				if (current->left != nullptr)
					current = current->left;
				else
					break;
			}
			cout << endl;
		}
	}

	Node* Find(T item)
	{
		Node* current = first_;
		while (current)
		{
			if (current->item == item)
				return current;

			current = current->right;
		}

		return current; // TODO:
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:
			Node* temp = new Node;
			temp->item = item;
			temp->right = node->right;
			node->right = temp;

			if (temp->right)
				temp->right->left = temp;
			temp->left = node;
		}
	}

	void PushFront(T item)
	{
		Node* temp = new Node;
		temp->item = item;

		temp->right = first_;
		if (first_)
			first_->left = temp;
		first_ = temp;
		temp->left = nullptr;

		// TODO:
		//if (first_ == nullptr)
		//{
		//	first_ = new Node;
		//	first_->item = item;
		//	return;
		//}

		//Node* new_node = new Node;
		//new_node->item = item;
		//first_->left = new_node;
		//new_node->right = first_;
		//first_ = new_node;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			Node* current = first_;
			while (current->right) current = current->right;

			Node* temp = new Node;
			temp->item = item;
			temp->right = nullptr;
			temp->left = current;

			current->right = temp;
		}
		else
			PushFront(item);

		// TODO:
		//Node* current = first_;
		//while (current->right)
		//	current = current->right;

		//Node* new_node = new Node;
		//new_node->item = item;
		//current->right = new_node;
		//new_node->left = current;
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

		// TODO:
		Node* temp = first_;
		first_ = first_->right;
		if (first_)
			first_->left = nullptr;

		delete temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		// TODO:
		if (first_->right == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		}

		Node* current = first_;

		if (current->right)
		{
			while (current->right->right)
				current = current->right;

			Node* temp = current->right;
			current->right = current->right->right;

			delete temp;
		}
		else
		{
			delete first_;
			first_ = nullptr;
		}
	}

	void Reverse()
	{
		// TODO:
		if (IsEmpty())
			return;
		else
		{
			Node* current = first_;
			Node* prev = nullptr;

			while (current)
			{
				prev = current;

				current = current->right;

				std::swap(prev->left, prev->right);
			}

			first_ = prev;
		}
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
		while (current->right) current = current->right;
		
		return current->item; // TODO:
	}

protected:
	Node* first_ = nullptr;
};