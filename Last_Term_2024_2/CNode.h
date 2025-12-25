#pragma once

#include <memory>

class CNode {
public:
	virtual ~CNode() = default;
	virtual double calculate() const = 0;
	virtual std::unique_ptr<CNode> clone() const = 0;
};