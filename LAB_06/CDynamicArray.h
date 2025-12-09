#pragma once

#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>


//template <class T> class CDynamicArray;
//
//template <class T>
//std::istream& operator>>(std::istream& in, CDynamicArray<T>& arr);
//
//template <class T>
//std::ostream& operator<<(std::ostream& out, const CDynamicArray<T>& arr);

template <class T>
class CDynamicArray {
private:
	T* _a;
	int _len;
public:
	T* array() const;
	int length() const;
	void setArray(const T* array, const int& newlen);
	void setLength(const int& length);
public:
	CDynamicArray();
	CDynamicArray(const int& length);
	CDynamicArray(const CDynamicArray& arr);
	CDynamicArray& operator=(const CDynamicArray& arr);
	~CDynamicArray();
public:
	void pushBack(const T& value);
	T getAt(const int& i);
	std::string ToString() const;
	template <class U>
	friend std::istream& operator>>(std::istream& in, CDynamicArray<U>& arr);
	template <class U>
	friend std::ostream& operator<<(std::ostream& out, const CDynamicArray<U>& arr);
public:
	T MaxElement();
	void sort();
};
