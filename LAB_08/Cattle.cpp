#include "Cattle.h"
#include <random>


Cattle::Cattle() {
	isFemale = Cattle::random(0, 1);
	_milk = 0;
}

// Gia súc sinh ngẫu nhiên từ 1 đến 3 con
int Cattle::giveBirth() {
	if (isFemale) {
		return Cattle::random(1, 3);
	}
	return 0;
}

int Cattle::giveMilk() {
	if (isFemale) {
		int current_milk = 0;
		current_milk = Cattle::random(0, max_milk);
		_milk += current_milk;
		return current_milk;
	}
	return 0;
}

int Cattle::random(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	return dis(gen);
}
