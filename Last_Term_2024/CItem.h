#pragma once

#include <string>
#include <memory>

class CItem {
protected:
	std::string m_name;
public:
	CItem(const std::string& name) : m_name(name) {};
	CItem(const CItem& other) : m_name(other.m_name) {};
	virtual ~CItem() = default;
	virtual int size() const = 0;
	virtual std::unique_ptr<CItem> clone() const = 0;
};