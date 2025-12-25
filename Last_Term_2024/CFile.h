#pragma once

#include <string>
#include "CItem.h"

class CFile : public CItem {
private:
	int m_size;
public:
	CFile(const std::string& name, int size = 0) : CItem(name), m_size(size) {};
	
	CFile(const CFile& other) : CItem(other), m_size(other.m_size) {};
	
	std::unique_ptr<CItem> clone() const override {
		return std::make_unique<CFile>(*this);
	}

	int size() const override {
		return m_size;
	}
};