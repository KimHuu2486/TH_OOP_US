#ifndef _CLINE_H
#define _CLINE_H

#include "CPoint.h"

class CLine {
private:
	CPoint _start;
	CPoint _end;
public:
	const CPoint& start() const;
	const CPoint& end() const;
	void setStart(const CPoint& value);
	void setEnd(const CPoint& value);
public:
	CLine();
	CLine(const CPoint&, const CPoint&);
	~CLine();
};

#endif 