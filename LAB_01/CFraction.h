#ifndef _CFRACTION_H
#define _CFRACTION_H

class CFraction {
private:
	int _num;
	int _den;
public:
	const int& num() const;
	const int& den() const;
	void setNum(const int& num);
	void setDen(const int& den);
public:
	CFraction();
	CFraction(const int&, const int&);
	~CFraction();
};


#endif
