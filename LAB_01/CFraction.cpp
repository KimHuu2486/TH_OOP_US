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
CFraction::~CFraction() {}