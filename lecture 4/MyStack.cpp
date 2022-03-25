#include "Stack.h"
#include <iostream>

MyStack::MyStack()
{
	top = NULL;
	
}

MyStack::~MyStack()
{
	if (top != NULL)
	{
		Block* next;
		next = top->next;
		while (next != NULL)
		{				
			delete top;
			top = next;
			next = next->next;
		}	
		delete top;
	}
}

bool MyStack::is_empty()
{
	if (top == NULL) 
	{
		return true;
	}
	else {
		return false;
	}
}

void MyStack::push(int x)
{
	Block* new_top = new Block();
	new_top->number = x;
	new_top->next = top;
	top = new_top;
}

int MyStack::pop()
{
	int top_number = top->number;
	Block new_top = *top->next;
	*top = new_top;
	return top_number;
}

void MyStack::print()
{
	if (top != NULL)
	{
		Block i = *top;
		std::cout << i.number << std::endl;
		while (i.next != NULL) {
			i = *i.next;
			std::cout << i.number << std::endl;
		}
		std::cout << "END" << std::endl;
	}
	else {
		std::cout << "stack empty nothing to see here." << std::endl;
	}
}

int MyStack::size()
{
	int counter = 0;
	if (top != NULL) {
		Block i = *top;
		counter++;
		while (i.next != NULL) {
			i = *i.next;
			counter++;
		}
		return counter;
	}
	else {
		return 0;
	}

}

int MyStack::sum()
{
	int sum = 0;
	if (top != NULL)
	{
		Block i = *top;
		sum += i.number;
		while (i.next != NULL) {
			i = *i.next;
			sum += i.number;
		}
		return sum;
	}
	else {
		return sum;
	}

}