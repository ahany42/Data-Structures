#include <iostream>
#include<string>
#include "StackImplementation.cpp"
#include "QueueImplementation.cpp"
#include <queue>
#include <stack>
using namespace std;

bool isEqualQueue(queue <int> q1, queue <int> q2) {
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
void BalancedBrackets(string s,stack <char> &st){
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')' && !st.empty() && st.top()=='(') {
			st.pop();
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			st.push('!');
		}
	}
}

int main()
{
	queue <int> q1;
	queue <int> q2;
	q1.push(1);
	q2.push(1);
	StackImplementation <char> S;
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

	QueueImplementation<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	while (!q.empty()) {
		cout << q.Front() << endl;
		q.dequeue();
	}
	if (isEqualQueue(q1, q2))
		cout << "Identical Queues" << endl;
	else
		cout << "Queues Not Identical" << endl;
	string str;
	stack <char> st;
	cout << "Enter a String of braces to test" << endl;
	cin >> str;
		BalancedBrackets(str,st);
	if(st.empty())
	cout<<"Balanced"<<endl;
	else
	cout<<"Not Balanced"<<endl;
	return 0;
}