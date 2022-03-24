#include "MyClass.h"
#include <sstream>

MyClass::MyClass(int x)
{
	this->x = x;
	*this->p = x;
}

MyClass::MyClass(int x, int p)
{
	this->x = x;
	*this->p = p;
}

void MyClass::twoTimes()
{
	x *= 2;
}

std::string MyClass::toString()
{
	std::ostringstream ostr;

	ostr << x; 

	return ostr.str();
}