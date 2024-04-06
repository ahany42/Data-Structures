#pragma once
enum Order
{
	INORDER = 0,
	PREORDER = 1,
	POSTORDER = 2,
	XOrder = 3
};
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
	Node<T>* FindNode(T val);
	Node<T>* FindParentNode(T val);
	Node<T>* FindMinNode(Node<T>* n);
	void Insert(T val);
	void traverse(Order order);
	void inOrder(Node<T>* node);
	void preOrder(Node<T>* node);
	void postOrder(Node<T>* node);
	void DeleteBST(Node<T>* node);
	~BSTImplementation();
};

