#pragma once
#include <iostream>
#include <string>

class Cattle {
protected:
	bool isFemale;
	int _milk; // Lượng sữa đã cho kể từ khi sinh ra
protected:
	int max_milk; // Lượng sữa tối đa trong mỗi lần cho
public:
	Cattle();
	virtual std::string getName() = 0;
	virtual void sound() = 0;
	virtual int giveBirth();
	virtual Cattle* Clone() = 0;
	virtual int giveMilk();
	virtual ~Cattle() = default;
public:
	static int random(int min, int max);
};
