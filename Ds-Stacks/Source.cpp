#include <iostream>
#include "StackImplementation.h"
#include "QueueImplementation.cpp"
using namespace std;

int main()
{
	StackImplementation S;
	S.StackPush('a');
	S.StackPush('b');
	S.StackPush('c');
	S.StackPush('d');
	S.StackPush('e');
	S.StackPush('f');
	while (!S.empty())
	{
		cout << "top= " << S.StackTop() << endl;
		S.StackPop();
	}
	cout << "here1" << endl;
	QueueImplementation<int> q;
	cout << "here2" << endl;
	q.enqueue(1);
	cout << "here3" << endl;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	cout << "here" << endl;
	while (!q.empty()) {
		cout << q.Front() << endl;
		q.dequeue();
	}

	return 0;
}