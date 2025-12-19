#include "Sheep.h"

#define MAX_MILK 5


Sheep::Sheep() : Cattle() {
	max_milk = MAX_MILK;
}

std::string Sheep::getName() {
	return "Sheep";
}

Cattle* Sheep::Clone() {
	return new Sheep(*this);
}

void Sheep::sound() {
	std::cout << "Sheep!!!" << std::endl;
}
