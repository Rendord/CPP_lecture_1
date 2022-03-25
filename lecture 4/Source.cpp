#include <iostream>
#include "MyClass.h"
#include "myinheritedclass.h"
#include "superclass.h"
#include "Stack.h"





int main() {
	MyInheritedClass* c = new MyInheritedClass();
	c->doIt();
	SuperClass* sc = new SuperClass();
	sc->doIt();
	SuperClass* ic = new MyInheritedClass();
	ic->doIt();

	MyClass klasje = MyClass();
	klasje.print();
	klasje.setX(4);
	klasje.print();
	klasje.setP(12);
	klasje.print();
	klasje.removeP();
	klasje.print();

	MyStack stack = MyStack();

	stack.print();
	std::cout << "boolean result = " << stack.is_empty() << std::endl;
	std::cout << stack.size() << std::endl;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.print();
	std::cout << "boolean result = " << stack.is_empty() << std::endl;
	std::cout << stack.size() << std::endl;
	std::cout << "pop stack:" << stack.pop() << std::endl;
	std::cout << "pop stack:" << stack.pop() << std::endl;
	stack.print();

	std::cout << "sum of stack: " << stack.sum() << std::endl;
	


}