#ifndef _CDIEM_H
#define _CDIEM_H

#include <iostream>
#include <math.h>

const float epsilon = 1e-6;

class CPoint {
private:
	float _x;
	float _y;
public:
	float X() const;
	float Y() const;
	void setX(const float& value);
	void setY(const float& value);
public:
	CPoint();
	CPoint(const float&, const float&);
	~CPoint();
	bool isEqual(const CPoint& p2) const;
	friend std::ostream& operator<<(std::ostream& out, const CPoint& p);
};

#endif
