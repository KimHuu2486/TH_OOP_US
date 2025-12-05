#pragma once

#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>

template <class T>
class CDynamicArray {
private:
	T* _a;
	int _len;
public:
	T* array() const {
		return _a;
	}

	int length() const {
		return _len;
	}
	void setArray(const T* array, const int& newlen) {
		if (_a != nullptr) {
			delete[] _a;
			_a = nullptr;
		}

		_len = newlen;
		_a = new T[_len];

		// Xu li ly truong hop cap phat bo nho khong thanh cong
		if (_a == nullptr) {
			std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
			exit(EXIT_FAILURE);
		}

		std::copy(array, array + _len, _a);
	}

	void setLength(const int& length) {
		if (length < 0 || _len == length) {
			return;
		}

		T* old = _a;
		_a = nullptr;
		_a = new T[length];
		// Xu li ly truong hop cap phat bo nho khong thanh cong
		if (_a == nullptr) {
			std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
			exit(EXIT_FAILURE);
		}
		int idx = 0;

		while (idx < std::min(_len, length)) {
			_a[idx] = old[idx];
			idx++;
		}

		_len = length;

		delete[] old;
	}
public:
	CDynamicArray() : _a(nullptr), _len(0) {}

	CDynamicArray(const int& length) : CDynamicArray() {
		if (length < 0) {
			std::cerr << "Do dai mang khong hop le!" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (length == 0) {
			return;
		}

		_len = length;
		_a = new T[_len]();
		// Xu li ly truong hop cap phat bo nho khong thanh cong
		if (_a == nullptr) {
			std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	CDynamicArray(const CDynamicArray& arr) : CDynamicArray() {
		_len = arr._len;
		if (_len > 0) {
			_a = new T[_len];
			// Xu li ly truong hop cap phat bo nho khong thanh cong
			if (_a == nullptr) {
				std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
				exit(EXIT_FAILURE);
			}
			std::copy(arr._a, arr._a + _len, _a);
		}
	}

	CDynamicArray& operator=(const CDynamicArray& arr) {
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
					exit(EXIT_FAILURE);
				}
				std::copy(arr._a, arr._a + _len, _a);
			}
		}
		return *this;
	}

	~CDynamicArray() {
		if (_a != nullptr) {
			delete[] _a;
			_a = nullptr;
		}
		_len = 0;
	}
public:
	void pushBack(const T& value) {
		T* old = _a;
		_a = nullptr;
		_a = new T[_len + 1];

		// Kiểm tra có cấp phát bộ nhớ được không
		if (_a == nullptr) {
			std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < _len; i++) {
			_a[i] = old[i];
		}

		_a[_len] = value;
		_len++;

		delete[] old;
	}

	T getAt(const int& i) {
		if (i < 0) {
			int idx = _len - abs(i) % _len;
			return _a[idx];
		}
		else {
			return _a[i % _len];
		}
	}

	std::string ToString() const {
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

	template <class U>
	friend std::istream& operator>>(std::istream& in, CDynamicArray<U>& arr) {
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
		arr._a = new U[arr._len];
		// Kiểm tra có cấp phát bộ nhớ được không
		if (arr._a == nullptr) {
			std::cerr << "Cap phat bo nho khong thanh cong!" << std::endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < arr._len; i++) {
			std::cout << "arr[" << i << "] = ";
			in >> arr._a[i];
		}
		return in;
	}

	template <class U>
	friend std::ostream& operator<<(std::ostream& out, const CDynamicArray<U>& arr) {
		out << arr.ToString();
		return out;
	}

public:
	T MaxElement() {
		if (_len == 0) {
			std::cerr << "Mang rong khong co phan tu!" << std::endl;
			exit(EXIT_FAILURE);
		}
		T maxElem = _a[0];
		for (int i = 1; i < _len; i++) {
			if (_a[i] > maxElem) {
				maxElem = _a[i];
			}
		}
		return maxElem;
	}

	void sort() {
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
};