#pragma once

#include <iostream>
#include <algorithm>

class CDynamicArray {
private:
	int* _a;
	int _len;
public:
	int* array() const;
	int length() const;
	void setArray(const int* array, const int& newlen);
	void setLength(const int& length);
public:
	CDynamicArray();
	CDynamicArray(const int&);
	CDynamicArray(const CDynamicArray& arr);
	~CDynamicArray();
public:
	void pushBack(const int& value);
	int getAt(const int& i);
	void print();
};