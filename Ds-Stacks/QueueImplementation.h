
#pragma once
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
	void clearQueue();
	static bool iseqaul(QueueImplementation , QueueImplementation);
	~QueueImplementation();
};


