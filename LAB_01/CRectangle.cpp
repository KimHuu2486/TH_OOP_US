#include "CRectangle.h"

const CPoint& CRectangle::topLeft() const {
	return _topLeft;
}

const CPoint& CRectangle::bottomRight() const {
	return _bottomRight;
}

void CRectangle::setTopLeft(const CPoint& value) {
	if (value.X() < _bottomRight.X() && value.Y() > _bottomRight.Y()) {
		_topLeft = value;
	}
}

void CRectangle::setBottomRight(const CPoint& value) {
	if (_topLeft.X() < value.X() && _topLeft.Y() > value.Y()) {
		_bottomRight = value;
	}
}

CRectangle::CRectangle() {
	_topLeft = CPoint(0, 1);
	_bottomRight = CPoint(1, 0);
}

CRectangle::CRectangle(const CPoint& TL, const CPoint& BR) {
	if (TL.X() < BR.X() && TL.Y() > BR.Y()) {
		_topLeft = TL;
		_bottomRight = BR;
	}
	else {
		_topLeft = CPoint(0, 1);
		_bottomRight = CPoint(1, 0);
	}
}

CRectangle::~CRectangle() {}