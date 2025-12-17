#include "Goat.h"

Goat::Goat() : Cattle() {
	_kind = 2;
	max_milk = 10;
}

void Goat::sound() {
	std::cout << "Goat!!!" << std::endl;
}
