#pragma once
template <class T>
class Node {
public:
	Node<T>* next;
	T value;
	Node();
	Node(T);
};
template <class T>
class LinkedListImplementation
{
	int count;
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedListImplementation();
	int Length();
	T At(int);
	void InsertAt(int ,T);
	void Append(T);
	void DeleteAt(int);
	~LinkedListImplementation();
};

