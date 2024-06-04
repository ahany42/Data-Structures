#include <iostream>
#include "StackImplementation.cpp"
#include "QueueImplementation.cpp"
#include "LinkedListImplementation.cpp"
#include <queue>
#include <stack>
#include <list>
using namespace std;
//Function to reverse queue
void ReverseQ(queue<int>& q) {
	stack <int> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}

//Function to check if 2 Queues are identical
template<class T>
bool isEqualQueue(QueueImplementation <T> q1, QueueImplementation <T> q2) {
	if (q1.length() == q2.length()) {
		while (!q1.empty()) {
			if (q1.Front() == q2.Front()) {
				q1.dequeue();
				q2.dequeue();
				if (q1.length() == 0)
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
bool BalancedBrackets(string s, StackImplementation<char> st) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')' && !st.empty() && st.top() == '(') {
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
void MovetoTop(StackImplementation <T>& s, T value) {
	StackImplementation <T> temp;
	while (!s.empty()) {
		if (s.top() != value) {
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
void TruncateList(LinkedListImplementation <T>& l, int num) {
	assert(num < l.Length());
	for (int i = l.Length(); i < num; i--)
		l.DeleteAt(i);
}
/*Function to promote 1 element in queue
* Sample input 10,20,30,40,50,70,60,80
* promte 60 => 10,30,20,40,50,60,70,80
* */
template<class T>
void PromoteInQueue(queue <T>& q, T value) {
	queue <T>temp = q;

	int i = -1;
	while (!temp.empty()) {
		i++;
		if (temp.front() == value) {
			break;
		}
		temp.pop();
	}
	if (i == 0)
		return;
	temp = q;
	while (!q.empty()) {
		q.pop();
	}
	T valuetoshift;
	for (int j = 0; j < i; j++) {
		if (temp.empty())
			break;
		if (j == i - 1) {
			valuetoshift = temp.front();
			temp.pop();
			break;
		}
		q.push(temp.front());
		temp.pop();
	}
	temp.pop();
	q.push(value);
	q.push(valuetoshift);
	while (!temp.empty()) {
		q.push(temp.front());
		temp.pop();

	}


}
void ReverseString(string str) {
	StackImplementation   <char> s;
	for (int i = 0; i < str.size(); i++)
		s.push(str[i]);
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
template <class T>
void DequeNth(queue<T> &q,int n) {
	queue<T> temp;
	int i = 0;
	while (!q.empty()) {
		i++;
		if (i == n) {
			q.pop();
			continue;
		}
		else {

			temp.push(q.top());
			q.pop();
		}
	}
	q = temp;
}
template <class T>
void QReplace(queue <T> &q, T v1, Tv2) {
	queue <T> temp;
	while (!q.empty()) {
		if (q.front() == v1) {
			q.pop();
			temp.push(v2);
		}
		else {
			temp.push(q.top());
			q.pop();
		}
	}
	q = temp;
}
void QmoveZeros(queue<int>& q) {
	queue<int> temp;
	int counter = 0;
	if (q.top() == 0)
	{
		counter++;
		q.pop();
	}
	else {
		temp.push(q.top());
		q.pop();
	}
	for (int i = 0; i < counter; i++) {
		temp.push(0);
	}
	temp = q;
}
void EvenFirst(queue<int>& q) {
	queue<int> EvenQueue;
	queue<int> OddQueue;
	while (!q.empty()) {
	if (q.top() % 2 == 0)
		EvenQueue.push(q.top());
	else
		OddQueue.push(q.top());
	q.pop();
	}q.
	while (!EvenQueue.empty()) {
		q.push(EvenQueue.top());
		EvenQueue.pop();
	}
	while (!OddQueue.empty()) {
		q.push(OddQueue.top());
		OddQueue.pop();
	}

}
stack<int> DecimalToBinary(int number) {
	stack<int> binaryStack;
	while (n > 0) {
		binaryStack.push(number % 2);
		number = number / 2;
	}
	return binaryStack;
}
bool Palindrome(string str) {
	stack <char> s;
	for (int i = 0; i < str.length(); i++) {
		s.push(str[i]);
	}
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != s.top())
			return false;
		s.pop();
	}
	else return true;
}
int main()
{

	int choice;
	do {
		cout << "---------------------" << endl;
		cout << "Enter 1 For Stacks" << endl;
		cout << "Enter 2 For Queues" << endl;
		cout << "Enter 3 For Queues Comparison" << endl;
		cout << "Enter 4 For Balanced Brackets" << endl;
		cout << "Enter 5 For Linked Lists" << endl;
		cout << "Enter 6 to Truncate List " << endl;
		cout << "Enter 7 to Promote Element In queue " << endl;
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
				cout << "To Reverse String Enter 5" << endl;
				cout << "Enter 7 To Return to Main Menu" << endl;
				cin >> choice2;
				if (choice2 == 1) {
					//Stack test
					cout << "Enter Char to Stack" << endl;
					cin >> ch;
					S.push(ch);
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
							cout << "Element " << i + 1 << " in Stack= " << S2.top() << endl;
							S2.pop();

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
						S.pop();
						cout << "Removed successfully" << endl;


					}


				}
				else if (choice2 == 4) {
					StackImplementation <int> s;
					StackImplementation <int> tmp;
					s.push(1);
					s.push(2);
					s.push(3);
					s.push(0);
					//Move value 3 to the top of the stack
					MovetoTop(s, 3);
					tmp = s;
					while (!tmp.empty()) {
						cout << tmp.top() << " ";
						tmp.pop();
					}
					cout << endl;
				}
				else if (choice2 == 5) {
					string str;
					cout << "Enter String To Reverse" << endl;
					cin >> str;
					ReverseString(str);
				}
				else {
					break;
				}

			} while (choice2 != 7);
		}
		else if (choice == 2) {
			//Queues test
			QueueImplementation<char> q;
			QueueImplementation<char> q2;
			int choice2;
			do {
				cout << "To Add Element to Queue Enter 1" << endl;
				cout << "To Display Elements in Queue Enter 2" << endl;
				cout << "To Remove Element from Queue Enter 3" << endl;
				cout << "To Reverse Queue Enter 4" << endl;
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
				else if (choice2 == 4) {
					queue<int> q;
					q.push(1);
					q.push(2);
					q.push(3);
					q.push(4);
					cout << "Queue Before Reversing" << endl;
					queue<int> q1;
					q1 = q;
					while (!q1.empty())

					{
						cout << q1.front() << endl;
						q1.pop();
					}
					ReverseQ(q);
					cout << "Queue After Reversing" << endl;
					while (!q.empty())
					{
						cout << q.front() << endl;
						q.pop();
					}
				}
				else {
					break;
				}
			} while (choice2 != 7);




		}
		else if (choice == 3) {
			//Identical queues test
			QueueImplementation <int> q1;
			QueueImplementation <int> q2;
			char ch;
			int num;
			cout << "Enter Integers for Queues Comparisons" << endl;
			cout << "Enter N when you complete the input of queue 1" << endl;
			cin >> ch;
			while (ch != 'N' || ch != 'n') {
				cin >> num;
				q1.enqueue(num);
			}
			cout << "Enter N when you complete the input of queue " << endl;
			cin >> ch;
			while (ch != 'N' || ch != 'n') {
				cin >> num;
				q2.enqueue(num);
			}
			if (isEqualQueue(q1, q2))
				cout << "Identical Queues" << endl;
			else
				cout << "Queues Not Identical" << endl;
		}
		else if (choice == 4) {
			//Blanaced Braces test
			string str;
			StackImplementation <char> st;
			cout << "Enter a String of braces to test" << endl;
			cin >> str;

			if (BalancedBrackets(str, st))
				cout << "Balanced" << endl;
			else
				cout << "Not Balanced" << endl;
		}
		else if (choice == 5) {
			//Linked list test
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
			//Truncate fn test
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
			//Promote in Queue test
			queue <int> q;
			q.push(10);
			q.push(20);
			q.push(30);
			q.push(40);
			q.push(50);
			q.push(70);
			q.push(60);
			q.push(80);
			PromoteInQueue(q, 60);
			while (!q.empty()) {
				cout << q.front() << " ";
				q.pop();
			}
			cout << endl;
		}
		else {

			break;
		}
	} while (choice != 8);


	return 0;
}