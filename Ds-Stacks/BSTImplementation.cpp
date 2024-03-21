#include "BSTImplementation.h"
#include <iostream>
#include <assert.h>
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
T BSTImplementation<T>::FindNode(T val) {
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
void BSTImplementation<T>::Insert(T val) {
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
