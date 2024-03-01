#include <iostream>
#include "StackImplementation.h"
#include "QueueImplementation.cpp"
#include "QueueImplementation.h"
#include <queue>
using namespace std;

bool isequalQueue(queue <int> q1, queue <int> q2) {
	if (q1.size() == q2.size()) {
		while (!q1.empty()) {
			if (q1.front() == q2.front()) {
				q1.pop();
				q2.pop();
				if (q1.size() == 0)
					return true;
			}
			else {
				return false;
			}

		}
	}
	else
		return false;
}
int main()
{
	queue <int> q1;
	queue <int> q2;
	q1.push(1);
	q2.push(1);
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
	cout << isequalQueue(q1, q2);
	return 0;
}