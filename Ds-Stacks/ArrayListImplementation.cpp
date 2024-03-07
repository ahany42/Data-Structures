#include "ArrayListImplementation.h"
#include "assert.h"
template <class T>
ArrayListImplementation<T>::ArrayListImplementation() {
	size = 10;
	count = 0;
	arr = new T[size];
}
template <class T>
void ArrayListImplementation<T>::Append(T val) {
	if (count == size)
		Expand();
	arr[count] = val;
	count++;
}
template <class T>
int ArrayListImplementation<T>::Length() {
	return count;
}
template <class T>
void ArrayListImplementation<T>::Expand() {
	size = size + 10;
	T *arr2 = new T[size];
	for (int i = 0; i < size - 10; i++) {
		arr2[i] = arr[i];
	}
	delete[] arr;
	arr = arr2;
}
template <class T>
void ArrayListImplementation<T>::InsertAt(int pos,T value) {
	assert(pos < count);
	if (count == size)
		Expand();
	for (int i = count; i > pos; i--) {
		arr[i] = arr[i - 1];
	}
	arr[pos] = value;
	count++;
}
template <class T>
void ArrayListImplementation<T>::DeleteAt(int pos) {
	assert(pos < count);
	for (int i = pos; i < count - 1; i++) {
		arr[i] = arr[i +1];
	}
	count--;
}
template <class T>
T ArrayListImplementation<T>::At(int pos) {
	assert(pos < count);
	return arr[pos];
}
template <class T>
ArrayListImplementation<T>::~ArrayListImplementation() {
	delete[] arr;
}