#pragma once
template <class T>
class StackImplementation
{
	int size;
	int count;
	char* arr;
public:
	StackImplementation();
	int StackSize();
	void StackPush(T);
	void StackPop();
	T StackTop();
	bool empty();
	void ExpandStack();
	~StackImplementation(void);
};

