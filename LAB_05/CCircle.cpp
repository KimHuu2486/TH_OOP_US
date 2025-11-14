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
	_radius = 1;

	InstanceCountCircle++;
}

CCircle::CCircle(const CPoint* c, const float& r) {
	_center = new CPoint(*c);
	_radius = (r > 0 ? r : 1);

	InstanceCountCircle++;
}

CCircle::CCircle(const CCircle& cir) {
	this->_center = new CPoint(*cir._center);
	this->_radius = cir._radius;

	InstanceCountCircle++;
}

CCircle::~CCircle() {
	if (_center != nullptr) {
		delete _center;
	}
	_center = nullptr;
	_radius = 0;

	InstanceCountCircle--;
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

std::string CCircle::ToString() const {
	std::stringstream writer;
	writer << "Tam: " << _center->ToString() << " & ban kinh r = " << _radius;
	return writer.str();
}

std::istream& operator>>(std::istream& in, CCircle& cir) {
	while (true) {
		std::cout << "Moi thay nhap tam duong tron: \n";
		in >> *cir._center;
		std::cout << "Moi thay nhap ban kinh duong tron: \n";
		in >> cir._radius;

		if (cir._radius > 0) {
			break;
		}

		std::cout << "Duong tron khong hop le, moi thay nhap lai!\n";
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const CCircle& cir) {
	out << cir.ToString() << std::endl;
	return out;
}

CCircle* CCircle::Parse(std::string line) {
	std::string seperator = "), ";
	std::vector<std::string> argu = Tokenizer::Parse(line, seperator);

	CPoint* center = CPoint::Parse(argu[0]);
	float radius = std::stof(argu[1]);

	CCircle* temp = new CCircle(center, radius);

	delete center;

	return temp;
}