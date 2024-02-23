#include "StackImplementation.h"
#include <assert.h>

StackImplementation::StackImplementation(void)
{
	size= 10;
	count = 0;
	arr = new char[size];
}

int StackImplementation::StackSize() {
	return count;
}
void StackImplementation::StackPush(char a) {
	if (size == count)
		ExpandStack();
	arr[count] = a;
	count++;
}
void StackImplementation::StackPop() {
	count--;
}
bool StackImplementation::empty() {
	return (count == 0);
}
char StackImplementation::StackTop() {
	assert(!empty());
	return arr [count-1];
}
void StackImplementation::ExpandStack() {
	size += 5;
	char* temp = new char[size];
	for (int i = 0; i < count; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	
}
StackImplementation::~StackImplementation(void)
{
	delete[] arr;
}
