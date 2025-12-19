#include "Cow.h"

#define MAX_MILK 20

Cow::Cow() : Cattle() {
	max_milk = MAX_MILK;
}


std::string Cow::getName() {
	return "Cow";
}

Cattle* Cow::Clone() {
	return new Cow(*this);
}

void Cow::sound() {
	std::cout << "Cow!!!" << std::endl;
}
