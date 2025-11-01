#include "CLine.h"
#include "CPoint.h"

const CPoint& CLine::start() const {
	return _start;
}

const CPoint& CLine::end() const {
	return _end;
}

void CLine::setStart(const CPoint& value) {
	if (!_end.isEqual(value)) {
		_start = value;
	}
}

void CLine::setEnd(const CPoint& value) {
	if (!_start.isEqual(value)) {
		_end = value;
	}
}

CLine::CLine() {
	this->_start = CPoint(0, 0);
	this->_end = CPoint(1, 1);
}

CLine::CLine(const CPoint& start, const CPoint& end) {
	if (!start.isEqual(end)) {
		this->_start = start;
		this->_end = end;
	}
}

CLine::~CLine() {

}