#ifndef _CTRIANGLE_H
#define _CTRIANGLE_H

#include "CPoint.h"

class CTriangle {
private:
	CPoint* _a;
	CPoint* _b;
	CPoint* _c;
public:
	CPoint* A() const;
	CPoint* B() const;
	CPoint* C() const;
	void setA(const CPoint* A);
	void setB(const CPoint* B);
	void setC(const CPoint* C);
public:
	CTriangle();
	CTriangle(const CPoint*, const CPoint*, const CPoint*);
	~CTriangle();
	bool isLine(const CPoint* a, const CPoint* b, const CPoint* c);
public:
	float perimeter();
	float area();
};

#endif
