#pragma once
enum Order
{
	INORDER = 0,
	PREORDER = 1,
	POSTORDER = 2,
	XOrder = 3
};
template <class T>
class BSTNode
{
public:
	T value;
	BSTNode<T>* left, * right;
	BSTNode();
	BSTNode(T val);
};
template <class T>
class BSTImplementation
{
	BSTNode<T>* root;
public:
	BSTImplementation();
	bool contains(T val);
	BSTNode<T>* findNode(T val);
	BSTNode<T>* findParentNode(T val);
	BSTNode<T>* findMinNode(BSTNode<T>* n);
	void removeNode(T val);
	void insert(T val);
	void traverse(Order order);
	void inOrder(BSTNode<T>* node);
	void preOrder(BSTNode<T>* node);
	void postOrder(BSTNode<T>* node);
	void DeleteBST(BSTNode<T>* node);
	~BSTImplementation();
};

