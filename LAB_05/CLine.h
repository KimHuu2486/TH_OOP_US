#pragma once

#include "CPoint.h"
#include "Tokenizer.h"

class CLine {
public:
	static int InstanceCountLine;
private:
	CPoint* _start;
	CPoint* _end;
	float _length;
public:
	const CPoint* start() const;
	const CPoint* end() const;
	const float length() const;
	void setStart(const CPoint* value);
	void setEnd(const CPoint* value);
public:
	CLine();
	CLine(const CPoint*, const CPoint*);
	CLine(const CLine&);
	~CLine();
public:
	void updateLength();
	std::string ToString() const;
	friend std::istream& operator>>(std::istream& in, CLine& l);
	friend std::ostream& operator<<(std::ostream& out, const CLine& l);
public:
	static CLine* Parse(std::string line);
};