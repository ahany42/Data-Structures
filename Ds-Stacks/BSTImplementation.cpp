#include "BSTImplementation.h"
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
Node <T>::Node() {
	left = right = NULL;
}
template <class T>
Node <T>::Node(T val) {
	left = right = NULL;
	value = val;
}
template <class T>
BSTImplementation<T>::BSTImplementation() {
	root = NULL;
}
template <class T>
bool BSTImplementation<T>::contains(T val) {
	Node <T>* tmp = FindNode(val);
	return (tmp != NULL);
}
template <class T>
Node<T>* BSTImplementation<T>::findNode(T val) {
	Node <T>* tmp = root;
	while (tmp != NULL) {
		if (tmp->value == val) {
			return tmp;
		}
		else if (val > tmp->value) {
			tmp = tmp->right;
		}
		else {
			tmp = tmp->left;
		}
	}
	return tmp;
}
template <class T>
Node<T>* BSTImplementation<T>::findParentNode(T val) {
	Node <T>* b = NULL;
	Node <T>* a = root;
	while (a != NULL) {
		if (a->value == val) {
			break;
		}
		else if (val > a->value) {
			a = a->right;
		}
		else {
			a = a->left;
		}
	}
	return b;
}
template <class T>
Node<T>* BSTImplementation<T>::findMinNode(Node<T>* n) {
	Node <T>* MinNode = n;
	while (MinNode->left != NULL) {
		MinNode = MinNode->left;
	}
	return MinNode;
}
template <class T>
void BSTImplementation<T>::insert(T val) {
	assert(!contains(val));
	Node<T>* newnode = new Node<T>(val);
	if (root == NULL) {
		root = newnode;
	}
	else {
		Node <T>* tmp = root;
		while (true){
			if (val > tmp->value) {
				if (tmp->right == NULL) {
					tmp->right = newnode;
					break;
				}
				else {
					tmp = tmp->right;
				}
			}
			else {
				if (tmp->left == NULL) {
					tmp->left = val;
					break;
				}
				else {
					tmp = tmp->left;
				}
			}
		}
	}
}
template <class T>
void BSTImplementation<T>::traverse(Order order)
{
	if (order == INORDER)
		inOrder(root);
	else if (order == PREORDER)
		preOrder(root);
	else
		postOrder(root);
}

template <class T>
void BSTImplementation<T>::inOrder(Node<T>* node)
{
	if (node != NULL)
	{
		inOrder(node->left);
		cout << node->value << endl;
		inOrder(node->right);
	}
}

template <class T>
void BSTImplementation<T>::preOrder(Node<T>* node)
{
	if (node != NULL)
	{
		cout << node->value << endl;
		preOrder(node->left);
		preOrder(node->right);
	}
}

template <class T>
void BSTImplementation<T>::postOrder(Node<T>* node)
{
	if (node != NULL)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->value << endl;
	}
}
template <class T>
void BSTImplementation<T>::removeNode(T val) {
	assert(contains(val));
	Node<T>* n = findNode(val);
	Node <T>* parent = findParentNode(val);
	//deleteing a leave node
	if ((n->left == NULL) && (n->right == NULL))
	{
		if (n == root)
			root = NULL;
		else {
		
			if (parent->value > n->value) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
		delete n;
	}
	//deleting node with 1 child
	else if ((n->left == NULL) && (n->right != NULL)) {
		if (n == root)
		{
			root = n->right;
		}
		else {
			if (n->value < parent->value) {
				parent->left = n->right;
			}
			else {
				parent->right = n->right;
			}
		}
		delete n;
	}
	else if ((n->left != NULL) && (n->right == NULL)) {
		if (n == root)
		{
			root = n->left;
		}
		else {
			if (n->value < parent->value) {
				parent->left = n->left;
			}
			else {
				parent->right = n->left;
			}
		}
		delete n;
	}
	//deleting node with 2 children
	else {
		Node<T>* MinNode = findMinNode(n->right);
		n->value = MinNode->value;
		if (parent == n) {
			parent->right = MinNode->right;
		}
		else {
			parent->left = MinNode->right;
		}
		delete MinNode;
	}
}
