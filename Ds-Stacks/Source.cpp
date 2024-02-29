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
	cout << "Size"<<S.StackSize()<<endl;
	while (!S.empty())
	{
		cout << "top= " << S.StackTop() << endl;
		S.StackPop();
	}
	QueueImplementation <int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	while (!q.empty()) {
		cout << q.Queuefront() << endl;
		q.dequeue();
	}

	return 0;
}