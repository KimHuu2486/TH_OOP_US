#include "CPoint.h"

float CPoint::X() const {
	return _x;
}

float CPoint::Y() const {
	return _y;
}

void CPoint::setX(const float& value) {
	_x = value;
}

void CPoint::setY(const float& value) {
	_y = value;
}

CPoint::CPoint() {
	this->_x = 0;
	this->_y = 0;
}

CPoint::CPoint(const float& x, const float& y) {
	this->_x = x;
	this->_y = y;
}

CPoint::~CPoint() {}

bool CPoint::isEqual(const CPoint* p2) const {
	return (fabs(this->_x - p2->X()) < epsilon) && fabs((this->_y - p2->Y()) < epsilon);
}

std::ostream& operator<<(std::ostream& out, const CPoint& p) {
	out << "(" << p._x << ", " << p._y << ")";
	return out;
}

float CPoint::CalcDistanceTo(const CPoint* other) {
	float dx = _x - other->_x;
	float dy = _y - other->_y;
	return sqrt(dx * dx + dy * dy);
}

void CPoint::addressOfThis() {
	std::cout << std::hex << this << std::endl;
}