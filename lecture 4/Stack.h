#pragma once
struct Block {
	int number;
	Block* next;
};

class MyStack 
{
private:
	Block* top; 

public:
	MyStack();
	~MyStack();
	bool is_empty();
	void push(int);
	int pop();
	void print();
	int size();
	int sum();

};