#pragma once

#include "Cattle.h"
#include <string>

class Goat : public Cattle {
public:
	Goat();
	void sound();
	std::string getName();
	Cattle* Clone() override;
	~Goat() = default;
};
