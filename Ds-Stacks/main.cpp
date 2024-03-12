#include <iostream>
#include<string>
#include "StackImplementation.h"
#include "QueueImplementation.cpp"
#include "QueueImplementation.h"
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
	cout << isEqualQueue(q1, q2);
	string s;
	stack <char> st;
	cin >> s;
		BalancedBrackets(s,st);
	if(st.empty())
	cout<<"Balanced"<<endl;
	else
	cout<<"Not Balanced"<<endl;
	return 0;
}