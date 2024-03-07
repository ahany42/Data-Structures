#pragma once
template<class T>
class ArrayListImplementation
{
	T* arr;
	int size;
	int count;
public:
	T At(int);
	int Length();
	void Append(T);
	void Expand();
	void InsertAt(int, T);
	void DeleteAt(int);
	ArrayListImplementation();
	~ArrayListImplementation();
};

