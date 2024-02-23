#include <iostream>
#include "StackImplementation.h"

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

	return 0;
}