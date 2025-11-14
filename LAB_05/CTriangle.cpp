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
	if (_a != nullptr) {
		delete _a;
	}
	if (_b != nullptr) {
		delete _b;
	}
	if (_c != nullptr) {
		delete _c;
	}
	_a = nullptr;
	_b = nullptr;
	_c = nullptr;
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

std::string CTriangle::ToString() const {
	std::stringstream writer;
	writer << _a->ToString() << " & " << _b->ToString() << " & " << _c->ToString();
	return writer.str();
}

std::ostream& operator<<(std::ostream& out, const CTriangle& tri) {
	out << tri.ToString() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, CTriangle& tri) {
	while (true) {
		std::cout << "Moi thay nhap diem a: \n";
		in >> *tri._a;
		std::cout << "Moi thay nhap diem b: \n";
		in >> *tri._b;
		std::cout << "Moi thay nhap diem c: \n";
		in >> *tri._c;

		if (!tri.isLine(tri._a, tri._b, tri._c)) {
			break;
		}

		std::cout << "Diem a, b, c khong hop le, moi thay nhap lai!\n";
	}

	return in;
}

CTriangle* CTriangle::Parse(std::string line) {
	std::string seperator = "), ";
	std::vector<std::string> points = Tokenizer::Parse(line, seperator);

	CPoint* a = CPoint::Parse(points[0]);
	CPoint* b = CPoint::Parse(points[1]);
	CPoint* c = CPoint::Parse(points[2]);

	CTriangle* temp = new CTriangle(a, b, c);

	delete a;
	delete b;
	delete c;

	return temp;
}