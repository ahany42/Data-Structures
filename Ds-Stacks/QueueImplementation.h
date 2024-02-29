
#pragma once
template <class T>
class QueueImplementation
{
	int size, count, front, back;
	T* arr;
public:
	QueueImplementation();
	T Queuefront();
	int length();
	bool empty();
	bool full();
	void enqueue(T);
	void dequeue();
	~QueueImplementation();
};

