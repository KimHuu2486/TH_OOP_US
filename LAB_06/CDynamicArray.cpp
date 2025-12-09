#pragma once
#include "CDynamicArray.h"

template <class T>
T* CDynamicArray<T>::array() const {
	return _a;
}

template <class T>
int CDynamicArray<T>::length() const {
	return _len;
}

template <class T>
void CDynamicArray<T>::setArray(const T* array, const int& newlen) {
	if (_a != nullptr) {
		delete[] _a;
		_a = nullptr;
	}

	_len = newlen;
	_a = new T[_len];

	// Xu li ly truong hop cap phat bo nho khong thanh cong
	if (_a == nullptr) {
		std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
		throw std::runtime_error("Memory allocation failed");
	}

	std::copy(array, array + _len, _a);
}

template <class T>
void CDynamicArray<T>::setLength(const int& length) {
	if (length < 0 || _len == length) {
		return;
	}

	T* old = _a;
	_a = nullptr;
	_a = new T[length];
	// Xu li ly truong hop cap phat bo nho khong thanh cong
	if (_a == nullptr) {
		std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
		throw std::runtime_error("Memory allocation failed");
	}
	int idx = 0;

	while (idx < std::min(_len, length)) {
		_a[idx] = old[idx];
		idx++;
	}

	_len = length;

	delete[] old;
}

template <class T>
CDynamicArray<T>::CDynamicArray() : _a(nullptr), _len(0) {}

template <class T>
CDynamicArray<T>::CDynamicArray(const int& length) : CDynamicArray<T>() {
	if (length < 0) {
		std::cerr << "Do dai mang khong hop le!" << std::endl;
		return;
	}
	if (length == 0) {
		return;
	}

	_len = length;
	_a = new T[_len]();
	// Xu li ly truong hop cap phat bo nho khong thanh cong
	if (_a == nullptr) {
		std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
		throw std::runtime_error("Memory allocation failed");
	}
}

template<class T>
CDynamicArray<T>::CDynamicArray(const CDynamicArray<T>& arr) : CDynamicArray<T>() {
	_len = arr._len;
	if (_len > 0) {
		_a = new T[_len];
		// Xu li ly truong hop cap phat bo nho khong thanh cong
		if (_a == nullptr) {
			std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
			throw std::runtime_error("Memory allocation failed");
		}
		std::copy(arr._a, arr._a + _len, _a);
	}
}

template<class T>
CDynamicArray<T>& CDynamicArray<T>::operator=(const CDynamicArray<T>& arr) {
	if (this != &arr) {
		if (_a != nullptr) {
			delete[] _a;
			_a = nullptr;
		}
		_len = arr._len;
		if (_len > 0) {
			_a = new T[_len];
			// Xu li ly truong hop cap phat bo nho khong thanh cong
			if (_a == nullptr) {
				std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
				throw std::runtime_error("Memory allocation failed");
			}
			std::copy(arr._a, arr._a + _len, _a);
		}
	}
	return *this;
}

template<class T>
CDynamicArray<T>::~CDynamicArray<T>() {
	if (_a != nullptr) {
		delete[] _a;
		_a = nullptr;
	}
	_len = 0;
}

template <class T>
void CDynamicArray<T>::pushBack(const T& value) {
	T* old = _a;
	_a = nullptr;
	_a = new T[_len + 1];

	// Kiểm tra có cấp phát bộ nhớ được không
	if (_a == nullptr) {
		std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
		throw std::runtime_error("Memory allocation failed");
	}

	for (int i = 0; i < _len; i++) {
		_a[i] = old[i];
	}

	_a[_len] = value;
	_len++;

	delete[] old;
}

template <class T>
T CDynamicArray<T>::getAt(const int& i) {
	if (i < 0) {
		int idx = _len - abs(i) % _len;
		return _a[idx];
	}
	else {
		return _a[i % _len];
	}
}

template <class T>
std::string CDynamicArray<T>::ToString() const {
	std::stringstream write;
	write << "Do dai: " << _len << "\n";
	write << "[";
	for (int i = 0; i < _len; i++) {
		write << _a[i];
		if (i < _len - 1) {
			write << ", ";
		}
	}
	write << "]\n";
	return write.str();
}

template <class T>
std::istream& operator>>(std::istream& in, CDynamicArray<T>& arr) {
	while (true) {
		std::cout << "Moi thay nhap do dai mang: ";
		in >> arr._len;
		if (arr._len > 0) {
			break;
		}
		std::cout << "Do dai mang khong hop le, moi thay nhap lai!\n";
	}
	if (arr._a != nullptr) {
		delete[] arr._a;
		arr._a = nullptr;
	}
	arr._a = new T[arr._len];
	// Kiểm tra có cấp phát bộ nhớ được không
	if (arr._a == nullptr) {
		std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
		throw std::runtime_error("Memory allocation failed");
	}
	for (int i = 0; i < arr._len; i++) {
		std::cout << "arr[" << i << "] = ";
		in >> arr._a[i];
	}
	return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const CDynamicArray<T>& arr) {
	out << arr.ToString();
	return out;
}


template <class T>
T CDynamicArray<T>::MaxElement() {
	if (_len == 0) {
		std::cerr << "Mang rong khong co phan tu!" << std::endl;
		throw std::runtime_error("Array is empty");
	}
	T maxElem = _a[0];
	for (int i = 1; i < _len; i++) {
		if (_a[i] > maxElem) {
			maxElem = _a[i];
		}
	}
	return maxElem;
}

template<class T>
void CDynamicArray<T>::sort() {
	for (int i = 0; i < _len - 1; i++) {
		for (int j = 0; j < _len - i - 1; j++) {
			if (_a[j] > _a[j + 1]) {
				T temp = _a[j];
				_a[j] = _a[j + 1];
				_a[j + 1] = temp;
			}
		}
	}
}
