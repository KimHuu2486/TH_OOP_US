#include "CStudent.h"

const std::string& CStudent::firstName() const {
	return _firstName;
}

const std::string& CStudent::middleName() const {
	return _middleName;
}

const std::string& CStudent::lastName() const {
	return _lastName;
}

void CStudent::setFirstName(const std::string& newFirstName) {
	_firstName = newFirstName;
}

void CStudent::setMiddleName(const std::string& newMiddleName) {
	_middleName = newMiddleName;
}

void CStudent::setLastName(const std::string& newLastName) {
	_lastName = newLastName;
}

CStudent::CStudent() {
	_firstName = "A";
	_middleName = "Van";
	_lastName = "Nguyen";
}

CStudent::CStudent(const std::string& firstName, const std::string& middleName, const std::string& lastName) {
	_firstName = firstName;
	_middleName = middleName;
	_lastName = lastName;
}

CStudent::~CStudent() {}

std::ostream& operator<<(std::ostream& out, const CStudent& st) {
	out << st.lastName() << " " << st.middleName() << " " << st.firstName();
	return out;
}