#pragma once

#include "Cattle.h"
#include <string>

class Sheep : public Cattle {
public:
	Sheep();
	void sound();
	Cattle* Clone() override;
	std::string getName();
	~Sheep() = default;
};
