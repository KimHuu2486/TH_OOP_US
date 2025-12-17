#include "Cow.h"

Cow::Cow() : Cattle() {
	_kind = 0;
	max_milk = 20;
}

void Cow::sound() {
	std::cout << "Cow!!!" << std::endl;
}
