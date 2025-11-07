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

	// Kiểm tra có cấp phát bộ nhớ được không
	if (_a == nullptr) {
		_len = 0;
		std::cerr << "Memory allocation failed!\n";
		return;
	}

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

		// Kiểm tra có cấp phát bộ nhớ được không
		if (_a == nullptr) {
			_len = 0;
			std::cerr << "Memory allocation failed!\n";
			return;
		}

		for (int i = 0; i < _len; i++) {
			_a[i] = arr._a[i];
		}
	}
}

CDynamicArray::~CDynamicArray() {
	if (_a != nullptr) {
		delete[] _a;
		_a = nullptr;
	}
	_len = 0;
}

void CDynamicArray::pushBack(const int& value) {
	int* old = _a;
	_a = nullptr;
	_a = new int[_len + 1];

	// Kiểm tra có cấp phát bộ nhớ được không
	if (_a == nullptr) {
		_len = 0;
		std::cerr << "Memory allocation failed!\n";
		return;
	}

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

std::string CDynamicArray::ToString() const {
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

std::istream& operator>>(std::istream& in, CDynamicArray& arr) {
	while (true) {
		std::cout << "Moi thay nhap do dai mang: ";
		in >> arr._len;

		if (arr._len > 0) {
			break;
		}
		std::cout << "Do dai mang khong hop le, moi thay nhap lai!\n";
	}

	std::cout << "Moi thay nhap " << arr._len << " phan tu cho mang:\n";
	arr._a = new int[arr._len];

	// Kiểm tra có cấp phát bộ nhớ được không
	if (arr._a == nullptr) {
		arr._len = 0;
		std::cerr << "Memory allocation failed!\n";
		return in;
	}

	for (int i = 0; i < arr._len; i++) {
		in >> arr._a[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const CDynamicArray& arr) {
	out << arr.ToString();
	return out;
}

CDynamicArray* CDynamicArray::Parse(std::string line) {
	std::string separator = ",";
	std::vector<std::string> tokens = Tokenizer::Parse(line, separator);

	if (tokens.size() <= 0) {
		return new CDynamicArray();
	}

	int len = tokens.size();

	CDynamicArray* temp = new CDynamicArray(len);

	for (int i = 0; i < len; i++) {
		temp->_a[i] = std::stoi(tokens[i]);
	}

	return temp;
}