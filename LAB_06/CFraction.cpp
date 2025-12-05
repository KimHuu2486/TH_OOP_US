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

CFraction::CFraction(const int& num, const int& den) 
	: CFraction()
{
	if (den != 0) {
		_num = num;
		_den = den;
	}
}

CFraction::CFraction(const CFraction& other) {
	_num = other._num;
	_den = other._den;
}

CFraction& CFraction::operator=(const CFraction& other) {
	if (this != &other) {
		_num = other._num;
		_den = other._den;
	}
	return *this;
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
	out << f.ToString();
	return out;
}

CFraction* CFraction::Parse(std::string line) {
	std::vector<std::string> tokens = Tokenizer::Parse(line, SEPERATOR);

	int num = std::stoi(tokens[0]);
	int den = std::stoi(tokens[1]);

	return new CFraction(num, den);
}
CFraction CFraction::operator+(const CFraction& other) {
	int num = _num * other._den + _den * other._num;
	int den = _den * other._den;
	int gcd = Utils::Gcd(num, den);
	CFraction result(num / gcd, den / gcd);
	return result;
}

CFraction CFraction::operator-(const CFraction& other) {
	int num = _num * other._den - _den * other._num;
	int den = _den * other._den;
	int gcd = Utils::Gcd(num, den);
	CFraction result(num / gcd, den / gcd);
	return result;
}

CFraction CFraction::operator*(const CFraction& other) {
	int num = _num * other._num;
	int den = _den * other._den;
	int gcd = Utils::Gcd(num, den);
	CFraction result(num / gcd, den / gcd);
	return result;
}

CFraction CFraction::operator/(const CFraction& other) {
	if (other._num == 0) {
		// Trường hợp chia cho 0
		return CFraction(INT_MAX, 1);
	}

	int num = _num * other._den;
	int den = _den * other._num;
	int gcd = Utils::Gcd(num, den);
	CFraction result(num / gcd, den / gcd);
	return result;
}

CFraction& CFraction::operator++() {
	_num += _den;
	int gcd = Utils::Gcd(_num, _den);
	_num /= gcd;
	_den /= gcd;
	return *this;
}

CFraction CFraction::operator++(int) {
	CFraction temp = *this;
	_num += _den;
	int gcd = Utils::Gcd(_num, _den);
	_num /= gcd;
	_den /= gcd;
	return temp;
}

CFraction& CFraction::operator--() {
	_num -= _den;
	int gcd = Utils::Gcd(_num, _den);
	_num /= gcd;
	_den /= gcd;
	return *this;
}

CFraction CFraction::operator--(int) {
	CFraction temp = *this;
	_num -= _den;
	int gcd = Utils::Gcd(_num, _den);
	_num /= gcd;
	_den /= gcd;
	return temp;
}