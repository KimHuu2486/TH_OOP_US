#pragma once

#include "CPoint.h"

class CRectangle {
public:
	static int InstanceCountRectangle;
private:
	CPoint* _topLeft;
	CPoint* _bottomRight;
public:
	const CPoint* topLeft() const;
	const CPoint* bottomRight() const;
	void setTopLeft(const CPoint* value);
	void setBottomRight(const CPoint* value);
public:
	CRectangle();
	CRectangle(const CPoint*, const CPoint*);
	CRectangle(const CRectangle&);
	~CRectangle();
public:
	float Perimeter();
	float Area();
};