#pragma once

#include <iostream>
#include <math.h>

const float epsilon = 1e-6;

class CPoint {
public:
	static int InstanceCount;
private:
	float _x;
	float _y;
public:
	const float X() const;
	const float Y() const;
	void setX(const float& value);
	void setY(const float& value);
public:
	CPoint();
	CPoint(const float&, const float&);
	CPoint(const CPoint&);
	~CPoint();
	friend std::ostream& operator<<(std::ostream& out, const CPoint& p);
public:
	float CalcDistanceTo(const CPoint* other) const;
public:
	static bool isEqual(const CPoint* p1, const CPoint* p2);
	static float CalcDistance(const CPoint* a, const CPoint* b);
};