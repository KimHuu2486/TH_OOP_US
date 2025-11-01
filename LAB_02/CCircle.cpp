#include "CCircle.h"

const CPoint* CCircle::center() const {
	return _center;
}

const float& CCircle::radius() const {
	return _radius;
}

void CCircle::setCenter(const CPoint* newCenter) {
	*_center = *newCenter;
}

void CCircle::setRadius(const float& newRadius) {
	if (newRadius > 0) {
		_radius = newRadius;
	}
}

CCircle::CCircle() {
	_center = new CPoint;
	_radius = 0;
}

CCircle::CCircle(const CPoint* c, const float& r)
	: CCircle()
{
	if (r > 0) {
		_radius = r;
	}
}

CCircle::~CCircle() {
	if (_center != nullptr) {
		delete _center;
		_center = nullptr;
		_radius = 0;
	}
}

float CCircle::Diameter() {
	return 2 * _radius;
}

float CCircle::Perimeter() {
	return 2 * _radius * PI;
}

float CCircle::Area() {
	return _radius * _radius * PI;
}