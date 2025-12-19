#include "Goat.h"
#include <string>

#define MAX_MILK 10

Goat::Goat() : Cattle() {
	max_milk = MAX_MILK;
}

std::string Goat::getName() {
	return "Goat";
}

Cattle* Goat::Clone() {
	return new Goat(*this);
}
	
void Goat::sound() {
	std::cout << "Goat!!!" << std::endl;
}
