#pragma once

#include <memory>
#include "CNode.h"

class CNumber : public CNode {
private:
	double m_num;
public:
	CNumber(const double& num) : CNode(), m_num(num) {};
	double calculate() const {
		return m_num;
	}
	std::unique_ptr<CNode> clone() const override{
		return std::make_unique<CNumber>(*this);
	}
};