#ifndef _CFRACTION_H
#define _CFRACTION_H

#include <iostream>
#include <string>
#include <sstream>

class CFraction {
private:
	int _num;
	int _den;
public:
	static int InstanceCountFraction;
public:
	const int& num() const;
	const int& den() const;
	void setNum(const int& num);
	void setDen(const int& den);
public:
	CFraction();
	CFraction(const int&, const int&);
	CFraction(const CFraction&);
	~CFraction();
public:
	std::string ToString() const;
	friend std::istream& operator>>(std::istream& in, CFraction& f);
	friend std::ostream& operator<<(std::ostream& out, const CFraction& f);
};


#endif