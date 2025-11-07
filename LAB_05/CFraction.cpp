#include "CFraction.h"

const int& CFraction::num() const {
	return _num;
}

const int& CFraction::den() const {
	return _den;
}

void CFraction::setNum(const int& num) {
	_num = num;
}

void CFraction::setDen(const int& den) {
	if (den != 0) {
		_den = den;
	}
}

CFraction::CFraction() {
	_num = 0;
	_den = 1;
}

CFraction::CFraction(const int& num, const int& den) {
	if (den != 0) {
		_num = num;
		_den = den;
	}
	else {
		_num = 0;
		_den = 1;
	}
}

CFraction::CFraction(const CFraction& f) {
	_num = f._num;
	_den = f._den;
}

CFraction::~CFraction() {}

std::string CFraction::ToString() const {
	std::stringstream writer;
	writer << _num << "/" << _den;
	return writer.str();
}

std::istream& operator>>(std::istream& in, CFraction& f) {
	while (true) {
		std::cout << "Moi thay nhap tu so: ";
		in >> f._num;
		std::cout << "Moi thay nhap mau so: ";
		in >> f._den;

		if (f._den != 0) {
			break;
		}

		std::cout << "Phan so khong hop le, moi thay nhap lai!\n";
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, const CFraction& f) {
	out << f.ToString() << std::endl;
	return out;
}

CFraction* CFraction::Parse(std::string line) {
	std::stringstream ss(line);
	char temp;
	int num, den;
	ss >> num >> temp >> den;
	return new CFraction(num, den);
}