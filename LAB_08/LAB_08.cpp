#include "Cattle.h"
#include "Cow.h"
#include "Sheep.h"
#include "Goat.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Farm {
private:
	std::vector<Cattle*>cattle;
public:
	Farm(int cow = 0, int sheep = 0, int goat = 0);

	void soundFarm();

	std::map<std::string, int> giveBirthFarm();
	void infoBirthFarm();

	std::map<std::string, int> giveMilkFarm();
	void infoMilkFarm();

	~Farm();
};

int main() {
	int n1, n2, n3;
	std::cout << "Moi thay nhap so bo, cuu, de" << std::endl;
	std::cin >> n1 >> n2 >> n3;
	Farm f1(n1, n2, n3);
	f1.soundFarm();

	f1.infoBirthFarm();

	f1.infoMilkFarm();

	return 0;
}

Farm::Farm(int cow, int sheep, int goat) {
	for (int i = 0; i < cow; i++) {
		cattle.push_back(new Cow());
	}
	for (int i = 0; i < sheep; i++) {
		cattle.push_back(new Sheep());
	}
	for (int i = 0; i < goat; i++) {
		cattle.push_back(new Goat());
	}
}

void Farm::soundFarm() {
	for (int i = 0; i < cattle.size(); i++) {
		cattle[i]->sound();
	}
}

std::map<std::string, int> Farm::giveBirthFarm() {
	// map để lưu số con sinh ra của từng loại
	std::map<std::string, int> birthCount;

	int n = cattle.size();
	for (int i = 0; i < n; i++) {
		int children = cattle[i]->giveBirth();
		for (int j = 0; j < children; j++) {
			Cattle* baby = cattle[i]->Clone();
			cattle.push_back(baby);
			birthCount[cattle[i]->getName()]++;
		}
	}

	return birthCount;
}

void Farm::infoBirthFarm() {
	std::map<std::string, int> birthInfo = giveBirthFarm();
	for (const auto& pair : birthInfo) {
		std::cout << pair.first << " sinh ra duoc " << pair.second << " con." << std::endl;
	}
}

std::map<std::string, int> Farm::giveMilkFarm() {
	// map để lưu số lượng sữa lấy được từ từng loại ở lần thu này
	std::map<std::string, int> milkCount;
	for (int i = 0; i < cattle.size(); i++) {
		int milk = cattle[i]->giveMilk();
		milkCount[cattle[i]->getName()] += milk;
	}
	return milkCount;
}

void Farm::infoMilkFarm() {
	std::map<std::string, int> milkInfo = giveMilkFarm();
	for (const auto& pair : milkInfo) {
		std::cout << "Tong so sua lay duoc tu " << pair.first << " o lan thu hoach nay la: " << pair.second << std::endl;
	}
}

Farm::~Farm() {
	for (int i = 0; i < cattle.size(); i++) {
		if (cattle[i] != nullptr) {
			delete cattle[i];
		}
		cattle[i] = nullptr;
	}
	cattle.clear();
}


