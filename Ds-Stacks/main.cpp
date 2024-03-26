#include <iostream>
#include<string>
#include "StackImplementation.cpp"
#include "QueueImplementation.cpp"
#include "LinkedListImplementation.cpp"
#include <queue>
#include <stack>
#include <list>
using namespace std;

//Function to check if 2 Queues are identical
bool isEqualQueue(queue <int> q1, queue <int> q2) {
	if (q1.size() == q2.size()) {
		while (!q1.empty()) {
			if (q1.front() == q2.front()) {
				q1.pop();
				q2.pop();
				if (q1.size() == 0)
					return true;
				else return false;
			}
			else {
				return false;
			}

		}
	}
	else
		return false;
}
//Function to check if the brackets are balanaced 
bool BalancedBrackets(string s,stack <char> st){
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')' && !st.empty() && st.top()=='(') {
			st.pop();
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			return false;
		}
	}
	if (!st.empty()) {
		return false;
	}
	else
		return true;
}
//Function to remove desired value on top of the stack
template<class T>
void MovetoTop(stack <T> &s,T value) {
	stack<T> temp;
	while (!s.empty()) {
		if (s.top()!=value) {
			temp.push(s.top());
			s.pop();
		}
		else {
			s.pop();
		}
	}
	while (!temp.empty()) {
		s.push(temp.top());
		temp.pop();
	}
	s.push(value);
}
template<class T>
void TruncateList(LinkedListImplementation <T> &l,int num) {
	assert(num < l.Length());
	for (int i = l.Length(); i < num; i--)
		l.DeleteAt(i);
}
int main()
{
	
	/*int choice;
	do {
		cout << "---------------------" << endl;
		cout << "Enter 1 For Stacks" << endl;
		cout << "Enter 2 For Queues" << endl;
		cout << "Enter 3 For Queues Comparison" << endl;
		cout << "Enter 4 For Balanced Brackets" << endl;
		cout << "Enter 5 For Linked Lists" << endl;
		cout << "Enter 6 to Truncate List " << endl;
		cout << "Enter 8 to Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			StackImplementation <char> S;
			StackImplementation <char> S2;
			int choice2;
			char ch;
			
		
			do {
				cout << "To Add Element in Stack Enter 1" << endl;
				cout << "To Display Elements in Stack Enter 2" << endl;
				cout << "To Remove the top Element from Stack Enter 3" << endl;
				cout << "To Move Element to the top of Stack Enter 4" << endl;
				cout << "Enter 7 To Return to Main Menu" << endl;
				cin >> choice2;
				if (choice2 == 1) {
					cout << "Enter Char to Stack" << endl;
						cin >> ch;
						S.StackPush(ch);
						cout << "Element Added successfully" << endl;
						cout << "---------------------" << endl;
					
				}	
				else if (choice2 == 2) {
					//Validation on empty Stack
					if (S.empty()) {
						cout << "Empty Stack" << endl;
					}
					else {
						S2 = S;
						int i = 0;
						//Displaying Stack Elements
						while (!S2.empty())
						{
							cout << "Element " << i + 1 << " in Stack= " << S2.StackTop() << endl;
							S2.StackPop();

						}
					}
					
					cout << "---------------------" << endl;
				
				}
				else if (choice2 == 3) {
					
					if (S.empty()) {
						cout << "Empty Stack" << endl;
						cout << "---------------------" << endl;
						
					}
					//Removing Element on top of the stack
					else {
						S.StackPop();
						cout << "Removed successfully" << endl;

						
					}
				
				
				}
				else if (choice2 == 4) {
					stack <int> s;
					stack <int> tmp;
					s.push(1);
					s.push(2);
					s.push(3);
					s.push(0);
					//Move value 3 to the top of the stack
					MovetoTop(s, 3);
					tmp = s;
					while (!tmp.empty()) {
						cout << tmp.top()<<" ";
						tmp.pop();
					}
					cout << endl;
				}
				else {
					break;
				}
				
			} while (choice2 != 7);
		}
		else if (choice == 2) {
			QueueImplementation<char> q;
			QueueImplementation<char> q2;
			int choice2;
			do {
				cout << "To Add Element to Queue Enter 1" << endl;
				cout << "To Display Elements in Queue Enter 2" << endl;
				cout << "To Remove Element from Queue Enter 3" << endl;
				cout << "Enter 7 To Return to Main Menu" << endl;
				cin >> choice2;
				//Adding Elements to queue
				if (choice2 == 1) {
					char ch;
					cout << "Enter Char to Queue" << endl;
					cin >> ch;
					q.enqueue(ch);
				}
				else if (choice2 == 2) {
					if (q.empty()) {
						cout << "Empty Queue" << endl;
					}
					//Displaying Elements in queue 
					else {
						q2 = q;
						int i = 0;
						while (!q2.empty()) {
							cout << "Element " << i + 1 << " in Queue = " << q2.Front() << endl;
							q2.dequeue();
							i++;
						}
					}
					cout << "---------------------" << endl;
				}
				else if (choice2 == 3) {
					if (q.empty()) {
						cout << "Empty Queue" << endl;
						cout << "---------------------" << endl;
					}
					//Removing the front element of the queue 
					else {
						q.dequeue();
						cout << "Removed Successfully" << endl;
						cout << "---------------------" << endl;
					}
					
				}
				else {
					break;
				}
			} while (choice2 != 7);
			
			
			
			
		}
		else if (choice == 3) {
			queue <int> q1;
			queue <int> q2;
			char ch;
			int num;
			cout << "Enter Integers for Queues Comparisons" << endl;
			cout << "Enter N when you complete the input of queue 1" << endl;
			cin >> ch;
			while (ch != 'N' || ch != 'n') {
				cin >> num;
				q1.push(num);
			}
			cout << "Enter N when you complete the input of queue " << endl;
			cin >> ch;
			while (ch != 'N' || ch != 'n') {
				cin >> num;
				q2.push(num);
			}
			if (isEqualQueue(q1, q2))
				cout << "Identical Queues" << endl;
			else
				cout << "Queues Not Identical" << endl;
		}
		else if (choice == 4) {
			string str;
			stack <char> st;
			cout << "Enter a String of braces to test" << endl;
			cin >> str;
			
			if (BalancedBrackets(str, st))
				cout << "Balanced" << endl;
			else
				cout << "Not Balanced" << endl;
		}
		else if (choice == 5) {
			LinkedListImplementation <int> L;
			L.Append(9);
			L.Append(10);
			L.Append(11);
			L.InsertAt(1, 100);
			L.DeleteAt(3);

			for (int i = 0; i < L.Length(); i++)
				cout << "Element of index " << i + 1 << "is " << L.At(i) << endl;
		}
		else if (choice == 6) {
			cout << "Enter List Of Characters" << endl;
			char ch;
			int numlist;
			cout << "Enter The Number of Elements in list" << endl;
			cin >> numlist;
			LinkedListImplementation <char> l;

			for (int i = 0; i < numlist; i++) {
				cin >> ch;
				l.Append(ch);
			}
		
			int num;
			cout << "Enter the number of elements to keep in list" << endl;
			cin >> num;
				TruncateList(l, num);
				cout << "Trancated List" << endl;
				for (int i = 0; i < num; i++) {
					cout << l.At(i);
				}
				cout << endl;
		}
		else if (choice == 7) {
			QueueImplementation <int> q3;
			q3.enqueue(10);
			q3.enqueue(20);
			q3.enqueue(30);
		}
		else {
			break;
			}
	}while (choice != 8);*/

	return 0;
}