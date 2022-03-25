#include "MyClass.h"
#include <sstream>
#include <iostream>

MyClass::MyClass()
{
	this->x = 0;
	p = NULL;
}

MyClass::MyClass(int x, int p)
{
	this->x = x;
	*this->p = p;
}

MyClass::~MyClass() {
	if(p != NULL)
		delete p;
}

void MyClass::twoTimes()
{
	x *= 2;
}

void MyClass::setX(int x)
{
	this->x = x;
}

void MyClass::setP(int p)
{
	if (this->p == NULL) 
	{
		this->p = new int();
		*this->p = p;
	}
	*this->p = p;
}

void MyClass::removeP()
{
	if (p != NULL) { 
		delete p;
		p = NULL;
	}
}

void MyClass::print() {
	std::cout << x << " " << p << std::endl;
}

std::string MyClass::toString()
{
	std::ostringstream ostr;

	ostr << x; 

	return ostr.str();
}