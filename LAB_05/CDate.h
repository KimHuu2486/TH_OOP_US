#pragma once

#include <iostream>
#include <string>
#include <sstream>

class CDate {
private:
	int _day;
	int _month;
	int _year;
public:
	int day() const;
	int month() const;
	int year() const;
	void setDay(const int& day);
	void setMonth(const int& month);
	void setYear(const int& year);
public:
	CDate();
	CDate(const int& day, const int& month, const int& year);
	CDate(const CDate* date);
	~CDate();
public:
	std::string ToString() const;
	friend std::istream& operator>>(std::istream& in, CDate& date);
	friend std::ostream& operator<<(std::ostream& out, const CDate& date);
public:
	static bool checkValid(const int& day, const int& month, const int& year);
	static CDate* Parse(std::string line);
};
