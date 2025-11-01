#include "CCircle.h"

const CPoint& CCircle::center() const {
	return _center;
}

const float& CCircle::radius() const {
	return _radius;
}

void CCircle::setCenter(const CPoint& newCenter) {
	_center = newCenter;
}

void CCircle::setRadius(const float& newRadius) {
	if (newRadius > 0) {
		_radius = newRadius;
	}
}

CCircle::CCircle() {
	_center = CPoint(0, 0);
	_radius = 1;
}

CCircle::CCircle(const CPoint& c, const float& r) {
	_center = c;
	if (r > 0) {
		_radius = r;
	}
	else {
		_radius = 1;
	}
}

CCircle::~CCircle() {}