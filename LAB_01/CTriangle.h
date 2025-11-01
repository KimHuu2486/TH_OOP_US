#ifndef _CTRIANGLE_H
#define _CTRIANGLE_H

#include "CPoint.h"
#include "math.h"

class CTriangle {
private:
	CPoint _a;
	CPoint _b;
	CPoint _c;
public:
	const CPoint& A() const;
	const CPoint& B() const;
	const CPoint& C() const;
	void setA(const CPoint& A);
	void setB(const CPoint& B);
	void setC(const CPoint& C);
public:
	CTriangle();
	CTriangle(const CPoint&, const CPoint&, const CPoint&);
	~CTriangle();
	bool isLine(const CPoint& a, const CPoint& b, const CPoint& c);
};

#endif
