#include "CLine.h"
#include "CPoint.h"

const CPoint* CLine::start() const {
	return _start;
}

const CPoint* CLine::end() const {
	return _end;
}

const float CLine::length() const {
	return _length;
}

void CLine::setStart(const CPoint* value) {
	if (value == nullptr) return;
	if (!CPoint::isEqual(value, _end)) {
		*_start = *value;
		this->updateLength();
	}
}

void CLine::setEnd(const CPoint* value) {
	if (value == nullptr) return;
	if (!CPoint::isEqual(_start, value)) {
		*_end = *value;
		this->updateLength();
	}
}

CLine::CLine() {
	this->_start = new CPoint(0, 0);
	this->_end = new CPoint(1, 1);
	this->updateLength();

	InstanceCountLine++;
}

CLine::CLine(const CPoint* start, const CPoint* end) {
	if (!CPoint::isEqual(start, end)) {
		this->_start = new CPoint(*start);
		this->_end = new CPoint(*end);
	}
	else {
		this->_start = new CPoint(0, 0);
		this->_end = new CPoint(1, 1);
	}

	this->updateLength();
	InstanceCountLine++;
}

CLine::CLine(const CLine& src) {
	this->_start = new CPoint(*src._start);
	this->_end = new CPoint(*src._end);

	this->updateLength();
	InstanceCountLine++;
}

CLine::~CLine() {
	delete _start;
	delete _end;
	_start = nullptr;
	_end = nullptr;
	_length = 0;

	InstanceCountLine--;
}

void CLine::updateLength() {
	_length = CPoint::CalcDistance(_start, _end);
}