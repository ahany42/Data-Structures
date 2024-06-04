#include "StackImplementation.h"
#include <assert.h>
#include <vector>
using namespace std;
template <class T>
StackImplementation<T>::StackImplementation(void)
{
	size= 10;
	count = 0;
	arr = new T[size];
}
template <class T>
int StackImplementation<T>::length() {
	return count;
}
template <class T>
void StackImplementation<T>::push(T value) {
	if (size == count)
		ExpandStack();
	arr[count] = value;
	count++;
}
template <class T>
void StackImplementation<T>::pop() {
	count--;
}
template <class T>
bool StackImplementation<T>::empty() {
	return (count == 0);
}
template <class T>
T StackImplementation<T>::top() {
	assert(!empty());
	return arr [count-1];
}
template <class T>
void StackImplementation<T>::ExpandStack() {
	size += 5;
	T* temp = new T[size];
	for (int i = 0; i < count; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	
}
template <class T>
void StackImplementation<T>::clear() {
	while (!empty()) {
		pop();
	}
}
template <class T>
T StackImplementation<T>::Max() {
	vector<T> v;
	while (!empty()) {
		v.push_back(top());
		pop();
	}
	sort(v.begin(), v.end());
	return v.back();
}
template <class T>
StackImplementation<T>::~StackImplementation(void)
{
	delete[] arr;
}
