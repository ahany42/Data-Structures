#pragma once
class StackImplementation
{
	int size;
	int count;
	char* arr;
public:
	StackImplementation();
	int StackSize();
	void StackPush(char a);
	void StackPop();
	char StackTop();
	bool empty();
	void ExpandStack();
	~StackImplementation(void);
};

