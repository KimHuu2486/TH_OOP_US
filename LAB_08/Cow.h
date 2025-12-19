#pragma once

#include "Cattle.h"
#include <string>

class Cow : public Cattle {
public:
	Cow();
	void sound();
	Cattle* Clone() override;
	std::string getName();
	~Cow() = default;
};