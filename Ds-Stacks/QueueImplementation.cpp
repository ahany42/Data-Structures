#include "QueueImplementation.h"
#include <assert.h>
template <class T>
QueueImplementation<T>::QueueImplementation() {
	size = 5, count = 0, front = -1, back = -1;
	T* arr = new T[size];

}
template <class T>
int QueueImplementation<T>::length() {
	return count;
}
template <class T>
void QueueImplementation<T>::enqueue(T value) {
	assert(!full());
	if (count == 0)
		front = 0;
	arr[count] = value;
	count++;
	back = (back + 1) % size;
}
template <class T>
void QueueImplementation<T>::dequeue() {
	assert(!empty());
	if (count == 1) {
		front = back = -1;
	}
	else {
		front = (front + 1) % size;
	}
	count--;
}
template <class T>
T QueueImplementation<T>::Queuefront() {
	assert(!empty());
	return arr[front];
}
template <class T>
bool QueueImplementation<T>::empty() {
	return(count == 0);
}
template <class T>
bool QueueImplementation<T>::full() {
	return(count == size);
}
template <class T>
QueueImplementation<T>::~QueueImplementation() {
	delete[] arr;
}
