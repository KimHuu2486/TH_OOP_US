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
	if (_topLeft != nullptr) {
		delete _topLeft;
	}
	if (_bottomRight != nullptr) {
		delete _bottomRight;
	}

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

std::string CRectangle::ToString() const {
	std::stringstream writer;
	writer << _topLeft->ToString() << " & " << _bottomRight->ToString();
	return writer.str();
}

std::istream& operator>>(std::istream& in, CRectangle& r) {
	while (true) {
		std::cout << "Moi thay nhap diem trai tren: \n";
		in >> *r._topLeft;
		std::cout << "Moi thay nhap diem duoi phai: \n";
		in >> *r._bottomRight;

		if (r._topLeft->X() < r._bottomRight->X() && r._topLeft->Y() > r._bottomRight->Y()) {
			break;
		}

		std::cout << "Diem trai tren va duoi phai khong hop le, moi thay nhap lai!\n";
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const CRectangle& r) {
	out << r.ToString() << std::endl;
	return out;
}