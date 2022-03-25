#pragma once
#include <string>

class MyClass {

private: 
	int x;
	int* p;

public:
	MyClass();
	MyClass(int, int);
	~MyClass(); 
	void twoTimes();
	void setX(int);
	void setP(int);
	void removeP();
	void print();
	std::string toString();
};