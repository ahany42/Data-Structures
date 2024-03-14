#include "LinkedListImplementation.h"
#include <assert.h>

template <class T>
Node<T>::Node() {
	next = 0;
}

template <class T>
Node <T> ::Node( T val) {
	value = val;
	next = 0;
}

template <class T>
LinkedListImplementation <T>::LinkedListImplementation(void) {
	head = 0;
    tail =0;
	count = 0;
}
template <class T>
int LinkedListImplementation <T>::Length() {
	return count;
}
template <class T>
void LinkedListImplementation <T>::Append(T val) {
	Node <T>* node = new Node <T> (val);
	if (head == 0)
	{
		head = tail = node;
	}
	else {
		tail->next = node;
		tail = node;
	}
	count++;
}
template <class T>
T LinkedListImplementation <T>::At(int pos) {
	assert(pos >= 0 && pos < count);
	Node <T>* temp = head;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	return temp->value;
}
template <class T>
void LinkedListImplementation <T>::InsertAt(int pos,T value) {
	Node <T>* temp = head;
	Node <T>* node = new Node<T>(value);
	if (pos == 0) {
		node->next = head;
		head = node;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			temp = temp->next;
		}
		node->next = temp->next;
		temp->next = node;
	}
	count++;
}
template <class T>
void LinkedListImplementation <T>::DeleteAt(int pos) {
	assert(pos >= 0 && pos < count);
	Node <T>* temp = head;
	if (pos == 0) {
		head = head->next;
		delete temp;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			temp = temp->next;
		}
		Node <T>* d = temp->next;
		delete d;
		if (pos == count - 1)
			tail = temp;
	}
	count--;
}
template <class T>
LinkedListImplementation <T>::~LinkedListImplementation(void) {
	while (count != 0)
		DeleteAt(0);
}