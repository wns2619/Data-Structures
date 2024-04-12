#pragma once

#include "BinarySearchTree.h"

template<typename K, typename V>
class AVL : public BinarySearchTree<K, V>
{
public:
	using Base = BinarySearchTree<K, V>;
	using Item = BinarySearchTree<K, V>::Item;
	using Node = BinarySearchTree<K, V>::Node;

	//struct Item {
	//	K key = K();	// first
	//	V value = V();	// second
	//};

	//struct Node {
	//	Item item;
	//	Node* left = nullptr;
	//	Node* right = nullptr;
	//};

	int Height(Node* node)
	{
		return Base::Height(node); // �򰥸� ������
	}

	int Balance(Node* node)
	{
		if (node)
			return Base::Height(node->left) - Base::Height(node->right);
		else
			return 0;
	}

	Node* RotateLeft(Node* parent)
	{
		// TODO:
		Node* temp = parent->right;
		parent->right = temp->left;
		temp->left = parent;

		return temp;
	}

	Node* RotateRight(Node* parent)
	{
		// TODO:
		Node* temp = parent->left;
		parent->left = temp->right;
		temp->right = parent;

		return temp;
	}

	void Insert(const Item& item)
	{
		root_ = Insert(root_, item);
	}

	Node* Insert(Node* node, const Item& item)
	{
		if (!node)
			return new Node{ item, nullptr, nullptr };

		const auto& key = item.key;

		if (key < node->item.key)
			node->left = Insert(node->left, item);
		else if (key > node->item.key)
			node->right = Insert(node->right, item);
		else
		{
			node->item = item;
			return node;
		}

		int balance = Balance(node);

		// balance�� 0, 1, -1 �̸� ������ �ʿ䰡 ���ٰ� �Ǵ�

		// LL -> Right Rotation
		if (balance > 1 && Balance(node->left) >= 0)
			return RotateRight(node);

		//	TODO:

		// RR -> Left Rotation
		if (balance < -1 && Balance(node->right) <= 0)
			return RotateLeft(node);

		// LR -> Left-Right Rotation
		if (balance > 1 && Balance(node->left) < 0)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}

		// RL -> Right-Left Rotation
		if (balance < -1 && Balance(node->right) > 0)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}

		return node;
	}

	Node* MinKeyNode(Node* node)
	{
		assert(node);
		while (node->left)
			node = node->left;
		return node;
	}

	void Remove(const K& key)
	{
		using namespace std;
		cout << "Remove " << key << endl;
		root_ = Remove(root_, key);
	}

	Node* Remove(Node* node, const K& key)
	{
		// BST�� ����
		if (!node) return node;

		if (key < node->item.key)
			node->left = Remove(node->left, key);
		else if (key > node->item.key)
			node->right = Remove(node->right, key);
		else
		{
			if (!node->left)
			{
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (!node->right)
			{
				Node* temp = node->left;
				delete node;
				return temp;
			}

			Node* temp = MinKeyNode(node->right);
			node->item = temp->item;
			node->right = Remove(node->right, temp->item.key);
		}

		if (node == NULL)
			return node;

		// ���� ���
		int balance = Balance(node);

		// LL -> Right Rotation
		if (balance > 1 && Balance(node->left) >= 0)
			return RotateRight(node);

		// RR -> Left Rotation
		if (balance < -1 && Balance(node->right) <= 0)
			return RotateLeft(node);

		// LR -> Left-Right Rotation
		if (balance > 1 && Balance(node->left) < 0)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}

		// RL -> Right-Left Rotation
		if (balance < -1 && Balance(node->right) > 0)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}

		return node;
	}

private:
	Node*& root_ = BinarySearchTree<K, V>::root_;
	// this->root_�ε� ��� ����
};