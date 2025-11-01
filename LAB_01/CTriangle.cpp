#include "CTriangle.h"

const float EPS = 1e-6;

const CPoint& CTriangle::A() const {
	return _a;
}

const CPoint& CTriangle::B() const {
	return _b;
}

const CPoint& CTriangle::C() const {
	return _c;
}

void CTriangle::setA(const CPoint& A) {
	if (!isLine(A, _b, _c)) {
		_a = A;
	}
}

void CTriangle::setB(const CPoint& B) {
	if (!isLine(_a, B, _c)) {
		_b = B;
	}
}

void CTriangle::setC(const CPoint& C) {
	if (!isLine(_a, _b, C)) {
		_c = C;
	}
}

CTriangle::CTriangle() {
	_a = CPoint(0, 0);
	_b = CPoint(1, 0);
	_c = CPoint(0, 1);
}

CTriangle::CTriangle(const CPoint& a, const CPoint& b, const CPoint& c) {
	if (!isLine(a, b, c)) {
		_a = a;
		_b = b;
		_c = c;
	}
	else {
		_a = CPoint(0, 0);
		_b = CPoint(1, 0);
		_c = CPoint(0, 1);
	}
}

CTriangle::~CTriangle() {}

bool CTriangle::isLine(const CPoint& a, const CPoint& b, const CPoint& c) {
	float res = ((b.X() - a.X()) * (c.Y() - a.Y())) - ((c.X() - a.X()) * (b.Y() - a.Y()));
	return fabs(res) < EPS;
}