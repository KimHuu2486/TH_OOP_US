#include "CTriangle.h"

const float EPS = 1e-6;

CPoint* CTriangle::A() const {
	return _a;
}

CPoint* CTriangle::B() const {
	return _b;
}

CPoint* CTriangle::C() const {
	return _c;
}

void CTriangle::setA(const CPoint* A) {
	if (!isLine(A, _b, _c)) {
		*_a = *A;
	}
}

void CTriangle::setB(const CPoint* B) {
	if (!isLine(_a, B, _c)) {
		*_b = *B;
	}
}

void CTriangle::setC(const CPoint* C) {
	if (!isLine(_a, _b, C)) {
		*_c = *C;
	}
}

CTriangle::CTriangle() {
	_a = new CPoint(1, 1);
	_b = new CPoint(1, 2);
	_c = new CPoint(4, 2);
}

CTriangle::CTriangle(const CPoint* a, const CPoint* b, const CPoint* c)
	: CTriangle()
{
	if (!isLine(a, b, c)) {
		*_a = *a;
		*_b = *b;
		*_c = *c;
	}
}

CTriangle::~CTriangle() {
	delete _a, _b, _c;
}

bool CTriangle::isLine(const CPoint* a, const CPoint* b, const CPoint* c) {
	float res = ((b->X() - a->X()) * (c->Y() - a->Y())) - ((c->X() - a->X()) * (b->Y() - a->Y()));
	return fabs(res) < EPS;
}

float CTriangle::perimeter() {
	float AB = _a->CalcDistanceTo(_b);
	float BC = _b->CalcDistanceTo(_c);
	float CA = _c->CalcDistanceTo(_a);
	return AB + BC + CA;
}

float CTriangle::area() {
	float temp = (_b->X() - _a->X()) * (_c->Y() - _a->Y()) - (_c->X() - _a->X()) * (_b->Y() - _a->Y());
	return 0.5f * fabs(temp);
}
