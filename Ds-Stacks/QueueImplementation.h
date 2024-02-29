
/*#pragma once
template <class T>
class QueueImplementation
{
	int size, count, front, back;
	T* arr;
public:
	QueueImplementation(void);
	T Queuefront();
	int length();
	bool empty();
	bool full();
	void enqueue(T);
	void dequeue();
	~QueueImplementation(void);
};*/
#pragma once
//#include "QueueArr.cpp"

template <class T>
class QueueImplementation
{
	T* arr;
	int count, size;
	int front, back;
public:
	QueueImplementation();
	int length();
	void enqueue(T);
	void dequeue();
	T Front();
	bool empty();
	bool full();
	~QueueImplementation();
};


