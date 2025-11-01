#include "CRectangle.h"

const CPoint* CRectangle::topLeft() const {
	return _topLeft;
}

const CPoint* CRectangle::bottomRight() const {
	return _bottomRight;
}

void CRectangle::setTopLeft(const CPoint* value) {
	if (!value) return;
	if (value->X() < _bottomRight->X() && value->Y() > _bottomRight->Y()) {
		*_topLeft = *value;
	}
}

void CRectangle::setBottomRight(const CPoint* value) {
	if (!value) return;
	if (_topLeft->X() < value->X() && _topLeft->Y() > value->Y()) {
		*_bottomRight = *value;
	}
}

CRectangle::CRectangle() {
	_topLeft = new CPoint(1, 10);
	_bottomRight = new CPoint(10, 1);

	InstanceCountRectangle++;
}

CRectangle::CRectangle(const CPoint* topLeft, const CPoint* bottomRight)
	: CRectangle()
{
	if (topLeft->X() < bottomRight->X() && topLeft->Y() > bottomRight->Y()) {
		*_topLeft = *topLeft;
		*_bottomRight = *bottomRight;
	}
}

CRectangle::CRectangle(const CRectangle& src) {
	this->_topLeft = new CPoint(*src._topLeft);
	this->_bottomRight = new CPoint(*src._bottomRight);

	InstanceCountRectangle++;
}

CRectangle::~CRectangle() {
	delete _topLeft;
	delete _bottomRight;

	_topLeft = nullptr;
	_bottomRight = nullptr;

	InstanceCountRectangle--;
}

float CRectangle::Perimeter() {
	return ((_bottomRight->X() - _topLeft->X()) + (_topLeft->Y() - _bottomRight->Y())) * 2;
}

float CRectangle::Area() {
	return (_bottomRight->X() - _topLeft->X()) * (_topLeft->Y() - _bottomRight->Y());
}