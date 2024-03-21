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