#include <iostream>
#include "StackImplementation.cpp"
#include "QueueImplementation.cpp"
#include "ArrayListImplementation.cpp"
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
	StackImplementation<char> S;
	S.StackPush('a');
	S.StackPush('b');
	S.StackPush('c');
	S.StackPush('d');
	S.StackPush('e');
	S.StackPush('f');
	ArrayListImplementation <int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(4);
	arr.InsertAt(2, 3);
	arr.Append(5);
	arr.DeleteAt(4);
	cout<<"second element in array "<<arr.At(1)<<endl;
	cout << "arr size "<<arr.Length() << endl;
	while (arr.Length() > 0) {
		cout << "Array List Element "<<arr.Length()<<" = "<<arr.At(arr.Length() - 1) << endl;
		arr.DeleteAt(arr.Length() - 1);
	}
		while (!S.empty())
	{
		cout << "stack top= " << S.StackTop() << endl;
		S.StackPop();
	}
	QueueImplementation<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	while (!q.empty()) {
		cout <<"Queue Front "<< q.Front() << endl;
		q.dequeue();
	}
	if (isequalQueue(q1, q2))
		cout << "Queues Are Identical" << endl;
	else
		cout << "Queues Are Not Identical" << endl;
	
	return 0;
}