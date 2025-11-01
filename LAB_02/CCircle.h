#ifndef _CCIRCLE_H
#define _CCIRCLE_H

#include "CPoint.h"

class CCircle {
public:
	const float PI = 3.14;
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
	~CCircle();
public:
	float Diameter();
	float Perimeter();
	float Area();
};

#endif
