#pragma once

#include "CPoint.h"
#include "Tokenizer.h"

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
public:
	std::string ToString() const;
	friend std::istream& operator>>(std::istream& in, CRectangle& r);
	friend std::ostream& operator<<(std::ostream& out, const CRectangle& r);
public:
	static CRectangle* Parse(std::string line);
};