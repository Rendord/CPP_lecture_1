#include <iostream>
#include "MyClass.h"
#include "myinheritedclass.h"
#include "superclass.h"





int main() {
	MyInheritedClass* c = new MyInheritedClass();
	c->doIt();
	SuperClass* sc = new SuperClass();
	sc->doIt();
	SuperClass* ic = new MyInheritedClass();
	ic->doIt();

}