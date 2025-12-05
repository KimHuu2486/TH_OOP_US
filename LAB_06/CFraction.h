#pragma once
#pragma

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Tokenizer.h"
#include "Utils.h"

class CFraction {
private:
	static std::string SEPERATOR;
private:
	int _num;
	int _den;
public:
	const int& num() const;
	const int& den() const;
	void setNum(const int& num);
	void setDen(const int& den);
public:
	CFraction();
	CFraction(const int&, const int&);
	CFraction(const CFraction&);
	CFraction& operator=(const CFraction& other);
	~CFraction();
public:
	std::string ToString() const;
	friend std::istream& operator>>(std::istream& in, CFraction& f);
	friend std::ostream& operator<<(std::ostream& out, const CFraction& f);
public:
	static CFraction* Parse(std::string line);
public:
	CFraction operator+(const CFraction& other);
	CFraction operator-(const CFraction& other);
	CFraction operator*(const CFraction& other);
	CFraction operator/(const CFraction& other);
	CFraction& operator++();
	CFraction operator++(int);
	CFraction& operator--();
	CFraction operator--(int);
};