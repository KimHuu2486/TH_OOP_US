#include "Sheep.h"

Sheep::Sheep() : Cattle() {
	_kind = 1;
	max_milk = 5;
}

void Sheep::sound() {
	std::cout << "Sheep!!!" << std::endl;
}
