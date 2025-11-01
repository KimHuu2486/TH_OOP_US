#include "CPoint.h"

const float CPoint::X() const {
	return _x;
}

const float CPoint::Y() const {
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

	CPoint::InstanceCount++;
}

CPoint::CPoint(const float& x, const float& y) {
	this->_x = x;
	this->_y = y;

	CPoint::InstanceCount++;
}

CPoint::CPoint(const CPoint& src) {
	this->_x = src._x;
	this->_y = src._y;

	CPoint::InstanceCount++;
}

CPoint::~CPoint() {
	this->_x = 0;
	this->_y = 0;
	CPoint::InstanceCount--;
}

std::ostream& operator<<(std::ostream& out, const CPoint& p) {
	out << "(" << p._x << ", " << p._y << ")";
	return out;
}

float CPoint::CalcDistanceTo(const CPoint* other) const {
	float dx = _x - other->_x;
	float dy = _y - other->_y;
	return sqrt(dx * dx + dy * dy);
}

bool CPoint::isEqual(const CPoint* p1, const CPoint* p2) {
	return (fabs(p1->_x - p2->X()) < epsilon) && fabs((p1->_y - p2->Y()) < epsilon);
}

float CPoint::CalcDistance(const CPoint* a, const CPoint* b) {
	return a->CalcDistanceTo(b);
}