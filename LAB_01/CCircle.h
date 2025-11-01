#ifndef _CCIRCLE_H
#define _CCIRCLE_H

#include "CPoint.h"

class CCircle {
private:
	CPoint _center;
	float _radius;
public:
	const CPoint& center() const;
	const float& radius() const;
	void setCenter(const CPoint& newCenter);
	void setRadius(const float& newRadius);
public:
	CCircle();
	CCircle(const CPoint&, const float&);
	~CCircle();
};

#endif
