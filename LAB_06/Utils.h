#pragma once

class Utils {
public:
	static unsigned Gcd(unsigned a, unsigned b) {
		if (b != 0) {
			return Gcd(b, a % b);
		}
		else {
			return a;
		}
	}
};
