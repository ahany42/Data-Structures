#pragma once
template <class T>
class BSTNode
{
public:
	T value;
	BSTNode<T>* left, * right;
	BSTNode(void);
	BSTNode(T val);
};
template <class T>
class BSTImplementation
{
	BSTNode<T>* root;
public:
	BSTImplementation(void);
	bool contains(T val);
	BSTNode<T>* findNode(T val);
	BSTNode<T>* findParentNode(T val);
	BSTNode<T>* findMinNode(BSTNode<T>* n);
	void removeNode(T val);
	void insert(T val);
	void traverse(int num);
	void inOrder(BSTNode<T>* node);
	void preOrder(BSTNode<T>* node);
	void postOrder(BSTNode<T>* node);
	void DeleteBST(BSTNode<T>* node);
	~BSTImplementation();
};

