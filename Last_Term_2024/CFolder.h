#pragma once

#include <string>
#include "CItem.h"
#include <vector>

class CFolder: public CItem {
private:
	std::vector<std::unique_ptr<CItem>> m_children;
public:
	CFolder(const std::string& name) : CItem(name) {};

	CFolder(const CFolder& other) : CItem(other) {
		m_children.reserve(other.m_children.size());
		for (const auto& child : other.m_children) {
			m_children.push_back(child->clone());
		}
	}

	void addLeft(const CItem& item) {
		m_children.insert(m_children.begin(), item.clone());
	}

	void addRight(const CItem& item) {
		m_children.push_back(item.clone());
	}

	std::unique_ptr<CItem> clone() const override {
		return std::make_unique<CFolder>(*this);
	}

	int size() const override {
		int total = 0;
		for (int i = 0; i < m_children.size(); i++) {
			total += m_children[i]->size();
		}
		return total;
	}
};