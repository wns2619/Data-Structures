#pragma once

#include <iostream>
#include <fstream>
#include <string> // BinaryTree ���

#include "Queue.h"
#include "Stack.h"

template<typename T>
class BinaryTree
{
public:
	struct Node
	{
		T item = T();
		Node* left = nullptr; // Left child
		Node* right = nullptr; // Right child
	};

	// ����� ����: ť���� �ּ� ��ſ� ������ ���
	class MyQueue : public Queue<Node*>
	{
	public:
		void Print()
		{
			using namespace std;

			for (int i = (this->front_ + 1) % this->capacity_; i != (this->rear_ + 1) % this->capacity_; i = (i + 1) % this->capacity_)
				cout << this->queue_[i]->item << " ";
			cout << endl;
		}
	};

	// ����� ����: ���ÿ��� �ּ� ��ſ� ������ ���
	class MyStack : public Stack<Node*>
	{
	public:
		void Print()
		{
			using namespace std;

			for (int i = 0; i < this->Size(); i++)
				cout << this->stack_[i]->item << " ";
			cout << endl;
		}
	};

	BinaryTree() {}

	BinaryTree(Node* root)
	{
		root_ = root;
	}

	bool IsEmpty()
	{
		return root_ == nullptr;
	}

	void Visit(Node* node)
	{
		using namespace std;
		cout << node->item << " "; // �����ϰ� ���� �۾� ����(���⼭�� ���)
	}

	int Sum()
	{
		return Sum(root_);
	}

	int Sum(Node* node)
	{
		if (node == nullptr) return 0;
		return node->item + Sum(node->left) + Sum(node->right);
	}

	int Height()
	{
		return Height(root_);
	}

	int Height(Node* node)
	{
		if (node == nullptr) return 0;
		return 1 + std::max(Height(node->left), Height(node->right));
	}

	~BinaryTree()
	{
		DeleteTree(root_);
	}

	void DeleteTree(Node* node)
	{
		if (node)
		{
			DeleteTree(node->left);
			DeleteTree(node->right);
			delete node;
		}
	}

	void Preorder() { Preorder(root_); }
	void Preorder(Node* node)
	{
		// TODO:
		if (node != nullptr)
		{
			Visit(node);
			Preorder(node->left);
			Preorder(node->right);
		}
	};

	void Inorder() { Inorder(root_); }
	void Inorder(Node* node)
	{
		// TODO:
		if (node != nullptr)
		{
			Inorder(node->left);
			Visit(node);
			Inorder(node->right);
		}
	}

	void Postorder() { Postorder(root_); }
	void Postorder(Node* node)
	{
		if (node != nullptr)
		{
			Postorder(node->left);
			Postorder(node->right);
			Visit(node);
		}
	}

	void LevelOrder()
	{
		
		if (!IsEmpty())
		{
			Queue<Node*> q;
			q.Enqueue(root_);

			while (!q.IsEmpty())
			{
				Node* n = q.Front();
				q.Dequeue();

				if (n != nullptr)
				{
					Visit(n);
					q.Enqueue(n->left);
					q.Enqueue(n->right);
				}
			}
		}
	}

	void IterPreorder()
	{
		if (!root_) return;

		Stack<Node*> s; // ��Ʈ: MyStack q;
		s.Push(root_);

		while (!s.IsEmpty())
		{
			Node* n = s.Top();
			s.Pop();

			Visit(n);

			if (n->right)
				s.Push(n->right);
			if (n->left)
				s.Push(n->left);
		}
	}

	void IterInorder()
	{
		if (!root_) return;

		Stack<Node*> s;

		Node* current = root_;
		while (current || !s.IsEmpty())
		{
			// TODO
			while (current)
			{
				s.Push(current);
				current = current->left;
			}

			current = s.Top();
			s.Pop();

			Visit(current);

			current = current->right;
		}
	}

	void IterPostorder()
	{
		if (!root_) return;

		Stack<Node*> s1, s2;
		s1.Push(root_);

		while (!s1.IsEmpty())
		{
			Node* n = s1.Top();
			s1.Pop();

			s2.Push(n);

			if (n->left)
				s1.Push(n->left);
			if (n->right)
				s1.Push(n->right);
		}

		while (!s2.IsEmpty())
		{
			Node* n = s2.Top();
			s2.Pop();

			Visit(n);
		}
	}

	void Print2D();
	void PrintLevel(int n);
	void DisplayLevel(Node* p, int lv, int d);

protected:
	Node* root_ = nullptr;
};

// ����� ���� ����
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
template<typename T>
void BinaryTree<T>::Print2D()
{
	using namespace std;
	int i = 0;
	while (i < Height()) {
		PrintLevel(i);
		i++;
		cout << endl;
	}
}

template<typename T>
void BinaryTree<T>::PrintLevel(int n) {
	using namespace std;
	Node* temp = root_;
	int val = (int)pow(2.0, Height() - n + 1.0);
	cout << setw(val) << "";
	DisplayLevel(temp, n, val);
}

template<typename T>
void BinaryTree<T>::DisplayLevel(Node* p, int lv, int d) {
	using namespace std;
	int disp = 2 * d;
	if (lv == 0) {
		if (p == NULL) {
			cout << "   ";
			cout << setw(disp - 3) << "";
			return;
		}
		else {
			int result = ((p->item <= 1) ? 1 : (int)log10(p->item) + 1);
			cout << " " << p->item << " ";
			cout << setw(static_cast<streamsize>(disp) - result - 2) << "";
		}
	}
	else
	{
		if (p == NULL && lv >= 1) {
			DisplayLevel(NULL, lv - 1, d);
			DisplayLevel(NULL, lv - 1, d);
		}
		else {
			DisplayLevel(p->left, lv - 1, d);
			DisplayLevel(p->right, lv - 1, d);
		}
	}
}