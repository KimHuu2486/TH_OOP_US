#pragma once

#include <memory>
#include "CNode.h"
#include <string>
#include <limits>

class COperator: public CNode {
private:
	std::string m_ope;
	std::unique_ptr<CNode> m_left;
	std::unique_ptr<CNode> m_right;
public:
	COperator(const std::string& name) : CNode(), m_ope(name), m_left(nullptr), m_right(nullptr) {};
	COperator(const COperator& other) : CNode(other), m_ope(other.m_ope) {
		if (other.m_left) m_left = other.m_left->clone();
		if (other.m_right) m_right = other.m_right->clone();
	}
	double calculate() const override {
		double left = 0.0f, right = 0.0f;
		if (m_left != nullptr) {
			left = m_left->calculate();
		}
		if (m_right != nullptr) {
			right = m_right->calculate();
		}
		
		if (m_ope == "+") {
			return left + right;
		}
		else if (m_ope == "-") {
			return left - right;
		}
		else if (m_ope == "*") {
			return left * right;
		}
		else if (m_ope == "/") {
			if (right == 0) {
				return std::numeric_limits<double>::infinity(); // trường hợp chia cho 0
			}
			else {
				return left / right;
			}
		}
		return std::numeric_limits<double>::infinity();
	}
	std::unique_ptr<CNode> clone() const override {
		return std::make_unique<COperator>(*this);
	}
	void addLeft(const CNode& item) {
		m_left = item.clone();
	}
	void addRight(const CNode& item) {
		m_right = item.clone();
	}
};