#pragma once
#include <string>

class MyClass {

private: 
	int x;
	int* p;

public:
	MyClass(int);
	MyClass(int, int);
	void twoTimes();
	std::string toString();
};