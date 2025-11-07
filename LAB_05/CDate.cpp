#include "CDate.h"

int CDate::day() const {
	return _day;
}

int CDate::month() const {
	return _month;
}

int CDate::year() const {
	return _year;
}

void CDate::setDay(const int& day) {
	if (checkValid(day, _month, _year)) {
		_day = day;
	}
}

void CDate::setMonth(const int& month) {
	if (checkValid(_day, month, _year)) {
		_month = month;
	}
}

void CDate::setYear(const int& year) {
	if (checkValid(_day, _month, year)) {
		_year = year;
	}
}

CDate::CDate()
	: _day(1), _month(1), _year(2025) { }

CDate::CDate(const int& day, const int& month, const int& year)
	: CDate() {
	if (checkValid(day, month, year)) {
		_day = day;
		_month = month;
		_year = year;
	}
}

CDate::CDate(const CDate* date)
	: CDate() {
	_day = date->_day;
	_month = date->_month;
	_year = date->_year;
}

CDate::~CDate() {}

std::string CDate::ToString() const {
	std::stringstream ss;
	ss << _day << "/" << _month << "/" << _year;
	return ss.str();
}

std::istream& operator>>(std::istream& in, CDate& date) {
	while (true) {
		std::cout << "Moi thay nhap ngay, thang, nam: ";
		in >> date._day >> date._month >> date._year;

		if (CDate::checkValid(date._day, date._month, date._year)) {
			break;
		}
		
		std::cout << "Ngay, thang, nam khong hop le, moi thay nhap lai!" << std::endl;
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const CDate& date) {
	out << date.ToString();
	return out;
}

bool CDate::checkValid(const int& day, const int& month, const int& year) {
	if (month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (leap && month == 2) {
		return day <= 29;
	}

	return day <= daysInMonth[month];
}

CDate* CDate::Parse(std::string line) {
	std::stringstream ss(line);
	int day, month, year;
	char temp;
	ss >> day >> temp >> month >> temp >> year;
	return new CDate(day, month, year);
}