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
	if (_start != nullptr) {
		delete _start;
	}
	if (_end != nullptr) {
		delete _end;
	}
	_start = nullptr;
	_end = nullptr;
	_length = 0;

	InstanceCountLine--;
}

void CLine::updateLength() {
	_length = CPoint::CalcDistance(_start, _end);
}

std::string CLine::ToString() const {
	std::stringstream writer;
	writer << _start->ToString() << " & " << _end->ToString();
	writer << ", do dai = " << _length;
	return writer.str();
}

std::istream& operator>>(std::istream& in, CLine& l) {
	while (true) {
		std::cout << "Moi thay nhap diem bat dau: \n";
		in >> *l._start;
		std::cout << "Moi thay nhap diem ket thuc: \n";
		in >> *l._end;

		if (l._start->X() != l._end->X() || l._start->Y() != l._end->Y()) {
			break;
		}

		std::cout << "Diem bat dau va ket thuc trung nhau, moi thay nhap lai!\n";
	}
	l.updateLength();
	return in;
}

std::ostream& operator<<(std::ostream& out, const CLine& l) {
	out << l.ToString() << std::endl;
	return out;
}

CLine* CLine::Parse(std::string line) {
	std::string seperator = "), ";
	std::vector<std::string> points = Tokenizer::Parse(line, seperator);

	CPoint* start = CPoint::Parse(points[0]);
	CPoint* end = CPoint::Parse(points[1]);

	CLine* temp = new CLine(start, end);

	delete start, end;

	return temp;
}