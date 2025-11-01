#ifndef _CSTUDENT_H
#define _CSTUDENT_H

#include <string>
#include <iostream>

class CStudent {
private:
	std::string _firstName;
	std::string _middleName;
	std::string _lastName;
public:
	const std::string& firstName() const;
	const std::string& middleName() const;
	const std::string& lastName() const;
	void setFirstName(const std::string& newFirstName);
	void setMiddleName(const std::string& newMiddleName);
	void setLastName(const std::string& newLastName);
public:
	CStudent();
	CStudent(const std::string&, const std::string&, const std::string&);
	~CStudent();
	friend std::ostream& operator<<(std::ostream& out, const CStudent& st);
};

#endif
