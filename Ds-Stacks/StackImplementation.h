#pragma once
template <class T>
class StackImplementation
{
	int size;
	int count;
	T* arr;
public:
	StackImplementation();
	int length();
	void push(T);
	void pop();
	T top();
	bool empty();
	void ExpandStack();
	void clear();
	~StackImplementation(void);
};

