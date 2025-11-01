#include "CDynamicArray.h"

int* CDynamicArray::array() const {
	return _a;
}

int CDynamicArray::length() const {
	return _len;
}

void CDynamicArray::setArray(const int* array, const int& newLen) {
	if (_a != nullptr) {
		delete[] _a;
		_a = nullptr;
	}

	_len = newLen;
	_a = new int[_len];
	for (int i = 0; i < _len; i++) {
		_a[i] = array[i];
	}
}

void CDynamicArray::setLength(const int& length) {
	if (length < 0 || _len == length) {
		return;
	}

	int* old = _a;
	_a = nullptr;
	_a = new int[length];
	int idx = 0;

	while (idx < std::min(_len, length)) {
		_a[idx] = old[idx];
		idx++;
	}

	//Truong hop length > _len
	while (idx < length) {
		_a[idx] = 0;
		idx++;
	}

	_len = length;

	delete[] old;
}

CDynamicArray::CDynamicArray()
	: _a(nullptr),
	_len(0)
{
}

CDynamicArray::CDynamicArray(const int& length)
	: CDynamicArray()
{
	_len = length;
	_a = new int[_len];
	for (int i = 0; i < _len; i++) {
		_a[i] = 0;
	}
}

CDynamicArray::CDynamicArray(const CDynamicArray& arr)
	: CDynamicArray()
{
	_len = arr.length();
	if (_len > 0) {
		_a = new int[_len];
		for (int i = 0; i < _len; i++) {
			_a[i] = arr._a[i];
		}
	}
}

CDynamicArray::~CDynamicArray() {
	if (_a != nullptr) {
		delete[] _a;
		_a = nullptr;
		_len = 0;
	}
}

void CDynamicArray::pushBack(const int& value) {
	int* old = _a;
	_a = nullptr;
	_a = new int[_len + 1];

	for (int i = 0; i < _len; i++) {
		_a[i] = old[i];
	}
	_a[_len] = value;
	_len++;

	delete[] old;
}

int CDynamicArray::getAt(const int& i) {
	if (i >= 0 && i < _len) {
		return _a[i];
	}
	return -1e6;
}

void CDynamicArray::print() {
	std::cout << "Length: " << _len << std::endl;
	std::cout << "Array: ";
	for (int i = 0; i < _len; i++) {
		std::cout << _a[i] << " ";
	}
	std::cout << std::endl;
}