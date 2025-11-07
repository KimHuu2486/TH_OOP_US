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

float CPoint::CalcDistanceTo(const CPoint* other) const {
	if (other == nullptr) return 0.0f;
	float dx = _x - other->_x;
	float dy = _y - other->_y;
	return sqrt(dx * dx + dy * dy);
}

std::string CPoint::ToString() const {
	std::stringstream writer;
	writer << "(" << _x << ", " << _y << ")";
	return writer.str();
}

bool CPoint::isEqual(const CPoint* p1, const CPoint* p2) {
	return (fabs(p1->_x - p2->X()) < epsilon) && (fabs(p1->_y - p2->Y()) < epsilon);
}

float CPoint::CalcDistance(const CPoint* a, const CPoint* b) {
	return a->CalcDistanceTo(b);
}

std::istream& operator>>(std::istream& in, CPoint& p) {
	std::cout << "Moi thay nhap x: ";
	in >> p._x;
	std::cout << "Moi thay nhap y: ";
	in >> p._y;
	return in;

}

std::ostream& operator<<(std::ostream& out, const CPoint& p) {
	out << p.ToString() << std::endl;
	return out;
}

CPoint* CPoint::Parse(std::string line) {
	std::stringstream ss(line);
	float _x, _y;
	char temp;

	ss >> temp >> _x >> temp >> _y;

	return new CPoint(_x, _y);
}