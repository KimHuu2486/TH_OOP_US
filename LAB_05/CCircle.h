#ifndef _CCIRCLE_H
#define _CCIRCLE_H

#include "CPoint.h"
#include "Tokenizer.h"

class CCircle {
public:
	const float PI = 3.14;
	static int InstanceCountCircle;
private:
	CPoint* _center;
	float _radius;
public:
	const CPoint* center() const;
	const float& radius() const;
	void setCenter(const CPoint* newCenter);
	void setRadius(const float& newRadius);
public:
	CCircle();
	CCircle(const CPoint*, const float&);
	CCircle(const CCircle&);
	~CCircle();
public:
	float Diameter();
	float Perimeter();
	float Area();
public:
	std::string ToString() const;
	friend std::istream& operator>>(std::istream& in, CCircle& cir);
	friend std::ostream& operator<<(std::ostream& out, const CCircle& cir);
public:
	static CCircle* Parse(std::string line);
};

#endif