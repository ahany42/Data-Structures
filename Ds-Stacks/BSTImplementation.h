#pragma once
template <class T>
class Node
{
public:
	T value;
	Node<T>* left, * right;
	Node();
	Node(T val);
};
template <class T>
class BSTImplementation
{
	Node<T>* root;
public:
	BSTImplementation();
	bool contains(T val);
	T FindNode(T val);
	void Insert(T val);
	/*void Traverse(Order order);
	void InOrder(Node<T>* node);
	void PreOrder(Node<T>* node);
	void PostOrder(Node<T>* node);*/
	void DeleteBST(Node<T>* node);
	~BSTImplementation();
};

