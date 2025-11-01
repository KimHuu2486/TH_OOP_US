#ifndef _CRECTANGLE_H
#define _CRECTANGLE_H

#include "CPoint.h"

class CRectangle {
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
	~CRectangle();
public:
	float Perimeter();
	float Area();
};

#endif 