#pragma once
#include <iostream>

class Cattle {
protected:
	bool isFemale;
	int _milk; // Lượng sữa đã cho kể từ khi sinh ra
protected:
	int _kind; // 0: Cow, 1: Sheep, 2: Goat
	int max_milk; // Lượng sữa tối đa có thể cho trong một lần vắt
public:
	Cattle();
	void sound();
	int giveBirth();
	int giveMilk();
	int getKind();
public:
	static int random(int min, int max);
};